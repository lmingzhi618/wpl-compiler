#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/InlineCost.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/ProfileSummaryInfo.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/InitializePasses.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/IPO/Inliner.h"

using namespace llvm;

namespace {

class MyInliner : public LegacyInlinerBase {
public:
    MyInliner() : LegacyInlinerBase(ID, /*InsertLifetime*/ true) {
        //initializeMyInlinerPass(*PassRegistry::getPassRegistry());
    }

    MyInliner(bool InsertLifetime) : LegacyInlinerBase(ID, InsertLifetime) {
        //initializeMyInlinerPass(*PassRegistry::getPassRegistry());
    }

    static char ID;

    InlineCost getInlineCost(CallBase &CB) override;

    void getAnalysisUsage(AnalysisUsage &AU) const override;
    bool runOnSCC(CallGraphSCC &SCC) override;

    using llvm::Pass::doFinalization;
    bool doFinalization(CallGraph &CG) override {
        return removeDeadFunctions(CG, /*AlwaysInlineOnly=*/ true);
    }
};
}

char MyInliner::ID = 0;
/*
INITIALIZE_PASS_BEGIN(MyInliner, "my-inline",
                      "Inliner for always_inline functions", false, false);
INITIALIZE_PASS_DEPENDENCY(AssumptionCacheTracker)
INITIALIZE_PASS_DEPENDENCY(CallGraphWrapperPass)
INITIALIZE_PASS_DEPENDENCY(ProfileSummaryInfoWrapperPass)
INITIALIZE_PASS_DEPENDENCY(TargetLibraryInfoWrapperPass)
INITIALIZE_PASS_END(MyInliner, "my-inline",
                      "Inliner for always_inline functions", false, false);
Pass *llvm::createMyInlinerPass() { return new MyInliner(); }

Pass *llvm::createMyInlinerPass(bool InsertLifetime) {
    return new MyInliner(InsertLifetime);
}
*/


InlineCost MyInliner::getInlineCost(CallBase &CB) {
    Function *Callee = CB.getCalledFunction();
    if (!Callee) {
        return InlineCost::getNever("indicrect call");
    }

    if (!Callee->isDeclaration()) {
        return InlineCost::getNever("no definition");
    }
    
    if (!CB.hasFnAttr(Attribute::AlwaysInline)) {
        return InlineCost::getNever("no alwaysinline attribute");
    }

    auto IsViable = isInlineViable(*Callee);
    if (!IsViable.isSuccess()) {
        return InlineCost::getNever(IsViable.getFailureReason());
    }

    return InlineCost::getAlways("always inliner");
}

bool MyInliner::runOnSCC(CallGraphSCC &SCC) {
    return inlineCalls(SCC);
}

void MyInliner::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.addRequired<AssumptionCacheTracker>();
    AU.addRequired<ProfileSummaryInfoWrapperPass>();
    AU.addRequired<TargetLibraryInfoWrapperPass>();
    getAAResultsAnalysisUsage(AU);
    LegacyInlinerBase::getAnalysisUsage(AU);
}

