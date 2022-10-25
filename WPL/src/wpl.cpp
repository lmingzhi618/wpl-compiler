#include <llvm/IR/Module.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/raw_ostream.h>

#include <fstream>
#include <iostream>

#include "CodegenVisitor.h"
#include "ErrorHandler.h"
#include "PropertyManager.h"
#include "STManager.h"
#include "SemanticVisitor.h"
#include "SymbolVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "antlr4-runtime.h"

void parseArgs(int argc, const char* argv[]) {
    std::cout << ">>> parseArgs <<<" << std::endl;
}

llvm::cl::OptionCategory WPLOptions("WPL Options");
static llvm::cl::opt<std::string> inputFileName(llvm::cl::Positional,
                                                llvm::cl::desc("<input file>"),
                                                llvm::cl::init("-"),
                                                llvm::cl::cat(WPLOptions));

static llvm::cl::opt<bool> printOutput("p", llvm::cl::desc("Print the IR"),
                                       llvm::cl::cat(WPLOptions));

static llvm::cl::opt<std::string> inputString(
    "s",
    llvm::cl::desc(
        "Take input from a string, do not use an input file if -s is used"),
    llvm::cl::value_desc("input string"), llvm::cl::init("-"),
    llvm::cl::cat(WPLOptions));

static llvm::cl::opt<std::string> outputFileName(
    "o", llvm::cl::desc("supply alternate output file"),
    llvm::cl::value_desc("output file"), llvm::cl::init("-"),
    llvm::cl::cat(WPLOptions));

static llvm::cl::opt<bool> noCode(
    "nocode", llvm::cl::desc("Do not generate any output file"),
    llvm::cl::cat(WPLOptions));

int main(int argc, char** argv) {
    // Commandline handling from the llvm::cl classes.
    llvm::cl::HideUnrelatedOptions(WPLOptions);
    llvm::cl::ParseCommandLineOptions(argc, argv);
    if (((inputFileName == "-") && (inputString == "-")) ||
        ((inputFileName != "-") && (inputString != "-"))) {
        std::cerr << "You can only have an input file or an input string, but "
                     "not both "
                  << std::endl;
        std::exit(-1);
    }

    antlr4::ANTLRInputStream* input = nullptr;
    if ("-" != inputFileName) {
        std::fstream* inStream = new std::fstream(inputFileName);
        input = new antlr4::ANTLRInputStream(*inStream);
    } else {
        input = new antlr4::ANTLRInputStream(inputString);
    }

    WPLLexer lexer(input);
    antlr4::CommonTokenStream tokens(&lexer);
    WPLParser parser(&tokens);
    WPLParser::CompilationUnitContext* tree = parser.compilationUnit();

    STManager* stm = new STManager();
    PropertyManager* pm = new PropertyManager();
    SemanticVisitor* semanticVisitor = new SemanticVisitor(stm, pm);
    semanticVisitor->visitCompilationUnit(tree);
    std::cout << stm->toString() << std::endl;
    if (semanticVisitor->hasErrors()) {
        std::cerr << semanticVisitor->getErrors() << std::endl;
        return -1;
    }

    // Generate the LLVM IR code
    CodegenVisitor* cv = new CodegenVisitor(pm, "wpl.ll");
    cv->visitCompilationUnit(tree);
    if (cv->hasErrors()) {
        std::cerr << cv->getErrors() << std::endl;
        return -1;
    }

    // Printout the module contents.
    llvm::Module* module = cv->getModule();
    std::cout << std::endl << std::endl;
    if (printOutput) {
        cv->modPrint();
    }

    // Dump the code to an output file
    if (!noCode) {
        std::cout << "dump code to file" << std::endl;
        std::string irFileName;
        if (outputFileName != "-") {
            irFileName = outputFileName;
        } else {
            irFileName =
                inputFileName.substr(0, inputFileName.find_last_of('.')) +
                ".ll";
        }
        std::error_code ec;
        llvm::raw_fd_ostream irFileStream(irFileName, ec);
        module->print(irFileStream, nullptr);
        irFileStream.flush();
    }
    return 0;
}

