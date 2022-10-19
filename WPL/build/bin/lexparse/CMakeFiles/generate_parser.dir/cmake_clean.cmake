file(REMOVE_RECURSE
  "("
  ")"
  "../../../src/generated/CalculatorLexer.cpp"
  "../../../src/generated/CalculatorLexer.h"
  "../../../src/generated/CalculatorParser.cpp"
  "../../../src/generated/CalculatorParser.h"
  "../../../src/lexparse/parser_sources.h"
  "CMakeFiles/generate_parser"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/generate_parser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
