file(REMOVE_RECURSE
  "("
  ")"
  "../../../src/generated/WPLLexer.cpp"
  "../../../src/generated/WPLLexer.h"
  "../../../src/generated/WPLParser.cpp"
  "../../../src/generated/WPLParser.h"
  "../../../src/lexparse/parser_sources.h"
  "CMakeFiles/generate_parser"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/generate_parser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
