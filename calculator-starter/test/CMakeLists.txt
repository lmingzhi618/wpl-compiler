# Test CMakeLists.txt file
#
include(Testing)
include(ANTLR)
include (Symbol)

include(cmake/LexParseTests.cmake)
include(cmake/SymbolTests.cmake)

message(STATE, "SYMBOL_TESTS: ${SYMBOL_TESTS}")
### Set up all tests to be run
add_executable(
  tests
  ${LEXPARSE_TESTS}
  ${SYMBOL_TESTS}
# ${SEMANTIC_TESTS}
)

add_dependencies(tests 
#   parser_lib 
    sym_lib
)

target_include_directories(tests PUBLIC
    ${ANTLR_INCLUDE}
    ${ANTLR_GENERATED_DIR}
    ${SYMBOL_INCLUDE}
)

target_link_libraries(tests
    PRIVATE
    ${ANTLR_RUNTIME_LIB}
    parser_lib
    sym_lib
    Catch2::Catch2WithMain
)

# Get the tests registered with CTest
catch_discover_tests(tests)

