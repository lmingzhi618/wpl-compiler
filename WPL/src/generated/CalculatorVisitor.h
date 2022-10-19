
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalculatorParser.
 */
class  CalculatorVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalculatorParser.
   */
    virtual std::any visitProgram(CalculatorParser::ProgramContext *context) = 0;

    virtual std::any visitBooleanConstant(CalculatorParser::BooleanConstantContext *context) = 0;

    virtual std::any visitAssignExpression(CalculatorParser::AssignExpressionContext *context) = 0;

    virtual std::any visitAsgExpr(CalculatorParser::AsgExprContext *context) = 0;

    virtual std::any visitIConstExpr(CalculatorParser::IConstExprContext *context) = 0;

    virtual std::any visitBinaryArithExpr(CalculatorParser::BinaryArithExprContext *context) = 0;

    virtual std::any visitEqExpr(CalculatorParser::EqExprContext *context) = 0;

    virtual std::any visitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *context) = 0;

    virtual std::any visitVariableExpr(CalculatorParser::VariableExprContext *context) = 0;

    virtual std::any visitParenExpr(CalculatorParser::ParenExprContext *context) = 0;

    virtual std::any visitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *context) = 0;

    virtual std::any visitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *context) = 0;

    virtual std::any visitBConstExpr(CalculatorParser::BConstExprContext *context) = 0;


};

