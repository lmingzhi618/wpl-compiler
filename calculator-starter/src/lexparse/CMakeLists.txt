# lexparse listfile
#
# Create the lexer and parser sources

# Add all generated ANTLR sources we care about here
SET(ANTLR_SOURCES
  ${GENERATED_SOURCE_DIR}/CalculatorLexer.cpp
  ${GENERATED_SOURCE_DIR}/CalculatorLexer.h
  ${GENERATED_SOURCE_DIR}/CalculatorParser.cpp 
  ${GENERATED_SOURCE_DIR}/CalculatorParser.h
)

add_custom_command(
  OUTPUT(
    ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
  )
  BYPRODUCTS ${ANTLR_SOURCES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND /bin/sh  generate.sh Calculator  # Change this if you have a different script
)

add_custom_target(generate_parser ALL
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
)

add_library(parser_lib OBJECT
  ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
  ${ANTLR_SOURCES}
)

target_include_directories(parser_lib PUBLIC ${ANTLR_INCLUDE})