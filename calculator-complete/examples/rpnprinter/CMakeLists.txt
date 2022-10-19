# examples listfile
include (ANTLR)

add_executable(rpnprinter 
  rpnprinter.cpp
  RPNVisitor.cpp)


target_include_directories(rpnprinter PUBLIC ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR})

target_link_libraries(rpnprinter ${ANTLR_RUNTIME_LIB})
target_link_libraries(rpnprinter parser_lib)