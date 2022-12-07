#include "llvm/Transforms/Scalar.h"
#include "llvm/ADT/DepthFirstIterator.h"
#include "llvm/ADT/SmallSet.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/InitializePasses.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {

struct MYADCE : public FunctionPass {
    static char ID;     // Pass identification, replacement for typeid
    MYADCE() : FunctionPass(ID) {
        //initializeMYADCEPass(*PassRegistry::getPassRegistry());
    }

    bool runOnFunction(Function& F) override;

    void getAnalysisUsage(AnalysisUsage& AU) const override {
        AU.setPreservesCFG();
    }
};

} // end anonymous namespace

char MYADCE::ID = 0;

//INITIALIZE_PASS(MYADCE, "myadce", "Aggressive Dead Code Elimination", false, false)

bool MYADCE::runOnFunction(Function& F) {
    if (skipFunction(F)) {
        return false;
    }

    DenseSet<Instruction*> Alive;
    SmallVector<Instruction*, 128> Worklist;

    // Collect the set of "root" instructions that are known live.
    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (I.isTerminator() || isa<DbgInfoIntrinsic>(I) ||
                isa<LandingPadInst>(I) || I.mayHaveSideEffects()) {
                Alive.insert(&I);
                Worklist.push_back(&I);
            }
        }
    }

    // Propagate liveness backwards to operands.
    while (!Worklist.empty()) {
        Instruction *Cur = Worklist.pop_back_val();
        for (Use &OI : Cur->operands()) {
            if (Instruction *Inst = dyn_cast<Instruction>(OI)) {
                if (Alive.insert(Inst).second) {
                    Worklist.push_back(Inst);
                }
            }
        }
    }

    // The instructions which are not in live set are considered dead in this pass.
    // The Instructoins which do not effect the control flow, return value, or do not
    // have any side effects are hence deleted.
    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (!Alive.count(&I)) {
                Worklist.push_back(&I);
                I.dropAllReferences();
            }
        }
    } 
    for (Instruction *&I : Worklist) {
        I->eraseFromParent();
    }
    return !Worklist.empty();
}

//FunctionPass *llvm::createMYAggressiveDCEPass() {
//    return new MYADCE();
//}

