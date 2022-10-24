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

std::any CodegenVisitor::visitProgram(CalculatorParser::ProgramContext *ctx) {
    // 1 Declare external functions.
    auto printf_prototype = FunctionType::get(i8p, true);
    auto printf_fn = Function::Create(
        printf_prototype, Function::ExternalLinkage, "printf", module);
    FunctionCallee printExpr(printf_prototype, printf_fn);

    // 2. Define the main program.
    FunctionType *mainFuncType =
        FunctionType::get(Int32Ty, {Int32Ty, Int8PtrPtrTy}, false);
    Function *mainFunc = Function::Create(
        mainFuncType, GlobalValue::ExternalLinkage, "program", module);

    // 3. Create a basic block and attach it to the builder
    BasicBlock *bBlock =
        BasicBlock::Create(module->getContext(), "entry", mainFunc);
    builder->SetInsertPoint(bBlock);

    // 4. Generate the code for all of the expression in the block.
    if (ctx->cuComponent) {
    }
    for (auto e : ctx->exprs) {
        Value *exprResult = std::any_cast<Value *>(e->accept(this));
        auto et = e->getText();  // the text of the expression
        StringRef formatRef = "Expression %s evaluates to %d\n";
        auto gFormat = builder->CreateGlobalStringPtr(formatRef, "fmtStr");
        StringRef exprRef = et;
        auto exFormat = builder->CreateGlobalStringPtr(exprRef, "exprStr");
        builder->CreateCall(printf_fn, {gFormat, exFormat, exprResult});
    }

    // 5. Generate code module trailer.
    builder->CreateRet(Int32Zero);
    return nullptr;
}

std::any CodegenVisitor::visitBooleanConstant(
    CalculatorParser::BooleanConstantContext *ctx) {
    Value *v;
    if (ctx->val->getType() == CalculatorParser::TRUE) {
        v = builder->getInt32(1);
    } else {
        v = builder->getInt32(0);
    }
    return v;
}

std::any CodegenVisitor::visitIConstExpr(
    CalculatorParser::IConstExprContext *ctx) {
    int i = std::stoi(ctx->i->getText());
    Value *v = builder->getInt32(i);
    return v;
}

std::any CodegenVisitor::visitParenExpr(
    CalculatorParser::ParenExprContext *ctx) {
    return ctx->ex->accept(this);
}

std::any CodegenVisitor::visitUnaryMinusExpr(
    CalculatorParser::UnaryMinusExprContext *ctx) {
    Value *exVal = std::any_cast<Value *>(ctx->ex->accept(this));
    Value *v = builder->CreateNSWSub(builder->getInt32(0), exVal);
    return v;
}

std::any CodegenVisitor::visitUnaryNotExpr(
    CalculatorParser::UnaryNotExprContext *ctx) {
    Value *v = std::any_cast<Value *>(ctx->ex->accept(this));
    v = builder->CreateZExtOrTrunc(v, CodegenVisitor::Int1Ty);
    v = builder->CreateXor(v, Int32One);
    v = builder->CreateZExtOrTrunc(v, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitBinaryArithExpr(
    CalculatorParser::BinaryArithExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    auto opType = ctx->op->getType();
    switch (opType) {
        case CalculatorParser::PLUS:
            v = builder->CreateNSWAdd(lVal, rVal);
            break;
        case CalculatorParser::MINUS:
            v = builder->CreateNSWSub(lVal, rVal);
            break;
        case CalculatorParser::MULTIPLY:
            v = builder->CreateNSWMul(lVal, rVal);
            break;
        case CalculatorParser::DIVIDE:
            v = builder->CreateSDiv(lVal, rVal);
            break;
    }
    return v;
}

std::any CodegenVisitor::visitBinaryRelExpr(
    CalculatorParser::BinaryRelExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    auto op = ctx->op->getType();
    Value *v1;
    if (op == CalculatorParser::LESS) {
        v1 = builder->CreateICmpSLT(lVal, rVal);
    } else {
        v1 = builder->CreateICmpSGT(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int32Ty);
}

std::any CodegenVisitor::visitEqExpr(CalculatorParser::EqExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    auto op = ctx->op->getType();
    Value *v1;
    if (op == CalculatorParser::EQUAL) {
        v1 = builder->CreateICmpEQ(lVal, rVal);
    } else {
        v1 = builder->CreateICmpNE(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitAssignExpression(
    CalculatorParser::AssignExpressionContext *ctx) {
    Value *v = nullptr;
    Value *exVal = std::any_cast<Value *>(ctx->ex->accept(this));
    Symbol *varSymbol = props->getBinding(ctx);  // child variable symbol
    if (varSymbol == nullptr) {
        trace("NULLPTR");
        exit(-1);
    }
    if (false == varSymbol->defined) {
        // Define the symbol and allocate memory.
        v = builder->CreateAlloca(CodegenVisitor::Int32Ty, 0,
                                  varSymbol->identifier);
        varSymbol->defined = true;
        varSymbol->val = v;
    } else {
        v = varSymbol->val;
    }
    builder->CreateStore(exVal, v);
    return exVal;
}

std::any CodegenVisitor::visitVariableExpr(
    CalculatorParser::VariableExprContext *ctx) {
    // 1. Get the name of the variable.
    std::string varId = ctx->v->getText();
    // 2. Get the binding.
    Symbol *symbol = props->getBinding(ctx);
    Value *v = nullptr;
    // We made sure that the variable is defined in the semantic analysis
    // phase
    if (!(symbol->defined)) {
        errors.addCodegenError(ctx->getStart(),
                               "Undefined variable in expression: " + varId);
    } else {
        v = builder->CreateLoad(CodegenVisitor::Int32Ty, symbol->val, varId);
    }
    return v;
}

