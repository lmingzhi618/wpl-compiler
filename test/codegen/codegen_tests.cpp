#include <catch2/catch_test_macros.hpp>

#include "CalcErrorHandler.h"
#include "CodegenVisitor.h"
#include "SemanticVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "antlr4-runtime.h"

TEST_CASE("Development tests", "[codegen]") {
    antlr4::ANTLRInputStream input("42;");
    WPLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    parser.removeErrorListeners();
    WPLParser::ProgramContext *tree = NULL;
    REQUIRE_NOTHROW(tree = parser.program());
    REQUIRE(tree != NULL);
    STManager *stm = new STManager();
    PropertyManager *pm = new PropertyManager();
    SemanticVisitor *sv = new SemanticVisitor(stm, pm);
    sv->visitProgram(tree);
    CodegenVisitor *cv = new CodegenVisitor(pm, "test");
    cv->visitProgram(tree);
    if (cv->hasErrors()) {
        CHECK("foo" == cv->getErrors());
    }
    CHECK_FALSE(cv->hasErrors());
}
