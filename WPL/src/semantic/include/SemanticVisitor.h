#pragma once
#include "ErrorHandler.h"
#include "PropertyManager.h"
#include "STManager.h"
#include "WPLBaseVisitor.h"
#include "antlr4-runtime.h"

class SemanticVisitor : WPLBaseVisitor {
   public:
    SemanticVisitor(STManager *stmgr, PropertyManager *pm)
        : stmgr(stmgr), bindings(pm) {}

    std::any visitCompilationUnit(
        WPLParser::CompilationUnitContext *ctx) override;
    // std::any visitCuComponent(WPLParser::CuComponentContext *ctx) override;
    //  std::any visitVarDeclaration(WPLParser::VarDeclarationContext *ctx)
    //  override;
    std::any visitScalarDeclaration(
        WPLParser::ScalarDeclarationContext *ctx) override;
    // std::any visitScalar(WPLParser::ScalarContext *ctx) override;
    std::any visitArrayDeclaration(
        WPLParser::ArrayDeclarationContext *ctx) override;
    std::any visitType(WPLParser::TypeContext *ctx) override;
    // std::any visitVarInitializer(WPLParser::VarInitializerContext
    // *ctx)override;
    // std::any visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx)
    // override;
    std::any visitProcedure(WPLParser::ProcedureContext *ctx) override;
    std::any visitProcHeader(WPLParser::ProcHeaderContext *ctx) override;
    // std::any visitExternProcHeader(
    //     WPLParser::ExternProcHeaderContext *ctx) override;
    std::any visitFunction(WPLParser::FunctionContext *ctx) override;
    std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx) override;
    // std::any visitExternFuncHeader(
    //     WPLParser::ExternFuncHeaderContext *ctx) override;
    std::any visitParam(WPLParser::ParamContext *ctx) override;
    std::any visitParams(WPLParser::ParamsContext *ctx) override;
    std::any visitBlock(WPLParser::BlockContext *ctx) override;

    // std::any visitStatement(WPLParser::StatementContext *ctx)override;
    // std::any visitLoop(WPLParser::LoopContext *ctx) override;
    std::any visitConditional(WPLParser::ConditionalContext *ctx) override;
    // std::any visitSelect(WPLParser::SelectContext *ctx) override;
    // std::any visitSelectAlt(WPLParser::SelectAltContext *ctx) override;
    // std::any visitCall(WPLParser::CallContext *ctx) override;
    // std::any visitArguments(WPLParser::ArgumentsContext *ctx)override;
    // std::any visitArg(WPLParser::ArgContext *ctx) override;
    std::any visitReturn(WPLParser::ReturnContext *ctx) override;
    std::any visitConstant(WPLParser::ConstantContext *ctx) override;
    std::any visitAssignment(WPLParser::AssignmentContext *ctx) override;
    // std::any visitArrayIndex(WPLParser::ArrayIndexContext *ctx) override;
    // std::any visitAndExpr(WPLParser::AndExprContext *ctx) override;
    std::any visitIDExpr(WPLParser::IDExprContext *ctx) override;
    // std::any visitConstExpr(WPLParser::ConstExprContext *ctx) override;
    //   std::any
    //   visitSubscriptExpr(WPLParser::SubscriptExprContext*ctx)override;
    std::any visitRelExpr(WPLParser::RelExprContext *ctx) override;
    //  std::any visitMultExpr(WPLParser::MultExprContext *ctx) override;
    std::any visitBinaryArithExpr(
        WPLParser::BinaryArithExprContext *ctx) override;
    //  std::any visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx)
    //  override;

    std::any visitUMinusExpr(WPLParser::UMinusExprContext *ctx) override;
    // std::any visitOrExpr(WPLParser::OrExprContext *ctx) override;
    std::any visitEqExpr(WPLParser::EqExprContext *ctx) override;
    std::any visitNotExpr(WPLParser::NotExprContext *ctx) override;
    std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override;
    // std::any visitFuncCallExpr(WPLParser::FuncCallExprContext *ctx) override;

    bool hasErrors() { return errors.hasErrors(); }
    std::string getErrors() { return errors.errorList(); }
    STManager *getSTManager() { return stmgr; }
    PropertyManager *getBindings() { return bindings; }

   private:
    STManager *stmgr;
    PropertyManager *bindings;
    ErrorHandler errors;
};
