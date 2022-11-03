#include "CodegenVisitor.h"
#include <llvm-12/llvm/ADT/StringExtras.h>
#include <llvm-12/llvm/Support/MathExtras.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/DerivedTypes.h>
#include <stdio.h>

#include <any>
#include <string>

using namespace llvm;

void trace(std::string message, Value *v = nullptr) {
#ifndef _TRACE_
    std::cout << message;
    if (v != nullptr) {
        std::cout.flush();
        v->print(llvm::outs());
    }
    std::cout << std::endl;
#endif
}

static std::vector<std::string> FunArgs;

Value *CodegenVisitor::createArith(IRBuilder<> &Builder, Value *L, Value *R) {
    return Builder.CreateMul(L, R, "multmp");
}

void CodegenVisitor::setFuncArgs(Function *fooFunc,
                                 std::vector<std::string> funArgs) {
    unsigned idx = 0;
    Function::arg_iterator AI, AE;
    for (AI = fooFunc->arg_begin(), AE = fooFunc->arg_end(); AI != AE;
         ++AI, ++idx) {
        AI->setName(funArgs[idx]);
    }
}

BasicBlock *CodegenVisitor::createBB(Function *func, std::string name) {
    return BasicBlock::Create(*context, name, func);
}

GlobalVariable *CodegenVisitor::createGlob(Type *type, std::string name) {
    M->getOrInsertGlobal(name, type);
    GlobalVariable *gVar = M->getNamedGlobal(name);
    gVar->setLinkage(GlobalValue::CommonLinkage);
    gVar->setAlignment(MaybeAlign(4));
    return gVar;
}

Value *CodegenVisitor::createIfElse(IRBuilder<> &Builder, BBList List,
                                    VarList VL) {
    Value *Condtn = VL[0];
    Value *Arg1 = VL[1];
    BasicBlock *ThenBB = List[0];
    BasicBlock *ElseBB = List[1];
    BasicBlock *MergeBB = List[2];
    Builder.CreateCondBr(Condtn, ThenBB, ElseBB);

    Builder.SetInsertPoint(ThenBB);
    Value *ThenVal = Builder.CreateAdd(Arg1, Builder.getInt32(1), "thenaddtmp");
    Builder.CreateBr(MergeBB);

    Builder.SetInsertPoint(ElseBB);
    Value *ElseVal = Builder.CreateAdd(Arg1, Builder.getInt32(2), "elseaddtmp");
    Builder.CreateBr(MergeBB);

    unsigned PhiBBSize = List.size() - 1;
    Builder.SetInsertPoint(MergeBB);
    PHINode *Phi =
        Builder.CreatePHI(Type::getInt32Ty(*context), PhiBBSize, "iftmp");
    Phi->addIncoming(ThenVal, ThenBB);
    Phi->addIncoming(ElseVal, ElseBB);
    return Phi;
}

std::any CodegenVisitor::visitVarDeclaration(
    WPLParser::VarDeclarationContext *ctx) {
    if (ctx->scalarDeclaration()) {
        return ctx->scalarDeclaration()->accept(this);
    }
    if (ctx->arrayDeclaration()) {
        return ctx->arrayDeclaration()->accept(this);
    }
    return nullptr;
}

std::any CodegenVisitor::visitVarInitializer(
    WPLParser::VarInitializerContext *ctx) {
    return ctx->c->accept(this);
}

Function *CodegenVisitor::createFunc(FunctionType *ft, std::string name) {
    return Function::Create(ft, GlobalValue::ExternalLinkage, name, M);
}

std::any CodegenVisitor::visitFunction(WPLParser::FunctionContext *ctx) {
    auto fn = std::any_cast<Function*>(ctx->funcHeader()->accept(this));
    funcMap[ctx] = fn;
    return ctx->block()->accept(this);
}

std::any CodegenVisitor::visitFuncHeader(WPLParser::FuncHeaderContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("Function symbol not found!");
        exit(-1);
    }
    std::vector<Type *> args_type;
    std::vector<std::string> args_name;
    if (symbol->params) {
        for (auto param : *(symbol->params)) {
            args_type.push_back(getLLVMType(param->baseType));
            args_name.push_back(param->id);
        }
    }
    auto retType = getLLVMType(symbol->baseType);
    auto *funcType = FunctionType::get(retType, args_type, false);
    auto func = createFunc(funcType, symbol->id);
    setFuncArgs(func, args_name);

    symbol->defined = true;
    symbol->val = func;
    return func;
}


std::any CodegenVisitor::visitProcedure(WPLParser::ProcedureContext *ctx) {
    auto fn = std::any_cast<Function*>(ctx->procHeader()->accept(this));
    funcMap[ctx] = fn;
    return ctx->block()->accept(this);
}
 
std::any CodegenVisitor::visitProcHeader(WPLParser::ProcHeaderContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("Procedure symbol not found!");
        exit(-1);
    }
    std::vector<Type *> args_type;
    std::vector<std::string> args_name;
    if (symbol->params) {
        for (auto param : *(symbol->params)) {
            args_type.push_back(getLLVMType(param->baseType));
            args_name.push_back(param->id);
        }
    }
    auto *funcType = FunctionType::get(builder->getVoidTy(), args_type, false);
    auto func = createFunc(funcType, symbol->id);
    setFuncArgs(func, args_name);

    symbol->defined = true;
    symbol->val = func;
    return func;
}
 
std::any CodegenVisitor::visitBlock(WPLParser::BlockContext *ctx) {
    std::string fn("CodegenVisitor::visitBlock");
    auto func = getParentFunc(ctx);
    builder->SetInsertPoint(createBB(func, ""));
    // alloca and save parameters of functions
   	if(dynamic_cast<WPLParser::FunctionContext *>(ctx->parent) || 
	   dynamic_cast<WPLParser::ProcedureContext *>(ctx->parent)) {
        Function::arg_iterator AI, AE;
        for (AI = func->arg_begin(), AE = func->arg_end(); AI != AE; ++AI) {
            Value* alloca = builder->CreateAlloca(AI->getType(), nullptr,AI->getName());
    		builder->CreateStore(AI, alloca);
            paramMap[AI] = alloca;
    	}
	}
    return visitChildren(ctx);
}

std::any CodegenVisitor::visitReturn(WPLParser::ReturnContext *ctx) {
    auto retVal = std::any_cast<Value *>(ctx->expr()->accept(this));
    builder->CreateRet(retVal);
    return retVal;
}

std::any CodegenVisitor::visitScalar(WPLParser::ScalarContext *ctx) {
    std::string fn("CodegenVisitor::visitScalar ");
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace(fn + "NULLPTR");
        exit(-1);
    }

    Value *alloca = nullptr;
    auto type = getLLVMType(symbol->baseType);

    Value *val = nullptr;
    if (ctx->varInitializer()) {
        val = std::any_cast<Value *>(ctx->varInitializer()->accept(this));
    }

    if (isGlobal(ctx)) {
        alloca = M->getOrInsertGlobal(symbol->id, type);
        auto gVar = M->getNamedGlobal(symbol->id);
        gVar->setLinkage(GlobalValue::CommonLinkage);
        gVar->setAlignment(MaybeAlign(4));
        if (val) {
            static_cast<GlobalVariable *>(alloca)->setInitializer(
                static_cast<Constant *>(val));
        }
    } else {
        alloca = builder->CreateAlloca(type, nullptr, symbol->id);
        if (val) {
            builder->CreateStore(val, alloca);
        }
    }
    symbol->defined = true;
    symbol->val = alloca;
    return alloca;
}

std::any CodegenVisitor::visitAssignment(WPLParser::AssignmentContext *ctx) {
    std::string fn("[CodegenVisitor::visitAssignment] ");
	Value *exVal = std::any_cast<Value *>(ctx->e->accept(this));
    if (ctx->target) {
        Symbol *symbol = props->getBinding(ctx);  // child variable symbol
        if (symbol == nullptr) {
            trace(fn + "symbol not found: " + ctx->ID()->getText());
            exit(-1);
        }
        if (symbol->val == nullptr) {
            // check function parameters
            auto func = getParentFunc(ctx);
            if (func) {
                Function::arg_iterator it;
                for (it = func->arg_begin(); it != func->arg_end(); it++) {
                    if (it->getName() == symbol->id) {
                        //symbol->val = it;
						// symbol->val = builder->CreateLoad(it->getType(), it);
                        if (paramMap.count(it)) {
                            symbol->val = builder->CreateLoad(it->getType(), paramMap[it]);
                        }
	    				break;
                    }
                }
            } 
        }
	    if (symbol->val == nullptr) {
            std::cerr << "Variable " << symbol->id << " not declared..." << std::endl;
            exit(-1);
        }
        builder->CreateStore(exVal, symbol->val);
    } else {
        Symbol *symbol = props->getBinding(ctx->arrayIndex());  // child variable symbol
        if (symbol == nullptr) {
            trace(fn + "NULLPTR");
            exit(-1);
        }

        Value *Idx = std::any_cast<Value *>(ctx->arrayIndex()->accept(this));
        builder->CreateInsertElement(symbol->val, exVal, Idx);
    }
    return exVal;
}

std::any CodegenVisitor::visitArrayIndex(WPLParser::ArrayIndexContext *ctx) {
    std::string fn("[CodegenVisitor::visitArrayIndex] ");
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace(fn + "symbol not found");
        exit(-1);
    }
    if (symbol->val == nullptr ){
        trace(fn + "symbol not defined");
        exit(-1);
    }

    Value * Idx = std::any_cast<Value *>(ctx->expr()->accept(this));
    if (nullptr == Idx) {
        trace(fn + "index of array should not be null...");
        exit(-1);
    }

    return builder->CreateExtractElement(symbol->val, Idx);
} 

std::any CodegenVisitor::visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx) {
    std::string fn("CodegenVisitor::visitArrayLengthExpr");
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace(fn + "symbol not found");
        exit(-1);
    }
    return (Value *)builder->getInt32(symbol->length);
}

/*
std::any CodegenVisitor::visitExternFuncHeader(
    WPLParser::ExternFuncHeaderContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("Function symbol is null!");
        exit(-1);
    }
    std::vector<Type *> args_type;
    std::vector<std::string> args_name;
    // TO DO LIST: ELLIPSIS
    if (symbol->params) {
        for (auto param : *(symbol->params)) {
            args_type.push_back(getLLVMType(param->baseType));
            args_name.push_back(param->id);
        }
    }
    auto retType = getLLVMType(symbol->baseType);
    auto *ft = FunctionType::get(retType, args_type, false);
    auto fn = createFunc(ft, symbol->id);
    setFuncArgs(fn, args_name);
    symbol->defined = true;
    symbol->val = fn;
    return fn;
}
*/



// std::any visitConstExpr(WPLParser::ConstExprContext *ctx) override;
std::any CodegenVisitor::visitConstant(WPLParser::ConstantContext *ctx) {
    Value *v;
    if (ctx->b) {
        if (ctx->b->getText() == "true") {
            v = builder->getInt1(1);
        } else {
            v = builder->getInt1(0);
        }
    } else if (ctx->i) {
        v = builder->getInt32(std::stoi(ctx->i->getText()));
    } else {
        StringRef sr = ctx->s->getText();
        v = builder->CreateGlobalStringPtr(sr);
    }
    return v;
}

std::any CodegenVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}

std::any CodegenVisitor::visitUMinusExpr(WPLParser::UMinusExprContext *ctx) {
    Value *exVal = std::any_cast<Value *>(ctx->expr()->accept(this));
    Value *v = builder->CreateNSWSub(builder->getInt32(0), exVal);
    return v;
}

std::any CodegenVisitor::visitNotExpr(WPLParser::NotExprContext *ctx) {
    Value *v = std::any_cast<Value *>(ctx->expr()->accept(this));
    // if v == 0: return 1 
    // else : return 0
    if (v->getType()->isPointerTy()) {
        v =  builder->CreateLoad(Int32Ty, v);
    }
    Value *cond = builder->CreateICmpEQ(v, Int32Zero, "cond");
    Value * ret = builder->CreateSelect(cond, Int32One, Int32Zero); 
    return ret;
}

std::any CodegenVisitor::visitAndExpr(WPLParser::AndExprContext *ctx) {
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    lVal = builder->CreateLoad(Int32Ty, lVal);
    rVal = builder->CreateLoad(Int32Ty, rVal);
    return builder->CreateAnd(lVal, rVal);
} 

std::any CodegenVisitor::visitIDExpr(WPLParser::IDExprContext *ctx) {
    std::string fn("[CodegenVisitor::visitIDExpr] ");
    Symbol *symbol = props->getBinding(ctx);

    if (symbol == nullptr) {
        trace(fn + "symbol not found: " +  ctx->id->getText());
        exit(-1);
    }
    if (symbol->val == nullptr) {
        // check function parameters
        auto func = getParentFunc(ctx);
        if (func) {
            Function::arg_iterator it;
            for (it = func->arg_begin(); it != func->arg_end(); it++) {
                if (it->getName() == symbol->id) {
					// symbol->val = builder->CreateLoad(it->getType(), it);
                    if (paramMap.count(it)) {
                        symbol->val = builder->CreateLoad(it->getType(), paramMap[it]);
                    }
					break;
                }
            }
        } 
    }
	if (symbol->val == nullptr) {
        std::cerr << "Variable " << symbol->id << " not declared..." << std::endl;
        exit(-1);
    }

    // auto v =  builder->CreateLoad(Int32Ty, symbol->val, "load_" + symbol->id);
    // return  builder->CreateLoad(getLLVMType(symbol->baseType), symbol->val, "load_" + symbol->id);
    return symbol->val;
}


std::any CodegenVisitor::visitBinaryArithExpr(
    WPLParser::BinaryArithExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    if (lVal->getType()->isPointerTy()) {
        lVal =  builder->CreateLoad(Int32Ty, lVal);
    }
    if (rVal->getType()->isPointerTy()) {
        rVal =  builder->CreateLoad(Int32Ty, rVal);
    }
    if (ctx->PLUS()) {
        v = builder->CreateNSWAdd(lVal, rVal);
    } else if (ctx->MINUS()) {
        v = builder->CreateNSWSub(lVal, rVal);
    } else if (ctx->MUL()) {
        v = builder->CreateNSWMul(lVal, rVal);
    } else {
        v = builder->CreateSDiv(lVal, rVal);
    }
    return v;
}

std::any CodegenVisitor::visitRelExpr(WPLParser::RelExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    if (lVal->getType()->isPointerTy()) {
        lVal =  builder->CreateLoad(Int32Ty, lVal);
    }
    if (rVal->getType()->isPointerTy()) {
        rVal =  builder->CreateLoad(Int32Ty, rVal);
    }
    Value *v1;
    if (ctx->LESS()) {
        v1 = builder->CreateICmpSLT(lVal, rVal);
    } else if (ctx->LEQ()) {
        v1 = builder->CreateICmpSLE(lVal, rVal);
    } else if (ctx->GTR()) {
        v1 = builder->CreateICmpSGT(lVal, rVal);
    } else {
        v1 = builder->CreateICmpSGE(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, Int1Ty);
    return v;
}

std::any CodegenVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    if (lVal->getType()->isPointerTy()) {
        lVal =  builder->CreateLoad(Int32Ty, lVal);
    }
    if (rVal->getType()->isPointerTy()) {
        rVal =  builder->CreateLoad(Int32Ty, rVal);
    }
    Value *v1;
    if (ctx->EQUAL()) {
        v1 = builder->CreateICmpEQ(lVal, rVal);
    } else {
        v1 = builder->CreateICmpNE(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int1Ty);
    return v;
}


std::any CodegenVisitor::visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) {
    std::string fn("CodegenVisitor::visitArrayDeclaration ");
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace(fn + "NULLPTR");
        exit(-1);
    }

    Value *addr = nullptr;
    Type *type = getLLVMType(symbol->baseType);
    Type *arrayType = ArrayType::get(type, symbol->length); 
    Type *ptrTy = arrayType->getPointerTo(0);
    if (isGlobal(ctx)) {
        addr = M->getOrInsertGlobal(symbol->id, ptrTy);
        auto gVar = M->getNamedGlobal(symbol->id);
        gVar->setLinkage(GlobalValue::CommonLinkage);
        gVar->setAlignment(MaybeAlign(4));
    } else {
        addr = builder->CreateAlloca(ptrTy, nullptr, symbol->id);
    }

    symbol->defined = true;
    symbol->val = addr;
    return addr;
}

/*
cond:
    br expr == 0, after_loop, loop
loop:
    ...
    br loop 
after_loop:

*/

std::any CodegenVisitor::visitLoop(WPLParser::LoopContext *ctx) {
    std::string fn("CodegenVisitor::visitLoop");
    auto func = getParentFunc(ctx);
    BasicBlock *headerBB = createBB(func, "loop.header");
    BasicBlock *loopBB = createBB(func, "loop.body");
    BasicBlock *afterBB = createBB(func, "afterloop");

    // pre header
    builder->CreateBr(headerBB);

    // loop header 
    builder->SetInsertPoint(headerBB);
    Value *exVal = std::any_cast<Value*>(ctx->e->accept(this));
    if (exVal->getType()->isPointerTy()) {
        exVal =  builder->CreateLoad(Int1Ty, exVal);
    }
    Value *cond = builder->CreateICmpEQ(exVal, builder->getInt1(1), "endcond");
    builder->CreateCondBr(cond, loopBB, afterBB);

    // loop body
    builder->SetInsertPoint(loopBB);
    visitChildren(ctx->block()); 
    builder->CreateBr(headerBB);

    // after loop
    builder->SetInsertPoint(afterBB);

    return nullptr;
}

std::any CodegenVisitor::visitSelect(WPLParser::SelectContext *ctx)  {
    auto func = getParentFunc(ctx);
    int cn = ctx->selectAlt().size();
    std::vector<BasicBlock*> bbs;   // body blocks
    std::vector<BasicBlock*> cbs;   // condition header blocks
    for (int i = 0; i < cn; ++i) {
        cbs.push_back(createBB(func, "cond-" + std::to_string(i)));
        bbs.push_back(createBB(func, "case-" + std::to_string(i)));
    }
    BasicBlock * afterBB = createBB(func, "after");
    cbs.push_back(afterBB);
    bbs.push_back(afterBB);

    builder->CreateBr(cbs[0]);
    for (int i = 0; i < cn; ++i) {
        builder->SetInsertPoint(cbs[i]);
        Value *exVal = std::any_cast<Value*>(ctx->selectAlt(i)->e->accept(this));
        if (exVal->getType()->isPointerTy()) {
            exVal =  builder->CreateLoad(Int32Ty, exVal);
        }
        exVal = builder->CreateZExtOrTrunc(exVal, Int32Ty);
        Value *cond = builder->CreateICmpEQ(exVal, builder->getInt32(1), "cond");
        builder->CreateCondBr(cond, bbs[i], cbs[i+1]);

        builder->SetInsertPoint(bbs[i]);
        ctx->selectAlt(i)->accept(this);
        builder->CreateBr(afterBB);
    }
    builder->SetInsertPoint(afterBB);

    return nullptr;
} 
    

std::any CodegenVisitor::visitConditional(WPLParser::ConditionalContext *ctx)  {
    auto func = getParentFunc(ctx);
    BasicBlock * thenBB = createBB(func, "then");
    BasicBlock * elseBB = nullptr;
    if (ctx->block().size() > 1) {
        elseBB = createBB(func, "else");
    }
    BasicBlock * mergeBB = createBB(func, "merge");
   
    Value *exVal = std::any_cast<Value*>(ctx->e->accept(this));
    if (exVal->getType()->isPointerTy()) {
        exVal =  builder->CreateLoad(Int32Ty, exVal);
    }
    exVal = builder->CreateZExtOrTrunc(exVal, Int32Ty);
    Value *cond = builder->CreateICmpEQ(exVal, builder->getInt32(1), "cond");
   
    builder->CreateCondBr(cond, thenBB, (elseBB ? elseBB : mergeBB));

    // then block
    builder->SetInsertPoint(thenBB);
    visitChildren(ctx->block(0));
    builder->CreateBr(mergeBB);
   
    // else block
    if (elseBB) {
        builder->SetInsertPoint(elseBB);
        visitChildren(ctx->block(1));
        builder->CreateBr(mergeBB);
    }

    // merge if-else block
    builder->SetInsertPoint(mergeBB);
    return nullptr;
}

std::any CodegenVisitor::visitCall(WPLParser::CallContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("Function symbol is not found!");
        exit(-1);
    }
    std::vector<Value *> Args;
    for (auto arg : ctx->arguments()->arg()) {
		Value *v = std::any_cast<Value*>(arg->c->accept(this));
        Args.push_back(v);
    }
    auto func = M->getFunction(symbol->id);
    return builder->CreateCall(func, Args);
}


std::any CodegenVisitor::visitFuncCallExpr(WPLParser::FuncCallExprContext *ctx) {
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace("Function symbol is null!");
        exit(-1);
    }
    std::vector<Value *> Args;
    for (auto arg : ctx->args) {
		Value *v = std::any_cast<Value*>(arg->accept(this));
        Args.push_back(v);
    }
    auto func = M->getFunction(symbol->id);
    Value *funcCall =  builder->CreateCall(func, Args);
	return funcCall;
}
