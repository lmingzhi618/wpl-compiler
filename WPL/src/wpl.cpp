#include "llvm/ADT/Triple.h"
#include "llvm/CodeGen/CommandFlags.h"

#include "llvm/IR/Module.h"
#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/Host.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/WithColor.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"

#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Analysis/AliasAnalysis.h"

#include "llvm/Target/TargetMachine.h"

#include <fstream>
#include <iostream>
#include <string>

#include "CodegenVisitor.h"
#include "ErrorHandler.h"
#include "PropertyManager.h"
#include "STManager.h"
#include "SemanticVisitor.h"
#include "SymbolVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "antlr4-runtime.h"

using namespace llvm;

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

// passes begin
// static codegen::RegisterCodeGenFlags CGF;

static cl::opt<std::string> MTriple("mtriple", cl::desc("Override target triple for module"));

static cl::opt<bool> EmitLLVM("emit-llvm",
                               cl::desc("Emit IR code instead of assembler"),
                               cl::init(false));

static cl::opt<signed char> OptLevel(
    cl::desc("Setting the optimization level:"),
    cl::ZeroOrMore,
    cl::values(
        clEnumValN(3, "O",  "Equivalent to -O3"),
        clEnumValN(0, "O0", "Optimization level 0"),
        clEnumValN(1, "O1", "Optimization level 1"),
        clEnumValN(2, "O2", "Optimization level 2"),
        clEnumValN(3, "O3", "Optimization level 3"),
        clEnumValN(-1, "Os", "Like -O2 with extra optimizations for size"),
        clEnumValN(-2, "Oz", "Like -Os but reduces code size further")
    ),
    cl::init(0));

static cl::opt<bool> DebugPM("debug-pass-manager",
                             cl::Hidden,
                             cl::desc("print PM debugging information"));

static cl::opt<std::string> PassPipeline("passes", cl::desc("A description of the pass pipeline"));

static cl::list<std::string> PassPlugins("load-pass-plugin",
                                         cl::desc("Load passes from plugin library"));
static cl::opt<std::string> PipelineStartEPPipeline(
    "passes-ep-pipeline-start",
    cl::desc("Pipeline start extension point"));

static const char *Head = "WPL - WPL compiler";

void printVersion(llvm::raw_ostream &OS) {
    OS << Head << "\n"
       << "Default target: " << llvm::sys::getDefaultTargetTriple() << "\n"
       << "Host CPU: " << llvm::sys::getHostCPUName() << "\n";
    OS.flush();
    TargetRegistry::printRegisteredTargetsForVersion(OS);
    exit(EXIT_SUCCESS);
}

llvm::TargetMachine * createTargetMachine() {
    llvm::Triple Triple = llvm::Triple(
        !MTriple.empty() ? llvm::Triple::normalize(MTriple)
                         : llvm::sys::getDefaultTargetTriple());

    llvm::TargetOptions TargetOptions = 
        codegen::InitTargetOptionsFromCodeGenFlags(Triple);
    std::string CPUStr = codegen::getCPUStr();
    std::string FeatureStr = codegen::getFeaturesStr();

    std::string Error;
    const llvm::Target *Target = llvm::TargetRegistry::lookupTarget(
        codegen::getMArch(), Triple, Error);

    if (!Target) {
        llvm::WithColor::error(llvm::errs()) << Error;
        return nullptr;
    }

    llvm::TargetMachine *TM = Target->createTargetMachine(
        Triple.getTriple(), CPUStr, FeatureStr,
        TargetOptions,
        llvm::Optional<llvm::Reloc::Model>(
            codegen::getRelocModel()));
    return TM;
}

std::string outputFilename(StringRef InputFilename) {
    CodeGenFileType FileType = codegen::getFileType();
    std::string OutputFilename;
    if (InputFilename == "-") {
        return "-";
    } 
    if (InputFilename.endswith(".wpl")) {
        OutputFilename = InputFilename.drop_back(4).str();
    } else {
        OutputFilename = InputFilename.str();
    }

    switch(FileType) {
    case CGFT_AssemblyFile:
        OutputFilename.append(EmitLLVM ? ".ll" : ".s");
        break;
    case CGFT_ObjectFile:
        OutputFilename.append(".o");
        break;
    case CGFT_Null:
        OutputFilename.append(".null");
        break;
    }
    return OutputFilename; 
}

#define HANDLE_EXTENSION(Ext) llvm::PassPluginLibraryInfo get##Ext##PluginInfo();
#include "llvm/Support/Extension.def"

bool emit(llvm::Module *M, llvm::TargetMachine *TM, StringRef InputFilename) {
    PassBuilder PB(TM);

    for (auto &PluginFN : PassPlugins) {
        auto PassPlugin = PassPlugin::Load(PluginFN);
        if (!PassPlugin) {
            WithColor::error(errs()) << "Failed to load passes from '"
                << PluginFN << "'. Request ignored.\n";
            continue;
        }
        PassPlugin->registerPassBuilderCallbacks(PB);
    }
/*
#define HANDLE_EXTENSION(Ext) get##Ext##PluginInfo().RegisterPassBuilderCallbacks(PB);
#include "llvm/Support/Extension.def"
*/
    LoopAnalysisManager LAM(DebugPM);
    FunctionAnalysisManager FAM(DebugPM);
    CGSCCAnalysisManager CGAM(DebugPM);
    ModuleAnalysisManager MAM(DebugPM);

    // Register the AA manager first so that our version is the one used.
    FAM.registerPass(
        [&] { return PB.buildDefaultAAPipeline(); });
    // Register all the basic analysis with the managers.
    PB.registerModuleAnalyses(MAM);
    PB.registerCGSCCAnalyses(CGAM);
    PB.registerFunctionAnalyses(FAM);
    PB.registerLoopAnalyses(LAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);

    PB.registerPipelineStartEPCallback(
        [&PB] (ModulePassManager &PM, PassBuilder::OptimizationLevel Level) {
          if (auto Err = PB.parsePassPipeline(PM, PipelineStartEPPipeline)) {
            WithColor::error(errs())
                << "Could not parse pipeline "
                << PipelineStartEPPipeline.ArgStr << ": "
                << toString(std::move(Err)) << "\n";
          }
        });

    ModulePassManager MPM(DebugPM);

    if (!PassPipeline.empty()) {
        if (auto Err = PB.parsePassPipeline(MPM, PassPipeline)) {
            WithColor::error(errs()) << toString(std::move(Err)) << "\n";
            return false;
        }
    } else {
        StringRef DefaultPass;
        switch (OptLevel) {
        case 0: DefaultPass = "default<O0>"; break;
        case 1: DefaultPass = "default<O1>"; break;
        case 2: DefaultPass = "default<O2>"; break;
        case 3: DefaultPass = "default<O3>"; break;
        case -1: DefaultPass = "default<Os>"; break;
        case -2: DefaultPass = "default<Oz>"; break;
        }
        if (auto Err = PB.parsePassPipeline(MPM, DefaultPass)) {
            WithColor::error(errs()) << toString(std::move(Err)) << "\n";
            return false;
        }
    }

    std::error_code EC;
    sys::fs::OpenFlags OpenFlags = sys::fs::OF_None;
    CodeGenFileType FileType = codegen::getFileType();
    if (FileType == CGFT_AssemblyFile) {
        OpenFlags |= sys::fs::OF_Text;
    }




    auto Out = std::make_unique<llvm::ToolOutputFile>(outputFilename(InputFilename), EC, OpenFlags);
    if (EC) {
        WithColor::error(errs()) << EC.message() << "\n";
        return false;
    }

    legacy::PassManager CodeGenPM;
    CodeGenPM.add(createTargetTransformInfoWrapperPass(TM->getTargetIRAnalysis()));
    if (FileType == CGFT_AssemblyFile && EmitLLVM) {
        CodeGenPM.add(createPrintModulePass(Out->os()));
    } else {
        if (TM->addPassesToEmitFile(CodeGenPM, Out->os(), nullptr, FileType)) {
            WithColor::error() << "No support for file type\n";
            return false;
        }
    }
    MPM.run(*M, MAM);
    CodeGenPM.run(*M);
    Out->keep();
    return true;
}
// passes end 

int main(int argc, char** argv) {
    llvm::InitLLVM X(argc, argv);

    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmPrinters();
    InitializeAllAsmParsers();

    llvm::cl::SetVersionPrinter(&printVersion);

    // Commandline handling from the llvm::cl classes.
    llvm::cl::HideUnrelatedOptions(WPLOptions);
    llvm::cl::ParseCommandLineOptions(argc, argv, Head);
    /*
    if (codegen::getMCPU() == "help" ||
        std::any_of(codegen::getMAttrs().begin(),
                    codegen::getMAttrs().end(),
                    [](const std::string &a) {
                        return a == "help";
                    })) {
        auto Triple = llvm::Triple(LLVM_DEFAULT_TARGET_TRIPLE);
        std::string ErrMsg;
        auto target = llvm::TargetRegistry::lookupTarget(Triple.getTriple(), ErrMsg);
        if (target) {
            llvm::errs() << "Targeting " << target->getName() << ". ";
            // prints the available CPUs and features of the target to stderr.
            target->createMCSubtargetInfo(Triple.getTriple(),
                                          codegen::getCPUStr(),
                                          codegen::getFeaturesStr());
        } else {
            llvm::errs() << ErrMsg << "\n";
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    llvm::TargetMachine *TM = createTargetMachine();
    if (!TM) {
        exit(EXIT_FAILURE);
    }
    */

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
    // std::cout << stm->toString() << std::endl;
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

    // todo: optimization passes
    llvm::Module *M = cv->getModule();
    //emit(M, TM, outputFileName);
    if (printOutput) {
        cv->modPrint();
    }

    if (!noCode) {
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
        llvm::Module* module = cv->getModule();
        module->print(irFileStream, nullptr);
        irFileStream.flush();
    }
    return 0;
}

