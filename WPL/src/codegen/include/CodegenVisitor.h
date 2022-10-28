
// Generated from WPL.g4 by ANTLR 4.10.1

#pragma once

#include <map>
#include <llvm/IR/Function.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/NoFolder.h>
#include <llvm/IR/Type.h>

#include "ErrorHandler.h"
#include "PropertyManager.h"
#include "Scope.h"
#include "Symbol.h"
#include "WPLBaseVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "WPLVisitor.h"
#include "antlr4-runtime.h"

using namespace llvm;

typedef SmallVector<BasicBlock *, 16> BBList;
typedef SmallVector<Value *, 16> VarList;

class CodegenVisitor : public WPLBaseVisitor {
   public:
    CodegenVisitor(PropertyManager *pm, std::string MName) {
        props = pm;
        context = new LLVMContext();
        M = new Module(MName, *context);
        // Use the NoFolder to turn off constant folding
        builder = new IRBuilder<NoFolder>(M->getContext());

        // cached types
        VoidTy = Type::getVoidTy(M->getContext());
        Int32Ty = Type::getInt32Ty(M->getContext());
        Int1Ty = Type::getInt1Ty(M->getContext());
        Int8Ty = Type::getInt8Ty(M->getContext());
        Int32Zero = ConstantInt::get(Int32Ty, 0, true);
        Int32One = ConstantInt::get(Int32Ty, 1, true);
        i8p = Type::getInt8PtrTy(M->getContext());
        Int8PtrPtrTy = i8p->getPointerTo();
    }

    // std::any visitCompilationUnit(
    //     WPLParser::CompilationUnitContext *ctx) override;
    std::any visitVarDeclaration(
        WPLParser::VarDeclarationContext *ctx) override;
    // std::any visitScalarDeclaration(
    //     WPLParser::ScalarDeclarationContext *ctx) override;
    std::any visitScalar(WPLParser::ScalarContext *ctx) override;
    std::any visitArrayDeclaration(
        WPLParser::ArrayDeclarationContext *ctx) override;
    //   std::any visitType(WPLParser::TypeContext *ctx) override;
    std::any visitVarInitializer(
        WPLParser::VarInitializerContext *ctx) override;
    // std::any visitExternDeclaration(
    //     WPLParser::ExternDeclarationContext *ctx) override;
    //  std::any visitProcedure(WPLParser::ProcedureContext
    //    *ctx) override; std::any
    //    visitProcHeader(WPLParser::ProcHeaderContext *ctx) override;
    //    std::any visitExternProcHeader(
    //        WPLParser::ExternProcHeaderContext *ctx) override;
    std::any visitFunction(WPLParser::FunctionContext *ctx) override;
    std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx) override;
    //std::any visitExternFuncHeader(
    //    WPLParser::ExternFuncHeaderContext *ctx) override;
    // std::any visitParam(WPLParser::ParamContext *ctx) override;
    // std::any visitParams(WPLParser::ParamsContext *ctx) override;
    std::any visitBlock(WPLParser::BlockContext *ctx) override;

    //// std::any visitStatement(WPLParser::StatementContext *ctx)override;
    // std::any visitLoop(WPLParser::LoopContext *ctx) override;
    // std::any visitConditional(WPLParser::ConditionalContext *ctx)
    // override;
    //// std::any visitSelect(WPLParser::SelectContext *ctx) override;
    // std::any visitSelectAlt(WPLParser::SelectAltContext *ctx) override;
    // std::any visitCall(WPLParser::CallContext *ctx) override;
    //// std::any visitArguments(WPLParser::ArgumentsContext *ctx)override;
    //// std::any visitArg(WPLParser::ArgContext *ctx) override;
    std::any visitReturn(WPLParser::ReturnContext *ctx) override;
    std::any visitConstant(WPLParser::ConstantContext *ctx) override;
    std::any visitAssignment(WPLParser::AssignmentContext *ctx) override;
    //// std::any visitArrayIndex(WPLParser::ArrayIndexContext *ctx)
    /// override;
    // std::any visitAndExpr(WPLParser::AndExprContext *ctx) override;
    std::any visitIDExpr(WPLParser::IDExprContext *ctx) override;
    //// std::any visitConstExpr(WPLParser::ConstExprContext *ctx) override;
    ////   std::any
    ////   visitSubscriptExpr(WPLParser::SubscriptExprContext*ctx)override;
    std::any visitRelExpr(WPLParser::RelExprContext *ctx) override;
    ////  std::any visitMultExpr(WPLParser::MultExprContext *ctx) override;
    std::any visitBinaryArithExpr(
        WPLParser::BinaryArithExprContext *ctx) override;
    ////  std::any visitArrayLengthExpr(WPLParser::ArrayLengthExprContext
    ///*ctx) /  override;

    std::any visitUMinusExpr(WPLParser::UMinusExprContext *ctx) override;
    // std::any visitOrExpr(WPLParser::OrExprContext *ctx) override;
    std::any visitEqExpr(WPLParser::EqExprContext *ctx) override;
    std::any visitNotExpr(WPLParser::NotExprContext *ctx) override;
    std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override;
    std::any visitFuncCallExpr(WPLParser::FuncCallExprContext *ctx) override;

    std::string getErrors() { return errors.errorList(); }
    PropertyManager *getProperties() { return props; }
    bool hasErrors() { return errors.hasErrors(); }
    llvm::Module *getModule() { return M; }
    void modPrint() { M->print(llvm::outs(), nullptr); }

    Type *getLLVMType(SymBaseType bt) {
        auto type = CodegenVisitor::Int32Ty;
        if (bt == STR) {
            type = CodegenVisitor::Int8PtrPtrTy;
        } else if (bt == BOOL) {
            type = CodegenVisitor::Int1Ty;
        }
        return type;
    }

    bool isGlobal(antlr4::tree::ParseTree *c) {
        antlr4::tree::ParseTree *ctx = c;
        while (ctx && !dynamic_cast<WPLParser::FunctionContext *>(ctx)) {
            ctx = ctx->parent;
        }
        return ctx == nullptr;
    }

    Function *getParentFunc(antlr4::tree::ParseTree *c) {
        antlr4::tree::ParseTree *ctx = c;
        while (ctx) {
            if(dynamic_cast<WPLParser::FunctionContext *>(ctx)) {
                break;
            }
            ctx = ctx->parent;
        }
        if (funcMap.count(ctx)) {
            return funcMap[ctx];
        }
        return nullptr;
    }
    
    Value * getTypeZero(SymBaseType type) {
        if (type == INT) {
            return builder->getInt32(0);
        }
        if (type == BOOL) {
            return builder->getInt1(0);
        }
        return builder->getInt8(0);
    }
   private:
    BasicBlock *createBB(std::string twine, Function *Parent = nullptr,
                         BasicBlock *InsertBefore = nullptr);
    Function *createFunc(FunctionType *fn_type, std::string twine);
    Value *createArith(IRBuilder<> &Builder, Value *L, Value *R);
    void setFuncArgs(Function *fooFunc, std::vector<std::string> funArgs);
    BasicBlock *createBB(Function *func, std::string name);
    GlobalVariable *createGlob(Type *type, std::string name);
    Value *createIfElse(IRBuilder<> &Builder, BBList List, VarList VL);

   private:
    PropertyManager *props;
    ErrorHandler errors;

    LLVMContext *context;
    Module *M;
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
    StringMap<Value *> nameMap;
    std::map<antlr4::tree::ParseTree*, Function*> funcMap;
    Value *V;
};

