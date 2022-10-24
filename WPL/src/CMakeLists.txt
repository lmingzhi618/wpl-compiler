# src listfile
include (ANTLR)
include (Utility)
include (Semantic)
include (Symbol)
include (Codegen)
include (LLVM)
include (Runtime)

find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

include(AddLLVM)
include(HandleLLVMOptions)


add_subdirectory(lexparse)
add_subdirectory(symbol)
add_subdirectory(semantic)
add_subdirectory(utility)
add_subdirectory(codegen)
add_subdirectory(runtime)


add_executable(wplc wpl.cpp)

add_dependencies(wplc
    utility_lib
    parser_lib
    semantic_lib
    sym_lib
    codegen_lib
    wpl_runtime
)

target_include_directories(wplc PUBLIC 
    ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR}
    ${SYMBOL_INCLUDE}
    ${SEMANTIC_INCLUDE}
    ${UTILITY_INCLUDE}
    ${CODEGEN_INCLUDE}
    ${LLVM_BINARY_DIR}/include
    ${LLVM_INCLUDE_DIR}
)

target_link_libraries(wplc 
    PRIVATE
    ${ANTLR_RUNTIME_LIB}
    parser_lib
    sym_lib
    semantic_lib
    utility_lib
    codegen_lib
    ${LLVM_LIBS}
)
