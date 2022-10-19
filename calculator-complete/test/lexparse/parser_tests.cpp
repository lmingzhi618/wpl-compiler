/**
 * @file parser_tests.cpp
 * @author gpollice
 * @brief Parser tests
 * @version 0.1
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 * @see https://stackoverflow.com/questions/44515370/how-to-override-error-reporting-in-c-target-of-antlr4
 */

#include <catch2/catch_test_macros.hpp>
#include "antlr4-runtime.h"
#include "CalculatorLexer.h"
#include "CalculatorParser.h"
#include "test_error_handlers.h"

/****************** Positive tests ******************/

TEST_CASE("Integer expression", "[front-end]") {
  antlr4::ANTLRInputStream input("1;");
  CalculatorLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CalculatorParser parser(&tokens);
  parser.removeErrorListeners();
  parser.addErrorListener(new TestErrorListener());
  antlr4::tree::ParseTree* tree = NULL;
  REQUIRE_NOTHROW(tree = parser.program());
  REQUIRE(tree != NULL);
}

/****************** Negative tests ******************/

TEST_CASE("Double operators", "[front-end]") {
  antlr4::ANTLRInputStream input("2 +* 5;");
  CalculatorLexer lexer(&input);
  lexer.removeErrorListeners();
  lexer.addErrorListener(new TestErrorListener());
  antlr4::CommonTokenStream tokens(&lexer);
  CalculatorParser parser(&tokens);
  parser.removeErrorListeners();
  parser.addErrorListener(new TestErrorListener());
  REQUIRE_THROWS(parser.program());
}