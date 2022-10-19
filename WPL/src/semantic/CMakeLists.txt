# semantic listfile

include (Semantic)
include (Symbol)
include (ANTLR)
include (Utility) 

add_library(semantic_lib OBJECT 
    ${SEMANTIC_SOURCES}
)

add_dependencies(semantic_lib
    parser_lib
)

include_directories(semantic_lib
    ${ANTLR_INCLUDE}
    ${ANTLR_GENERATED_DIR}
    ${SYMBOL_INCLUDE}
    ${SEMANTIC_INCLUDE}
    ${UTILITY_INCLUDE}
)


