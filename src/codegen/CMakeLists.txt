include (Semantic)
include (Symbol)
include (ANTLR)
include (Utility)
include (Codegen)
include (LLVM)

find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include (AddLLVM)
include (HandleLLVMOptions)

add_library(codegen_lib OBJECT 
    ${CODEGEN_SOURCES}
)

add_dependencies(codegen_lib
   parser_lib
   utility_lib
   semantic_lib
)

include_directories(codegen_lib
    ${ANTLR_INCLUDE}
    ${ANTLR_GENERATED_DIR}
    ${SYMBOL_INCLUDE}
    ${SEMANTIC_INCLUDE}
    ${UTILITY_INCLUDE}
    ${CODEGEN_INCLUDE}
    ${LLVM_BINARY_DIR}/include
    ${LLVM_INCLUDE_DIR}
)
