
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

  virtual std::any visitText(CalculatorParser::TextContext *ctx) override {
    return visitChildren(ctx);
  }


};

