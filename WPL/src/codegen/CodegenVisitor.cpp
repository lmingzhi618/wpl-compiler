#include "CodegenVisitor.h"
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
        if (val) {
            alloca = builder->CreateAlloca(type, val, symbol->id);
        } else {
            alloca = builder->CreateAlloca(type, nullptr, symbol->id);
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
            trace(fn + "NULLPTR");
            exit(-1);
        }
        if (symbol->val == nullptr) {
            // check function parameters
            auto func = getParentFunc(ctx);
            if (func) {
                Function::arg_iterator it;
                for (it = func->arg_begin(); it != func->arg_end(); it++) {
                    if (it->getName() == symbol->id) {
                        symbol->val = it;
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

    Value * vIdx = std::any_cast<Value *>(ctx->expr()->accept(this));
    if (nullptr == vIdx) {
        trace(fn + "index of array should not be null...");
        exit(-1);
    }
    return vIdx;
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

std::any CodegenVisitor::visitFuncCallExpr(
    WPLParser::FuncCallExprContext *ctx) {
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


std::any CodegenVisitor::visitConstant(WPLParser::ConstantContext *ctx) {
    Value *v;
    if (ctx->b) {
        if (ctx->b->getText() == "true") {
            v = builder->getInt32(1);
        } else {
            v = builder->getInt32(0);
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
    v = builder->CreateZExtOrTrunc(v, CodegenVisitor::Int1Ty);
    v = builder->CreateXor(v, Int32One);
    v = builder->CreateZExtOrTrunc(v, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitBinaryArithExpr(
    WPLParser::BinaryArithExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
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
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int32Ty);
    return v;
}

std::any CodegenVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
    Value *v = nullptr;
    Value *lVal = std::any_cast<Value *>(ctx->left->accept(this));
    Value *rVal = std::any_cast<Value *>(ctx->right->accept(this));
    Value *v1;
    if (ctx->EQUAL()) {
        v1 = builder->CreateICmpEQ(lVal, rVal);
    } else {
        v1 = builder->CreateICmpNE(lVal, rVal);
    }
    v = builder->CreateZExtOrTrunc(v1, CodegenVisitor::Int32Ty);
    return v;
}


std::any CodegenVisitor::visitIDExpr(WPLParser::IDExprContext *ctx) {
    std::string fn("[CodegenVisitor::visitIDExpr] ");
    Symbol *symbol = props->getBinding(ctx);
    if (symbol == nullptr) {
        trace(fn + "NULLPTR");
        exit(-1);
    }

    if (symbol->val == nullptr) {
        // check function parameters
        auto func = getParentFunc(ctx);
        if (func) {
            Function::arg_iterator it;
            for (it = func->arg_begin(); it != func->arg_end(); it++) {
                if (it->getName() == symbol->id) {
                    symbol->val = it;
					break;
                }
            }
        } 
    }
	if (symbol->val == nullptr) {
        std::cerr << "Variable " << symbol->id << " not declared..." << std::endl;
        exit(-1);
    }

    return symbol->val;
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
        addr = builder->CreateAlloca(ptrTy, getTypeZero(symbol->baseType), symbol->id);
    }

    symbol->defined = true;
    symbol->val = addr;
    return addr;
}


std::any CodegenVisitor::visitLoop(WPLParser::LoopContext *ctx) {
    return visitChildren(ctx);
}

