#pragma once
#include "CalcErrorHandler.h"
#include "CalculatorBaseVisitor.h"
#include "PropertyManager.h"
#include "STManager.h"
#include "antlr4-runtime.h"

class SemanticVisitor : CalculatorBaseVisitor {
   public:
    SemanticVisitor(STManager *stmgr, PropertyManager *pm)
        : stmgr(stmgr), bindings(pm) {}

    std::any visitProgram(CalculatorParser::ProgramContext *ctx) override;
    std::any visitBooleanConstant(
        CalculatorParser::BooleanConstantContext *ctx) override;
    std::any visitIConstExpr(CalculatorParser::IConstExprContext *ctx) override;
    std::any visitParenExpr(CalculatorParser::ParenExprContext *ctx) override;
    std::any visitUnaryMinusExpr(
        CalculatorParser::UnaryMinusExprContext *ctx) override;
    std::any visitUnaryNotExpr(
        CalculatorParser::UnaryNotExprContext *ctx) override;
    std::any visitBinaryArithExpr(
        CalculatorParser::BinaryArithExprContext *ctx) override;
    std::any visitBinaryRelExpr(
        CalculatorParser::BinaryRelExprContext *ctx) override;
    std::any visitEqExpr(CalculatorParser::EqExprContext *ctx) override;
    std::any visitAssignExpression(
        CalculatorParser::AssignExpressionContext *ctx) override;
    std::any visitVariableExpr(
        CalculatorParser::VariableExprContext *ctx) override;

    bool hasErrors() { return errors.hasErrors(); }
    std::string getErrors() { return errors.errorList(); }
    STManager *getSTManager() { return stmgr; }
    PropertyManager *getBindings() { return bindings; }

   private:
    STManager *stmgr;
    PropertyManager *bindings;
    CalcErrorHandler errors;
};
