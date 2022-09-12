#include <iostream>

#include "CalculatorLexer.h"
#include "CalculatorParser.h"
#include "antlr4-runtime.h"

void parseArgs(int argc, const char* argv[]) {
    std::cout << ">>> parseArgs <<<" << std::endl;
}

int main(int argc, const char* argv[]) {
    // parseArgs(argc, argv);
    //  Provide the input text in a stream
    antlr4::ANTLRInputStream input("a :=4; a = 6 * (2+3);");

    // Create a lexer from the input
    CalculatorLexer lexer(&input);

    // Create a token stream from the lexer
    antlr4::CommonTokenStream tokens(&lexer);

    // Create a parser from the token stream
    CalculatorParser parser(&tokens);

    // Display the parse tree
    std::cout << "OUTPUT\n" << parser.program()->toStringTree() << std::endl;
    return 0;
}
