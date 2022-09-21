#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "CalcErrorHandler.h"
#include "CalculatorLexer.h"
#include "CalculatorParser.h"
#include "PropertyManager.h"
#include "SemanticVisitor.h"
#include "antlr4-runtime.h"

TEST_CASE("Dummy semantic tests", "[semantic]") { CHECK(true == true); }

TEST_CASE("Simple valid expressions", "[semantics]") {
    antlr4::ANTLRInputStream input("3 * 2 = ((2 * 3) < 10);");
    CalculatorLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    CalculatorParser parser(&tokens);
    parser.removeErrorListeners();
    CalculatorParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // if (sv->hasErrors()) {
    //     CHECK("foo" == sv->getErrors());
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
}

TEST_CASE("Undefined variables", "[semantic]") {
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
    //     CHECK("foo" == sv->getErrors());
    // }
    CHECK(sv->hasErrors());
}
