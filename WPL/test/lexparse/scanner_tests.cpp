#include <catch2/catch_test_macros.hpp>

#include "CalculatorLexer.h"
#include "antlr4-runtime.h"
#include "test_error_handlers.h"

TEST_CASE("Scanner operator tests", "[front-end]") {
    antlr4::ANTLRInputStream input(":= / = > < - * ~ + ~=");
    CalculatorLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(new TestErrorListener());
    CHECK(lexer.nextToken()->getType() == lexer.ASSIGN);
    CHECK(lexer.nextToken()->getType() == lexer.DIVIDE);
    CHECK(lexer.nextToken()->getType() == lexer.EQUAL);
    CHECK(lexer.nextToken()->getType() == lexer.GREATER);
    CHECK(lexer.nextToken()->getType() == lexer.LESS);
    CHECK(lexer.nextToken()->getType() == lexer.MINUS);
    CHECK(lexer.nextToken()->getType() == lexer.MULTIPLY);
    CHECK(lexer.nextToken()->getType() == lexer.NOT);
    CHECK(lexer.nextToken()->getType() == lexer.PLUS);
    CHECK(lexer.nextToken()->getType() == lexer.UNEQUAL);
}

TEST_CASE("Invalid lexemes", "[front-end]") {
    antlr4::ANTLRInputStream input("{");
    CalculatorLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(new TestErrorListener());
    // The next assertion works if we do not have our test error listener
    // CHECK_FALSE(lexer.nextToken()->getType() != lexer.EOF);
    CHECK_THROWS(lexer.nextToken());
}
