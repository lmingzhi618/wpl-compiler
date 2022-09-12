
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorVisitor.h"


/**
 * This class provides an empty implementation of CalculatorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalculatorBaseVisitor : public CalculatorVisitor {
public:

  virtual std::any visitProgram(CalculatorParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanConstant(CalculatorParser::BooleanConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpression(CalculatorParser::AssignExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsgExpr(CalculatorParser::AsgExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIConstExpr(CalculatorParser::IConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryArithExpr(CalculatorParser::BinaryArithExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExpr(CalculatorParser::EqExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableExpr(CalculatorParser::VariableExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(CalculatorParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBConstExpr(CalculatorParser::BConstExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

