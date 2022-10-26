#include "CodegenVisitor.h"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/GlobalVariable.h>

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

std::any CodegenVisitor::visitVarDeclaration(
    WPLParser::VarDeclarationContext *ctx) {
    if (ctx->scalarDeclaration()) {
        return ctx->scalarDeclaration()->accept(this);
    }
    if (ctx->arrayDeclaration()) {
        return ctx->arrayDeclaration()->accept(this);
    }
    return nullptr;
}

std::any CodegenVisitor::visitScalar(WPLParser::ScalarContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("NULLPTR");
        exit(-1);
    }

    Value *alloca = nullptr;
    if (!(symbol->defined)) {
        auto type = getLLVMType(symbol->baseType);
        if (isGlobal(ctx)) {
            alloca = M->getOrInsertGlobal(symbol->id, type);
        } else {
            alloca = builder->CreateAlloca(type, nullptr, symbol->id);
        }
        symbol->defined = true;
        symbol->val = alloca;
    } else {
        alloca = symbol->val;
    }

    if (ctx->varInitializer()) {
        Value *val =
            std::any_cast<Value *>(ctx->varInitializer()->accept(this));
        if (isGlobal(ctx)) {
            static_cast<GlobalVariable *>(alloca)->setInitializer(
                static_cast<Constant *>(val));
        } else {
            builder->CreateStore(val, alloca);
        }
    }
    return alloca;
}

std::any CodegenVisitor::visitVarInitializer(
    WPLParser::VarInitializerContext *ctx) {
    return ctx->c->accept(this);
}

std::any CodegenVisitor::visitArrayDeclaration(
    WPLParser::ArrayDeclarationContext *ctx) {
    return nullptr;
}

BasicBlock *CodegenVisitor::createBB(std::string twine, Function *parent,
                                     BasicBlock *insertBefore) {
    auto BB = BasicBlock::Create(M->getContext(), twine, parent, insertBefore);
    if (BB == nullptr) {
        trace("Failed to createBB");
        exit(-1);
    }
    return BB;
}

Function *CodegenVisitor::createFunc(FunctionType *ft, std::string twine) {
    return Function::Create(ft, GlobalValue::ExternalLinkage, twine, M);
}

std::any CodegenVisitor::visitFunction(WPLParser::FunctionContext *ctx) {
    auto fn = std::any_cast<Function *>(ctx->funcHeader()->accept(this));
    builder->SetInsertPoint(createBB(ctx->getText(), fn));
    ctx->block()->accept(this);
    return nullptr;
}

std::any CodegenVisitor::visitFuncHeader(WPLParser::FuncHeaderContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("Function symbol is null!");
        exit(-1);
    }
    std::vector<Type *> args;
    if (symbol->params) {
        for (auto param : *(symbol->params)) {
            args.push_back(getLLVMType(param->baseType));
        }
    }
    auto retType = getLLVMType(symbol->baseType);
    auto *ft = FunctionType::get(retType, args, false);
    auto fn = createFunc(ft, symbol->id);
    symbol->defined = true;
    symbol->val = fn;

    return fn;
}

std::any CodegenVisitor::visitBlock(WPLParser::BlockContext *ctx) {
    BasicBlock *BB = BasicBlock::Create(M->getContext(), ctx->getText());
    builder->SetInsertPoint(BB);
    return visitChildren(ctx);
}

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
        // builder->CreateStore(exVal, v);
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
        // builder->CreateStore(exVal, v);
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

