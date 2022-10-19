/**
 * @file rpmprinter.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 */

#include <iostream>
#include "antlr4-runtime.h"
#include "CalculatorLexer.h"
#include "CalculatorParser.h"
#include "RPNVisitor.h"

RPNVisitor* visitor;

int main(int argc, const char* argv[]) {
  // Provide the input text in a stream
  antlr4::ANTLRInputStream input("6*(2+3);a := 42; 5 < 10 = ~false;");
  
  // Create a lexer from the input
  CalculatorLexer lexer(&input);
  
  // Create a token stream from the lexer
  antlr4::CommonTokenStream tokens(&lexer);
  
  // Create a parser from the token stream
  CalculatorParser parser(&tokens);  

  // Parse the input
  CalculatorParser::ProgramContext* tree = parser.program();

  // Now visit the parse tree
  std::cout << "RPN for \"6*(2+3);a := 42; 5 < 10 = ~false;\"" << std::endl;
  visitor = new RPNVisitor();
  visitor->visitProgram(tree);

  return 0;
}