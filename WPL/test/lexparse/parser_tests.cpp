#include <catch2/catch_test_macros.hpp>

#include "WPLLexer.h"
#include "WPLParser.h"
#include "antlr4-runtime.h"
#include "test_error_handlers.h"

TEST_CASE("Integer expresson", "[front-end]") {
    antlr4::ANTLRInputStream input("1;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(new TestErrorListener());
    antlr4::tree::ParseTree* tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
}

TEST_CASE("Double operators", "[front-end]") {
    antlr4::ANTLRInputStream input("2 +* 5;");
    WPLLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(new TestErrorListener());
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(new TestErrorListener());
    // REQUIRE_THROWS(parser.program());
    REQUIRE_THROWS(parser.expression());
}
