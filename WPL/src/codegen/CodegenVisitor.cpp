#include "CodegenVisitor.h"

#include <llvm/IR/BasicBlock.h>

#include <any>
#include <string>

using namespace llvm;

void trace(std::string message, Value *v = nullptr) {
#ifndef _TRACE_
    std::cout << message;
    if (v != nullptr) {
        std::cout.flush();
        v->print(llvm::outs());
    }
    std::cout << std::endl;
#endif
}

// std::any CodegenVisitor::visitCompilationUnit(
//     WPLParser::CompilationUnitContext *ctx) {
//     // 1 Declare external functions.
//     auto printf_prototype = FunctionType::get(i8p, true);
//     auto printf_fn = Function::Create(
//         printf_prototype, Function::ExternalLinkage, "printf", module);
//     FunctionCallee printExpr(printf_prototype, printf_fn);
//
//     // 2. Define the main program.
//     FunctionType *mainFuncType =
//         FunctionType::get(Int32Ty, {Int32Ty, Int8PtrPtrTy}, false);
//     Function *mainFunc = Function::Create(
//         mainFuncType, GlobalValue::ExternalLinkage, "program", module);
//
//     // 3. Create a basic block and attach it to the builder
//     BasicBlock *bBlock =
//         BasicBlock::Create(module->getContext(), "entry", mainFunc);
//     builder->SetInsertPoint(bBlock);
//
//     // 4. Generate the code for all of the expression in the block.
//     for (auto cc : ctx->cuComponent()) {
//         std::any_cast<Value *>(cc->accept(this));
//     }
//
//     // 5. Generate code module trailer.
//     builder->CreateRet(Int32Zero);
//     return nullptr;
// }

std::any CodegenVisitor::visitConstant(WPLParser::ConstantContext *ctx) {
    Value *v;
    if (ctx->b) {
        if (ctx->b->getText() == "true") {
            v = builder->getInt32(1);
        } else {
            v = builder->getInt32(0);
        }
    } else if (ctx->i) {
        v = builder->getInt32(std::stoi(ctx->i->getText()));
    } else {
        StringRef sr = ctx->s->getText();
        v = builder->CreateGlobalStringPtr(sr);
    }
    return v;
}

std::any CodegenVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}

std::any CodegenVisitor::visitUMinusExpr(WPLParser::UMinusExprContext *ctx) {
    Value *exVal = std::any_cast<Value *>(ctx->expr()->accept(this));
    Value *v = builder->CreateNSWSub(builder->getInt32(0), exVal);
    return v;
}

std::any CodegenVisitor::visitNotExpr(WPLParser::NotExprContext *ctx) {
    Value *v = std::any_cast<Value *>(ctx->expr()->accept(this));
    v = builder->CreateZExtOrTrunc(v, CodegenVisitor::Int1Ty);
    v = builder->CreateXor(v, Int32One);
    v = builder->CreateZExtOrTrunc(v, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitBinaryArithExpr(
    WPLParser::BinaryArithExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    if (ctx->PLUS()) {
        v = builder->CreateNSWAdd(lVal, rVal);
    } else if (ctx->MINUS()) {
        v = builder->CreateNSWSub(lVal, rVal);
    } else if (ctx->MUL()) {
        v = builder->CreateNSWMul(lVal, rVal);
    } else {
        v = builder->CreateSDiv(lVal, rVal);
    }
    return v;
}

std::any CodegenVisitor::visitRelExpr(WPLParser::RelExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    Value *v1;
    if (ctx->LESS()) {
        v1 = builder->CreateICmpSLT(lVal, rVal);
    } else if (ctx->LEQ()) {
        v1 = builder->CreateICmpSLE(lVal, rVal);
    } else if (ctx->GTR()) {
        v1 = builder->CreateICmpSGT(lVal, rVal);
    } else {
        v1 = builder->CreateICmpSGE(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    Value *v1;
    if (ctx->EQUAL()) {
        v1 = builder->CreateICmpEQ(lVal, rVal);
    } else {
        v1 = builder->CreateICmpNE(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitAssignment(WPLParser::AssignmentContext *ctx) {
    Value *v = nullptr;
    Value *exVal;
    if (ctx->target) {
        exVal = std::any_cast<Value *>(ctx->e->accept(this));
        Symbol *symbol = props->getBinding(ctx);  // child variable symbol
        if (symbol == nullptr) {
            trace("NULLPTR");
            exit(-1);
        }
        if (false == symbol->defined) {
            // Define the symbol and allocate memory.
            auto type = getLLVMType(symbol->baseType);
            v = builder->CreateAlloca(type, 0, symbol->id);
            symbol->defined = true;
            symbol->val = v;
        } else {
            v = symbol->val;
        }
        builder->CreateStore(exVal, v);
    } else {
        exVal = std::any_cast<Value *>(ctx->arrayIndex()->accept(this));
        Symbol *symbol = props->getBinding(ctx);  // child variable symbol
        if (symbol == nullptr) {
            trace("NULLPTR");
            exit(-1);
        }
        if (false == symbol->defined) {
            // Define the symbol and allocate memory.
            v = builder->CreateAlloca(CodegenVisitor::Int32Ty, 0, symbol->id);
            symbol->defined = true;
            symbol->val = v;
        } else {
            v = symbol->val;
        }
        builder->CreateStore(exVal, v);
    }
    return exVal;
}

std::any CodegenVisitor::visitIDExpr(WPLParser::IDExprContext *ctx) {
    // 1. Get the name of the variable.
    std::string id = ctx->id->getText();
    // 2. Get the binding.
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("NULLPTR");
        exit(-1);
    }
    Value *v = nullptr;
    // We made sure that the variable is defined in the semantic analysis
    // phase
    if (!(symbol->defined)) {
        errors.addCodegenError(ctx->getStart(),
                               "Undefined variable in expression: " + id);
    } else {
        v = builder->CreateLoad(CodegenVisitor::Int32Ty, symbol->val, id);
    }
    return v;
}

// std::any CodegenVisitor::visitScalarDeclaration(
//     WPLParser::ScalarDeclarationContext *ctx) {
//     std::string id = "VAR";
//     if (ctx->t) {
//         id = ctx->t->getText();
//     }
//     Symbol *symbol = props->getBinding(ctx);
//     if (symbol == nullptr) {
//         trace("NULLPTR");
//         exit(-1);
//     }
//     Value *v = nullptr;
//     if (!(symbol->defined)) {
//         errors.addCodegenError(ctx->getStart(),
//                                "Undefined variable in expression: " + id);
//     }
//     for (auto s : ctx->scalars) {
//         auto type = CodegenVisitor::Int32Ty;
//         if (symbol->baseType == STR) {
//             type = CodegenVisitor::Int8PtrPtrTy;
//         } else if (symbol->baseType == BOOL) {
//             type = CodegenVisitor::Int1Ty;
//         }
//         v = builder->CreateLoad(type, symbol->val, id);
//     }
//     return v;
// }

std::any CodegenVisitor::visitScalar(WPLParser::ScalarContext *ctx) {
    std::string id = ctx->id->getText();
    Symbol *symbol = props->getBinding(ctx);
    auto type = getLLVMType(symbol->baseType);
    Value *v = builder->CreateAlloca(type, 0, symbol->id);
    Value *vi = nullptr;
    symbol->defined = true;
    symbol->val = v;
    if (ctx->varInitializer()) {
        symbol->defined = true;
        vi = std::any_cast<Value *>(ctx->varInitializer()->accept(this));
    }
    builder->CreateStore(v, vi);
    return v;
}
