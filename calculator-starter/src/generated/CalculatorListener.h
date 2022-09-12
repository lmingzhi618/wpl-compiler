
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CalculatorParser.
 */
class  CalculatorListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(CalculatorParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(CalculatorParser::ProgramContext *ctx) = 0;

  virtual void enterBooleanConstant(CalculatorParser::BooleanConstantContext *ctx) = 0;
  virtual void exitBooleanConstant(CalculatorParser::BooleanConstantContext *ctx) = 0;

  virtual void enterAssignExpression(CalculatorParser::AssignExpressionContext *ctx) = 0;
  virtual void exitAssignExpression(CalculatorParser::AssignExpressionContext *ctx) = 0;

  virtual void enterAsgExpr(CalculatorParser::AsgExprContext *ctx) = 0;
  virtual void exitAsgExpr(CalculatorParser::AsgExprContext *ctx) = 0;

  virtual void enterIConstExpr(CalculatorParser::IConstExprContext *ctx) = 0;
  virtual void exitIConstExpr(CalculatorParser::IConstExprContext *ctx) = 0;

  virtual void enterBinaryArithExpr(CalculatorParser::BinaryArithExprContext *ctx) = 0;
  virtual void exitBinaryArithExpr(CalculatorParser::BinaryArithExprContext *ctx) = 0;

  virtual void enterEqExpr(CalculatorParser::EqExprContext *ctx) = 0;
  virtual void exitEqExpr(CalculatorParser::EqExprContext *ctx) = 0;

  virtual void enterUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx) = 0;
  virtual void exitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx) = 0;

  virtual void enterVariableExpr(CalculatorParser::VariableExprContext *ctx) = 0;
  virtual void exitVariableExpr(CalculatorParser::VariableExprContext *ctx) = 0;

  virtual void enterParenExpr(CalculatorParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(CalculatorParser::ParenExprContext *ctx) = 0;

  virtual void enterBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx) = 0;
  virtual void exitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx) = 0;

  virtual void enterUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *ctx) = 0;
  virtual void exitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *ctx) = 0;

  virtual void enterBConstExpr(CalculatorParser::BConstExprContext *ctx) = 0;
  virtual void exitBConstExpr(CalculatorParser::BConstExprContext *ctx) = 0;


};

