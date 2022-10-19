# sandbox listfile
include (ANTLR)
include (Utility)
include (Symbol)
include (Semantic)


find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include(AddLLVM)
include(HandleLLVMOptions)

add_executable(hello hello.cpp)
target_include_directories(hello PUBLIC 
  # ${ANTLR_INCLUDE}
  # ${ANTLR_GENERATED_DIR}
  # ${SYMBOL_INCLUDE}
  # ${SEMANTIC_INCLUDE}
  # ${UTILITY_INCLUDE}
  # ${CODEGEN_INCLUDE} 
  ${LLVM_BINARY_DIR}/include
  ${LLVM_INCLUDE_DIR}
  # ${LLVM_INCLUDE_DIR}/include/ExecutionEngine
)
Target_link_libraries(hello 
  LLVMCore
)

# add_executable(sandbox sandbox.cpp)

# target_include_directories(sandbox PUBLIC 
# ${ANTLR_INCLUDE}
# ${ANTLR_GENERATED_DIR}
# ${SYMBOL_INCLUDE}
# ${SEMANTIC_INCLUDE}
# ${UTILITY_INCLUDE}
# ${CODEGEN_INCLUDE} 
# ${LLVM_BINARY_DIR}/include
# ${LLVM_INCLUDE_DIR}
# )

# target_link_libraries(sandbox ${ANTLR_RUNTIME_LIB})
# target_link_libraries(sandbox lexparse_lib)
# target_link_libraries(sandbox sym_lib)
# target_link_libraries(sandbox semantic_lib)
# Target_link_libraries(sandbox LLVMCore)