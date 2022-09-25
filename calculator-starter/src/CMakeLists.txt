# src listfile
include (ANTLR)
include (Utility)
add_subdirectory(lexparse)
add_subdirectory(symbol)
add_subdirectory(semantic)
add_subdirectory(utility)


add_executable(calculator calculator.cpp)


target_include_directories(calculator PUBLIC 
    ${ANTLR_INCLUDE} 
    ${GENERATED_SOURCE_DIR}
    ${SYMBOL_INCLUDE}
    ${SEMANTIC_INCLUDE}
    ${UTILITY_INCLUDE}
)

target_link_libraries(calculator ${ANTLR_RUNTIME_LIB})
target_link_libraries(calculator parser_lib)
target_link_libraries(calculator sym_lib)
target_link_libraries(calculator semantic_lib)
target_link_libraries(utility_lib)
