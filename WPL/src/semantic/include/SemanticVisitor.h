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

    // std::any visitCompilationUnit(
    //     WPLParser::CompilationUnitContext *ctx) override;

    //  std::any visitCuComponent(WPLParser::CuComponentContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitVarDeclaration(
    //      WPLParser::VarDeclarationContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitScalarDeclaration(
    //      WPLParser::ScalarDeclarationContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitScalar(WPLParser::ScalarContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitArrayDeclaration(
    //      WPLParser::ArrayDeclarationContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    std::any visitType(WPLParser::TypeContext *ctx) override;

    //  std::any visitVarInitializer(
    //      WPLParser::VarInitializerContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitExternDeclaration(
    //      WPLParser::ExternDeclarationContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitProcedure(WPLParser::ProcedureContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitProcHeader(WPLParser::ProcHeaderContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitExternProcHeader(
    //      WPLParser::ExternProcHeaderContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitFunction(WPLParser::FunctionContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitExternFuncHeader(
    //      WPLParser::ExternFuncHeaderContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitParams(WPLParser::ParamsContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitBlock(WPLParser::BlockContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitStatement(WPLParser::StatementContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitLoop(WPLParser::LoopContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitConditional(WPLParser::ConditionalContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitSelect(WPLParser::SelectContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitSelectAlt(WPLParser::SelectAltContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitCall(WPLParser::CallContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitArguments(WPLParser::ArgumentsContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitArg(WPLParser::ArgContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitReturn(WPLParser::ReturnContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    // std::any visitConstant(WPLParser::ConstantContext *ctx) override;

    //  std::any visitAssignment(WPLParser::AssignmentContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitArrayIndex(WPLParser::ArrayIndexContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitAndExpr(WPLParser::AndExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitIDExpr(WPLParser::IDExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitConstExpr(WPLParser::ConstExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitSubscriptExpr(WPLParser::SubscriptExprContext *ctx)
    //  override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitRelExpr(WPLParser::RelExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitMultExpr(WPLParser::MultExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitAddExpr(WPLParser::AddExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitArrayLengthExpr(
    //      WPLParser::ArrayLengthExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitUMinusExpr(WPLParser::UMinusExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitOrExpr(WPLParser::OrExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitEqExpr(WPLParser::EqExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitNotExpr(WPLParser::NotExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override {
    //      return visitChildren(ctx);
    //  }

    //  std::any visitFuncCallExpr(WPLParser::FuncCallExprContext *ctx) override
    //  {
    //      return visitChildren(ctx);
    //  }

    // CALCULATOR ...
    //  std::any visitBooleanConstant(
    //      WPLParser::BooleanConstantContext *ctx) override;
    //  std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override;
    //  std::any visitUnaryMinusExpr(
    //      WPLParser::UnaryMinusExprContext *ctx) override;
    //  std::any visitUnaryNotExpr(WPLParser::UnaryNotExprContext *ctx)
    //  override; std::any visitBinaryArithExpr(
    //      WPLParser::BinaryArithExprContext *ctx) override;
    //  std::any visitBinaryRelExpr(WPLParser::BinaryRelExprContext *ctx)
    //  override; std::any visitEqExpr(WPLParser::EqExprContext *ctx) override;
    //  std::any visitAssignExpression(
    //      WPLParser::AssignExpressionContext *ctx) override;
    //  std::any visitVariableExpr(WPLParser::VariableExprContext *ctx)
    //  override;

    bool hasErrors() { return errors.hasErrors(); }
    std::string getErrors() { return errors.errorList(); }
    STManager *getSTManager() { return stmgr; }
    PropertyManager *getBindings() { return bindings; }

   private:
    STManager *stmgr;
    PropertyManager *bindings;
    ErrorHandler errors;
};
