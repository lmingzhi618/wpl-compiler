#pragma once
#include "CalculatorBaseVisitor.h"
#include "PropertyManager.h"
#include "STManager.h"
#include "antlr4-runtime.h"

class SemanticVisitor : CalculatorBaseVisitor {
   public:
    SemanticVisitor() {}
    SemanticVisitor(STManager *stm, PropertyManager *pm) : stm(stm), pm(pm) {}
    std::any visitProgram(CalculatorParser::ProgramContext *ctx);
    // std::any visitBooleanConstant(CalculatorParser::BooleanContextContext
    // *ctx); std::any visitAssignExpression(
    //     CalculatorParser::AssignExpressionContext *ctx);
    // std::any visitParenExpr(CalculatorParser::ParenExprContext *ctx);
    // std::any visitUnaryEqExpr(CalculatorParser::UnaryEqExprContext *ctx);
    // std::any visitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx);
    // std::any visitBinaryArithExpr(
    //     CalculatorParser::BinaryArithExprContext *ctx);
    // std::any visitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx);
    // std::any visitEqExpr(CalculatorParser::EqExprContext *ctx);
    // std::any visitVariableExpr(CalculatorParser::VariableExprContext *ctx);
    // std::any visitIConstExpr(CalculatorParser::IConstExprContext *ctx);
    bool hasErrors() { return false; }
    std::string getErrors() { return ""; }

   private:
    STManager *stm;
    PropertyManager *pm;
};
