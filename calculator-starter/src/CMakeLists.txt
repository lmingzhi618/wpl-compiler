# src listfile
include (cmake/antlr.cmake)
add_subdirectory(lexparse)

add_executable(calculator calculator.cpp)


target_include_directories(calculator PUBLIC ${ANTLR_INCLUDE} ${GENERATED_SOURCE_DIR})

target_link_libraries(calculator ${ANTLR_RUNTIME_LIB})
target_link_libraries(calculator parser_lib)