# symbol listfile
#
include (Symbol)
include (LLVM)
include (Semantic)
include (ANTLR)
include (Utility) 

add_library(sym_lib OBJECT 
    ${SYMBOL_SOURCES}
)

add_dependencies(sym_lib
    parser_lib
    utility_lib
    semantic_lib
)

include_directories(sym_lib
    ${ANTLR_INCLUDE}
    ${ANTLR_GENERATED_DIR}
    ${SEMANTIC_INCLUDE}
    ${UTILITY_INCLUDE}
    ${SYMBOL_INCLUDE}
)
