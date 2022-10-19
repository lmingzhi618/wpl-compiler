/**
 * @file hello.cpp
 * @author Tim Morgan
 * @brief Hello world in LLVM
 * @see https://gist.github.com/seven1m/2ca74265cca9ef6f493ef1de87e9252d
 */
// % clang++ $(llvm-config --cxxflags --ldflags --system-libs --libs core) -o hello_world_llvm hello_world_llvm.cpp
// % ./hello_world_llvm
// hello world

// #include <llvm/ExecutionEngine/ExecutionEngine.h>
// #include <llvm/ExecutionEngine/GenericValue.h>
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include <llvm/IR/IRBuilder.h>
#include <stdio.h>

using namespace llvm;

int main() {
    auto context = std::make_unique<LLVMContext>();
    IRBuilder<> builder(*context);

    auto module = std::make_unique<Module>("hello", *context);

    // build a 'main' function
    auto i32 = builder.getInt32Ty();
    auto prototype = FunctionType::get(i32, false);
    Function *main_fn = Function::Create(prototype, Function::ExternalLinkage, "main", module.get());
    BasicBlock *body = BasicBlock::Create(*context, "body", main_fn);
    builder.SetInsertPoint(body);

    // use libc's printf function
    auto i8p = builder.getInt8PtrTy();
    auto printf_prototype = FunctionType::get(i8p, true);
    auto printf_fn = Function::Create(printf_prototype, Function::ExternalLinkage, "printf", module.get());

    // call printf with our string
    auto format_str = builder.CreateGlobalStringPtr("hello world\n");
    builder.CreateCall(printf_fn, { format_str });

    // return 0 from main
    auto ret = ConstantInt::get(i32, 0);
    builder.CreateRet(ret);

    // if you want to print the LLVM IR:
    //module->print(llvm::outs(), nullptr);

    // // execute it!
    // ExecutionEngine *executionEngine = EngineBuilder(std::move(module)).setEngineKind(llvm::EngineKind::Interpreter).create();
    // Function *main = executionEngine->FindFunctionNamed(StringRef("main"));
    // auto result = executionEngine->runFunction(main, {});

    // // return the result
    // return result.IntVal.getLimitedValue();
    std::error_code ec;
    llvm::raw_fd_ostream irFileStream("hello.ll", ec);
    module->print(irFileStream, nullptr);
    irFileStream.flush();
    return 0;
}