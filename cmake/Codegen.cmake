# Symbol component module

set (CODEGEN_DIR ${CMAKE_SOURCE_DIR}/src/codegen)
set (CODEGEN_INCLUDE ${CODEGEN_DIR}/include)

set (CODEGEN_SOURCES
    ${CODEGEN_DIR}/CodegenVisitor.cpp
    ${CODEGEN_DIR}/MyADCE.cpp
    ${CODEGEN_DIR}/MyInliner.cpp
)
