#include <string.h>

#include <iostream>

#include "RPNVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "antlr4-runtime.h"
//#include "antlr4/include/ANTLRInputStream.h"
//#include "antlr4/include/CommonTokenStream.h"

int main(int argc, const char **argv) {
    // Provide the input text in a stream
    char *str = "6*(2+3);a := 42; 5 < 10 = ~false; n ~= 5";
    antlr4::ANTLRInputStream input(str);

    // Create a lexer from the input
    WPLLexer lexer(&input);

    // Create a token stream from the lexer
    antlr4::CommonTokenStream tokens(&lexer);

    // Create a parser from the token stream
    WPLParser parser(&tokens);

    // Parse the input
    WPLParser::ProgramContext *tree = parser.program();

    // Now visit the parse tree
    std::cout << "RPN for " << str << std::endl;
    auto visitor = new RPNVisitor();
    visitor->visitProgram(tree);

    return 0;
}
