
#pragma once

#include "WPLBaseVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "WPLVisitor.h"
#include "antlr4-runtime.h"

class SymbolVisitor : public WPLBaseVisitor {
   private:
   public:
    SymbolVisitor() {}
    virtual std::any visitCompilationUnit(
        WPLParser::CompilationUnitContext *ctx) override {
        stmgr->enterScope();  // initial (global) scope
        return visitChildren(ctx);
    }

    virtual std::any visitCuComponent(
        WPLParser::CuComponentContext *ctx) override {
        stmgr->enterScope();
        return visitChildren(ctx);
    }

    virtual std::any visitVarDeclaration(
        WPLParser::VarDeclarationContext *ctx) override {
        stmgr->enterScope();
        return visitChildren(ctx);
    }

    // virtual std::any visitScalar(WPLParser::ScalarContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitArrayDeclaration(
    //     WPLParser::ArrayDeclarationContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitVarInitializer(
    //     WPLParser::VarInitializerContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitExternDeclaration(
    //     WPLParser::ExternDeclarationContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitProcedure(WPLParser::ProcedureContext *ctx)
    // override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitProcHeader(
    //     WPLParser::ProcHeaderContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitExternProcHeader(
    //     WPLParser::ExternProcHeaderContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitExternFuncHeader(
    //     WPLParser::ExternFuncHeaderContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitStatement(WPLParser::StatementContext *ctx)
    // override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitLoop(WPLParser::LoopContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitConditional(
    //     WPLParser::ConditionalContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitSelect(WPLParser::SelectContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitSelectAlt(WPLParser::SelectAltContext *ctx)
    // override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitCall(WPLParser::CallContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitArguments(WPLParser::ArgumentsContext *ctx)
    // override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitArg(WPLParser::ArgContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitReturn(WPLParser::ReturnContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitConstant(WPLParser::ConstantContext *ctx) override
    // {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitAssignment(
    //     WPLParser::AssignmentContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitArrayIndex(
    //     WPLParser::ArrayIndexContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitAndExpr(WPLParser::AndExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitConstExpr(WPLParser::ConstExprContext *ctx)
    // override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitSubscriptExpr(
    //     WPLParser::SubscriptExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitRelExpr(WPLParser::RelExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitMultExpr(WPLParser::MultExprContext *ctx) override
    // {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitAddExpr(WPLParser::AddExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitArrayLengthExpr(
    //     WPLParser::ArrayLengthExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitUMinusExpr(
    //     WPLParser::UMinusExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitOrExpr(WPLParser::OrExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitEqExpr(WPLParser::EqExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitNotExpr(WPLParser::NotExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitParenExpr(WPLParser::ParenExprContext *ctx)
    // override {
    //     return visitChildren(ctx);
    // }

    // virtual std::any visitFuncCallExpr(
    //     WPLParser::FuncCallExprContext *ctx) override {
    //     return visitChildren(ctx);
    // }

    std::any visitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) {
        // 1. Get the type
        SymType type = UNDEFINED;
        std::string id;
        if (ctx->t != nullptr) {
            type = std::any_cast<SymType>(ctx->t->accept(this));
        }

        // 2. Get the variable name(s)
        for (auto s : ctx->scalars) {
            id = s->id->getText();
            Symbol *sym = new Symol(id, type);
            Symbol *symbol = stmgr->addSymbol(sym);
            if (symbol == nullptr) {
                errors.addError(ctx->getStart(), "Duplicate variable: " + id);
            }
        }
        return nullptr;
    }

    std::any visitBlock(WPLParser::BlockContext *ctx) {
        stmgr->enterScope();
        this->visitChildren(ctx);
        stmgr->exitScope();
        return nullptr;
    }

    std::any visitType(WPLParser::TypeContext *ctx) {
        return ctx->b != nullptr ? BOOLEAN : ctx->i != nullptr ? INT : STR;
    }

    std::any visitParam(WPLParser::ParamsContext *ctx) {
        SymBaseType type = std::any_cast<SymBaseType>(ctx->t->accept(this));
        std::string id = ctx->id->getText();
        Param *param = new Param(id, type);
        return param;
    }

    std::any visitParams(WPLParser::ParamsContext *ctx) {
        std::vector<Param *> *params = new std::vector<Param *>;
        for (WPLParser::ParamsContext *param : ctx->p) {
            std::string id = param->id->getText();
            SymBaseType type =
                std::any_cast<SymBaseType>(param->t->accept(this));
            Param *prm = new Param(id, type);
            params->push_back(prm);
        }
        return params;
    }

    std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx) {
        SymBaseType type = std::any_cast<SymBaseType>(ctx->t->accept(this));
        std::string id = ctx->id->getText();
        std::vector<Param *> *params = nullptr;
        if (ctx->p != nullptr) {
            params =
                std::any_cast<std::vector<Param *> *>(ctx->p->accept(this));
        }
        Symbol *sym = new Symbol(id, type, params);
        Symbol *symbol = stmgr->addSymbol(sym);
        if (symbol == nullptr) {
            errors.addError(ctx->getStart(), "Duplicate variable: " + id);
        }

        stmgr->enterScope();  // scope for the parameters
        if (ctx->p != nullptr) {
            for (Param *p : *params) {
                Symbol *sym = new Symbol(p->id, p->baseType);
                Symbol *symbol = stmgr->addSymbol(sym);
                if (symbol) {
                    errors.addError(ctx->getStart(),
                                    "Duplicate variable: " + id);
                }
            }
        }
        return nullptr;
    }

    std::any visitFunction(WPLParser::FunctionContext *ctx) {
        visitChildren(ctx);
        stmgr->exitScope();  // Entered in the header
        return nullptr;
    }

    std::any visitIDExpr(WPLParser::IDExprContext *ctx) {
        std::string id = ctx->id->getText();
        Symbol *symbol = stmgr->findSymbol(id);
        if (symbol) {
            bindings->bind(ctx, symbol);  // bindings: property manager
        } else {
            errors.addError(ctx->getStart(),
                            "Use of undefined variable: " + id);
        }
        return nullptr
    }
};

