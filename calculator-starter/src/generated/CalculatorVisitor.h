
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
    virtual std::any visitText(CalculatorParser::TextContext *context) = 0;


};

