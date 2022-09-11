
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CalculatorParser.
 */
class  CalculatorListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterText(CalculatorParser::TextContext *ctx) = 0;
  virtual void exitText(CalculatorParser::TextContext *ctx) = 0;


};

