/**
 * @file semantic_tests.cpp
 * @author gpollice
 * @brief Semantic analysis tests
 * @version 0.1
 * @date 2022-07-21
 */
#include <catch2/catch_test_macros.hpp>
#include "antlr4-runtime.h"
#include "CalculatorLexer.h"
#include "CalculatorParser.h"
#include "CalcErrorHandler.h"
#include "SemanticVisitor.h"

TEST_CASE("Development tests", "[semantic]") {
  antlr4::ANTLRInputStream input("42; true; -5; 6 * 7 + 3;7*6 < 6+7;7 + 3 = 6 * 4;");
  CalculatorLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CalculatorParser parser(&tokens);
  parser.removeErrorListeners();
  CalculatorParser::ProgramContext* tree = NULL;
  REQUIRE_NOTHROW(tree = parser.program());
  REQUIRE(tree != NULL);
  SemanticVisitor* sv = new SemanticVisitor(new STManager(), new PropertyManager());  // NEW
  sv->visitProgram(tree);
  if (sv->hasErrors()) {
    CHECK("foo" == sv->getErrors());
  }
  CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("Simple valid expressions", "[semantic]") {
  antlr4::ANTLRInputStream input("3 * 2 = 2 * 3;");
  CalculatorLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CalculatorParser parser(&tokens);
  parser.removeErrorListeners();
  CalculatorParser::ProgramContext* tree = NULL;
  REQUIRE_NOTHROW(tree = parser.program());
  REQUIRE(tree != NULL);
  SemanticVisitor* sv = new SemanticVisitor(new STManager(), new PropertyManager());
  sv->visitProgram(tree);
  // if (sv->hasErrors()) {
  //   CHECK("foo" == sv->getErrors());
  // }
  CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("Defined variables", "[semantic]") {
  antlr4::ANTLRInputStream input("a := 1; b := a;");
  CalculatorLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CalculatorParser parser(&tokens);
  parser.removeErrorListeners();
  CalculatorParser::ProgramContext* tree = NULL;
  REQUIRE_NOTHROW(tree = parser.program());
  REQUIRE(tree != NULL);
  STManager* stm = new STManager();
  SemanticVisitor* sv = new SemanticVisitor(stm, new PropertyManager());
  sv->visitProgram(tree);
  if (sv->hasErrors()) {
    CHECK("foo" == sv->getErrors());
  }
  CHECK_FALSE(sv->hasErrors());
  CHECK(stm->findSymbol("a") != nullptr);
}

TEST_CASE("Undefined variable", "[semantic]") {
  antlr4::ANTLRInputStream input("a + 1;");
  CalculatorLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CalculatorParser parser(&tokens);
  parser.removeErrorListeners();
  CalculatorParser::ProgramContext* tree = NULL;
  REQUIRE_NOTHROW(tree = parser.program());
  REQUIRE(tree != NULL);
  STManager* stm = new STManager();
  SemanticVisitor* sv = new SemanticVisitor(stm, new PropertyManager());
  sv->visitProgram(tree);
  // if (sv->hasErrors()) {
  //   CHECK("foo" == sv->getErrors());
  // }
  CHECK(sv->hasErrors());
}