/**
 * @file RPNVisitor.h
 * @author gpollice
 * @brief Header file for the RPN Visitor
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "antlr4-runtime.h"
#include "CalculatorBaseVisitor.h"

class RPNVisitor : CalculatorBaseVisitor {
  public :
    std::any visitProgram(CalculatorParser::ProgramContext *ctx);
    std::any visitBooleanConstant(CalculatorParser::BooleanConstantContext *ctx);
    std::any visitAssignExpression(CalculatorParser::AssignExpressionContext *ctx);
    std::any visitParenExpr(CalculatorParser::ParenExprContext *ctx);
    std::any visitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *ctx);
    std::any visitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx);
    std::any visitBinaryArithExpr(CalculatorParser::BinaryArithExprContext *ctx);
    std::any visitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx);
    std::any visitEqExpr(CalculatorParser::EqExprContext *ctx);
    std::any visitVariableExpr(CalculatorParser::VariableExprContext *ctx);
    std::any visitIConstExpr(CalculatorParser::IConstExprContext *ctx);
};