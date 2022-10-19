
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once

#include <llvm/IR/Constant.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/NoFolder.h>
#include <llvm/IR/Type.h>

#include "CalcErrorHandler.h"
#include "CalculatorBaseVisitor.h"
#include "CalculatorLexer.h"
#include "CalculatorParser.h"
#include "CalculatorVisitor.h"
#include "PropertyManager.h"
#include "antlr4-runtime.h"

using namespace llvm;
class CodegenVisitor : public CalculatorBaseVisitor {
   public:
    CodegenVisitor(PropertyManager *pm, std::string moduleName) {
        props = pm;
        context = new LLVMContext();
        module = new Module(moduleName, *context);
        // Use the NoFolder to turn off constant folding
        builder = new IRBuilder<NoFolder>(module->getContext());

        // cached types
        VoidTy = Type::getVoidTy(module->getContext());
        Int32Ty = Type::getInt32Ty(module->getContext());
        Int1Ty = Type::getInt1Ty(module->getContext());
        Int8Ty = Type::getInt8Ty(module->getContext());
        Int32Zero = ConstantInt::get(Int32Ty, 0, true);
        Int32One = ConstantInt::get(Int32Ty, 1, true);
        i8p = Type::getInt8PtrTy(module->getContext());
        Int8PtrPtrTy = i8p->getPointerTo();
    }

    std::any visitProgram(CalculatorParser::ProgramContext *ctx) override;
    std::any visitBooleanConstant(
        CalculatorParser::BooleanConstantContext *ctx) override;
    std::any visitAssignExpression(
        CalculatorParser::AssignExpressionContext *ctx) override;
    //  std::any visitAsgExpr(CalculatorParser::AsgExprContext *ctx) override;
    std::any visitIConstExpr(CalculatorParser::IConstExprContext *ctx) override;
    std::any visitBinaryArithExpr(
        CalculatorParser::BinaryArithExprContext *ctx) override;
    std::any visitEqExpr(CalculatorParser::EqExprContext *ctx) override;
    std::any visitUnaryNotExpr(
        CalculatorParser::UnaryNotExprContext *ctx) override;
    std::any visitVariableExpr(
        CalculatorParser::VariableExprContext *ctx) override;
    std::any visitParenExpr(CalculatorParser::ParenExprContext *ctx) override;
    std::any visitBinaryRelExpr(
        CalculatorParser::BinaryRelExprContext *ctx) override;
    std::any visitUnaryMinusExpr(
        CalculatorParser::UnaryMinusExprContext *ctx) override;

    std::string getErrors() { return errors.errorList(); }
    PropertyManager *getProperties() { return props; }
    bool hasErrors() { return errors.hasErrors(); }
    llvm::Module *getModule() { return module; }
    void modPrint() { module->print(llvm::outs(), nullptr); }

   private:
    PropertyManager *props;
    CalcErrorHandler errors;

    LLVMContext *context;
    Module *module;
    IRBuilder<NoFolder> *builder;
    // Catch commonly used types
    Type *VoidTy;
    Type *Int1Ty;
    Type *Int8Ty;
    Type *Int32Ty;
    Type *i8p;
    Type *Int8PtrPtrTy;
    Constant *Int32Zero;
    Constant *Int32One;
};

