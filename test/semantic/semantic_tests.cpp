#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "ErrorHandler.h"
#include "PropertyManager.h"
#include "SemanticVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "antlr4-runtime.h"

TEST_CASE("Development tests", "[semantic]") {
    antlr4::ANTLRInputStream input("42;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // Error checking is NEW
    if (sv->hasErrors()) {
        CHECK("foo" == sv->getErrors());
    }
    CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("Simple valid expressions", "[semantics]") {
    antlr4::ANTLRInputStream input("3 * 2 = ((2 * 3) < 10);");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
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
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
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

TEST_CASE("Undefined variables", "[semantic]") {
    antlr4::ANTLRInputStream input("a + 1;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
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

TEST_CASE("Assignment tests", "[semantic]") {
    antlr4::ANTLRInputStream input("a := 5 * 3;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("UnaryMinus tests", "[semantic]") {
    antlr4::ANTLRInputStream input("42; true; -3;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // Error checking is NEW
    if (sv->hasErrors()) {
        CHECK("foo" == sv->getErrors());
    }
    CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("UnaryNot tests", "[semantic]") {
    antlr4::ANTLRInputStream input("~false;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // Error checking is NEW
    if (sv->hasErrors()) {
        CHECK("foo" == sv->getErrors());
    }
    CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("BinaryArithExpr tests", "[semantic]") {
    antlr4::ANTLRInputStream input("2 + 3; 4 * 5 * 2;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // Error checking is NEW
    if (sv->hasErrors()) {
        CHECK("foo" == sv->getErrors());
    }
    CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("BinaryRelExpr tests", "[semantic]") {
    antlr4::ANTLRInputStream input("2 < 3;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // Error checking is NEW
    if (sv->hasErrors()) {
        CHECK("foo" == sv->getErrors());
    }
    CHECK_FALSE(sv->hasErrors());
}

TEST_CASE("EqExpr tests", "[semantic]") {
    antlr4::ANTLRInputStream input("1 < 4 = 3 = 2 = 4 > 3;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    SemanticVisitor* sv =
        new SemanticVisitor(new STManager(), new PropertyManager());
    sv->visitProgram(tree);
    // Error checking is NEW
    if (sv->hasErrors()) {
        CHECK("foo" == sv->getErrors());
    }
    CHECK_FALSE(sv->hasErrors());
}
