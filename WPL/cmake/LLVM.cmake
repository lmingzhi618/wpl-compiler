set(LLVM_DIR /lib/llvm-12/)
set(LLVM_INCLUDE_DIR "{LLVM_DIR}/include")
set(support_plugins SUPPORT_PLUGINS)

llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD}
    AggressiveInstCombine
    Analysis
    AsmParser
    BitWriter
    CodeGen
    Core
    Coroutines
    ipo
    IRReader
    InstCombine
    Instrumentation
    MC
    MCJIT
    ObjCARCOpts
    Remarks
    ScalarOpts
    Support
    Target
    TransformUtils
    Vectorize
    Passes
)
