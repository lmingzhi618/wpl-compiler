# Test CMakeLists.txt file
#
include(Testing)
include(ANTLR)
include (Symbol)
include (Semantic)
include (Utility)
include(Codegen)
include(LLVM)

find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in ${LLVM_DIR}")

#include(AddLLVM)
#include(HandleLLVMOptions)

include(cmake/LexParseTests.cmake)
include(cmake/SymbolTests.cmake)
#include(cmake/SemanticTests.cmake)
#include(cmake/CodegenTests.cmake)

### Set up all tests to be run
add_executable(
  tests
  ${LEXPARSE_TESTS}
# ${SYMBOL_TESTS}
# ${SEMANTIC_TESTS}
# ${CODEGEN_TESTS}
)

add_dependencies(tests 
    parser_lib 
    sym_lib
    semantic_lib
    utility_lib
    codegen_lib
)

target_include_directories(tests PUBLIC
    ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR}
    ${SYMBOL_INCLUDE}
    ${SEMANTIC_INCLUDE}
    ${UTILITY_INCLUDE}
    ${CODEGEN_INCLUDE}
    ${LLVM_BINARY_DIR}/include
    ${LLVM_INCLUDE_DIR}
)

message(STATUS "===|> ANTLR_RUNTIME_LIB: ${ANTLR_RUNTIME_LIB}")

target_link_libraries(tests
    PRIVATE
    ${ANTLR_RUNTIME_LIB}
    parser_lib
    sym_lib
    semantic_lib
    utility_lib
    codegen_lib
    ${LLVM_LIBS}
    Catch2::Catch2WithMain
)

# Get the tests registered with CTest
catch_discover_tests(tests)

