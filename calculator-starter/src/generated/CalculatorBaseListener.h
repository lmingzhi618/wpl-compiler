
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorListener.h"


/**
 * This class provides an empty implementation of CalculatorListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CalculatorBaseListener : public CalculatorListener {
public:

  virtual void enterProgram(CalculatorParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(CalculatorParser::ProgramContext * /*ctx*/) override { }

  virtual void enterBooleanConstant(CalculatorParser::BooleanConstantContext * /*ctx*/) override { }
  virtual void exitBooleanConstant(CalculatorParser::BooleanConstantContext * /*ctx*/) override { }

  virtual void enterAssignExpression(CalculatorParser::AssignExpressionContext * /*ctx*/) override { }
  virtual void exitAssignExpression(CalculatorParser::AssignExpressionContext * /*ctx*/) override { }

  virtual void enterAsgExpr(CalculatorParser::AsgExprContext * /*ctx*/) override { }
  virtual void exitAsgExpr(CalculatorParser::AsgExprContext * /*ctx*/) override { }

  virtual void enterIConstExpr(CalculatorParser::IConstExprContext * /*ctx*/) override { }
  virtual void exitIConstExpr(CalculatorParser::IConstExprContext * /*ctx*/) override { }

  virtual void enterBinaryArithExpr(CalculatorParser::BinaryArithExprContext * /*ctx*/) override { }
  virtual void exitBinaryArithExpr(CalculatorParser::BinaryArithExprContext * /*ctx*/) override { }

  virtual void enterEqExpr(CalculatorParser::EqExprContext * /*ctx*/) override { }
  virtual void exitEqExpr(CalculatorParser::EqExprContext * /*ctx*/) override { }

  virtual void enterUnaryNotExpr(CalculatorParser::UnaryNotExprContext * /*ctx*/) override { }
  virtual void exitUnaryNotExpr(CalculatorParser::UnaryNotExprContext * /*ctx*/) override { }

  virtual void enterVariableExpr(CalculatorParser::VariableExprContext * /*ctx*/) override { }
  virtual void exitVariableExpr(CalculatorParser::VariableExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(CalculatorParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(CalculatorParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterBinaryRelExpr(CalculatorParser::BinaryRelExprContext * /*ctx*/) override { }
  virtual void exitBinaryRelExpr(CalculatorParser::BinaryRelExprContext * /*ctx*/) override { }

  virtual void enterUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext * /*ctx*/) override { }
  virtual void exitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext * /*ctx*/) override { }

  virtual void enterBConstExpr(CalculatorParser::BConstExprContext * /*ctx*/) override { }
  virtual void exitBConstExpr(CalculatorParser::BConstExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

