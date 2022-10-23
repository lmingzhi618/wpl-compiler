#include "SymbolVisitor.h"

#include <string>

SymbolVisitor::SymbolVisitor(STManager *stmgr, PropertyManager *pm)
    : stmgr(stmgr), bindings(pm) {}

std::any SymbolVisitor::visitCompilationUnit(
    WPLParser::CompilationUnitContext *ctx) {
    stmgr->enterScope();  // initial (global) scope
    return visitChildren(ctx);
}

// scalarDeclaration : (t=type| VAR) scalars+=scalar (',' scalars+=scalar)* ';'
std::any SymbolVisitor::visitScalarDeclaration(
    WPLParser::ScalarDeclarationContext *ctx) {
    // 1. Get the type
    SymBaseType type = UNDEFINED;
    if (ctx->t != nullptr) {
        type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    }

    // 2. Get the variable name(s)
    std::string id;
    for (auto s : ctx->scalars) {
        id = s->ID()->getText();
        Symbol *sym = new Symbol(id, type);
        Symbol *symbol = stmgr->addSymbol(sym);
        // std::cout << ctx->t->getText() << id << std::endl;
        if (symbol == nullptr) {
            errors.addError(ctx->getStart(), "Duplicate variable: " + id);
        }
    }
    return nullptr;
}

std::any SymbolVisitor::visitType(WPLParser::TypeContext *ctx) {
    return ctx->b != nullptr ? BOOL : ctx->i != nullptr ? INT : STR;
}

std::any SymbolVisitor::visitArrayDeclaration(
    WPLParser::ArrayDeclarationContext *ctx) {
    // 1. Get the type
    SymBaseType type = UNDEFINED;
    if (ctx->t) {
        type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    }
    // 2. Get the symbol
    std::string id = ctx->id->getText();
    // 3. Get the length of the array
    int len = std::stoi(ctx->INTEGER()->getText());
    if (stmgr->addSymbol(new Symbol(id, type, len))) {
        errors.addError(ctx->getStart(), "Duplicate variable: " + id);
    }
    return nullptr;
}

// function          : funcHeader block  ;
std::any SymbolVisitor::visitFunction(WPLParser::FunctionContext *ctx) {
    visitChildren(ctx);
    stmgr->exitScope();  // Entered in the header
    return nullptr;
}

// funcHeader        : t=type 'func' id=ID '(' p=params? ')' ;
std::any SymbolVisitor::visitFuncHeader(WPLParser::FuncHeaderContext *ctx) {
    SymBaseType type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    std::string id = ctx->id->getText();
    std::vector<Param *> *params = nullptr;
    if (ctx->p != nullptr) {
        params = std::any_cast<std::vector<Param *> *>(ctx->p->accept(this));
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
                errors.addError(ctx->getStart(), "Duplicate variable: " + id);
            }
        }
    }
    return nullptr;
}

// std::any SymbolVisitor::visitExternFuncHeader(
//     WPLParser::ExternFuncHeaderContext *ctx)  {
//     return visitChildren(ctx);
// }

std::any SymbolVisitor::visitParam(WPLParser::ParamContext *ctx) {
    SymBaseType type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    std::string id = ctx->id->getText();
    Param *param = new Param(id, type);
    return param;
}

std::any SymbolVisitor::visitParams(WPLParser::ParamsContext *ctx) {
    std::vector<Param *> *params = new std::vector<Param *>;
    for (WPLParser::ParamContext *param : ctx->ps) {
        std::string id = param->id->getText();
        SymBaseType type = std::any_cast<SymBaseType>(param->t->accept(this));
        Param *prm = new Param(id, type);
        params->push_back(prm);
    }
    return params;
}

std::any SymbolVisitor::visitBlock(WPLParser::BlockContext *ctx) {
    stmgr->enterScope();
    this->visitChildren(ctx);
    stmgr->exitScope();
    return nullptr;
}

// ID      				  : LETTER (LETTER|DIGIT|UNDERSCORE)* ;
std::any SymbolVisitor::visitIDExpr(WPLParser::IDExprContext *ctx) {
    std::string id = ctx->id->getText();
    Symbol *symbol = stmgr->findSymbol(id);
    if (symbol) {
        bindings->bind(ctx, symbol);  // bindings: property manager
    } else {
        errors.addError(ctx->getStart(), "Use of undefined variable: " + id);
    }
    return nullptr;
}

std::any SymbolVisitor::visitConstant(WPLParser::ConstantContext *ctx) {
    return ctx->b != nullptr ? BOOL : ctx->i != nullptr ? INT : STR;
}
