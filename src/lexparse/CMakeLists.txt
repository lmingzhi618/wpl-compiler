# lexparse listfile
#
# Create the lexer and parser sources
#include(ANTLR)

# Add all generated ANTLR sources we care about here
SET(ANTLR_SOURCES
  ${GENERATED_SOURCE_DIR}/WPLLexer.cpp
  ${GENERATED_SOURCE_DIR}/WPLLexer.h
  ${GENERATED_SOURCE_DIR}/WPLParser.cpp 
  ${GENERATED_SOURCE_DIR}/WPLParser.h
)

add_custom_command(
  OUTPUT(
    ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
  )
  BYPRODUCTS ${ANTLR_SOURCES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND /bin/sh  generate.sh WPL  # Change this if you have a different script
)

add_custom_target(generate_parser ALL
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
)

add_library(parser_lib OBJECT
  ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
  ${ANTLR_SOURCES}
)

target_include_directories(parser_lib PUBLIC ${ANTLR_INCLUDE})

add_library(lexparse_lib
    ${ANTLR_SOURCES}
)

add_dependencies(lexparse_lib parser_lib)
target_include_directories(lexparse_lib PUBLIC ${ANTLR_INCLUDE})
