#include "SemanticVisitor.h"

#include <any>
#include <string>

// std::any visitConstant(WPLParser::ConstantContext *ctx) {}

/**
 * @brief IConstExpr.type = INT
 */
// std::any SemanticVisitor::visitIConstExpr(WPLParser::IConstExprContext *ctx)
// {
//     return SymType::INT;
// }

//
///**
// * @brief v.defined == TRUE && VariableExpr.type = v.type
// *
// * @return The type of the variable as found in the symbol table or
// UNDEFINED if
// * it is not defined in the symbol table.
// */
// std::any SemanticVisitor::visitVariableExpr(
//    WPLParser::VariableExprContext *ctx) {
//    SymType result = UNDEFINED;
//    std::string varId = ctx->v->getText();
//    Symbol *symbol = stmgr->findSymbol(varId);
//    if (symbol == nullptr) {
//        // Undefined: error
//        errors.addSemanticError(ctx->getStart(),
//                                "Undefined avriable in expression: " +
//                                varId);
//    } else {
//        // bind the symbol to this node
//        bindings->bind(ctx, symbol);
//        result = symbol->type;
//    }
//    return result;
//}

std::any SemanticVisitor::visitCompilationUnit(
    WPLParser::CompilationUnitContext *ctx) {
    stmgr->enterScope();  // initial (global) scope
    return visitChildren(ctx);
}

std::any SemanticVisitor::visitVarInitializer(
    WPLParser::VarInitializerContext *ctx) {
    return ctx->c->accept(this);
}

// scalarDeclaration : (t=type| VAR) scalars+=scalar (',' scalars+=scalar)*
std::any SemanticVisitor::visitScalarDeclaration(
    WPLParser::ScalarDeclarationContext *ctx) {
    std::string fn("[SemanticVisitor::visitScalarDeclaration] ");
    // 1. Get the type
    SymBaseType type = UNDEFINED;
    if (ctx->t != nullptr) {
        type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    }

    // 2. Get the variable name(s)
    std::string id;
    for (auto s : ctx->scalars) {
        if (s->varInitializer()) {
            auto st =
                std::any_cast<SymBaseType>(s->varInitializer()->accept(this));
            if (type != UNDEFINED && st != type) {
                errors.addError(ctx->getStart(),
                                fn + "Value type(" +
                                    Symbol::getBaseTypeName(st) +
                                    ") doesn't match scalar type(" +
                                    Symbol::getBaseTypeName(type) + ")");
            }
        }
        id = s->ID()->getText();
        Symbol *sym = new Symbol(id, type);
        Symbol *symbol = stmgr->addSymbol(sym);
        if (symbol == nullptr) {
            errors.addError(ctx->getStart(), fn + "Duplicate variable: " + id);
        }
        bindings->bind(s, symbol);  // bindings: property manager
    }
    return nullptr;
}

// std::any SemanticVisitor::visitScalar(WPLParser::ScalarContext *ctx) {
//     id = ctx->ID()->getText();
//     Symbol *sym = new Symbol(id, type);
//     Symbol *symbol = stmgr->addSymbol(sym);
//     if (symbol == nullptr) {
//         errors.addError(ctx->getStart(), fn + "Duplicate variable: " + id);
//     }
//
//     if (ctx->varInitializer()) {
//         auto st =
//             std::any_cast<SymBaseType>(ctx->varInitializer()->accept(this));
//         if (st != type) {
//             errors.addError(ctx->getStart(),
//                             fn + "Value type(" + Symbol::getBaseTypeName(st)
//                             +
//                                 ") doesn't match scalar type(" +
//                                 Symbol::getBaseTypeName(type) + ")");
//         }
//     }
// }
std::any SemanticVisitor::visitType(WPLParser::TypeContext *ctx) {
    return ctx->b != nullptr ? BOOL : ctx->i != nullptr ? INT : STR;
}

std::any SemanticVisitor::visitArrayDeclaration(
    WPLParser::ArrayDeclarationContext *ctx) {
    std::string fn("[SemanticVisitor::visitArrayDeclaration] ");

    // 1. Get the type
    SymBaseType type = UNDEFINED;
    if (ctx->t) {
        type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    }

    // 2. Get the symbol
    std::string id = ctx->id->getText();

    // 3. Get the length of the array
    int len = std::stoi(ctx->INTEGER()->getText());

    // std::cout << fn << "add symbol: id: " << id << ", type: " << type
    //           << ", len: " << len << std::endl;

    if (nullptr == stmgr->addSymbol(new Symbol(id, type, len))) {
        // std::cerr << fn << ", add errornullptr == " << std::endl;
        errors.addError(ctx->getStart(), fn + "Duplicate variable: " + id);
    }
    // std::cout << fn << " END..." << std::endl;
    return nullptr;
}

// function          : funcHeader block  ;
std::any SemanticVisitor::visitFunction(WPLParser::FunctionContext *ctx) {
    visitChildren(ctx);
    stmgr->exitScope();  // Entered in the header
    return nullptr;
}

// funcHeader        : t=type 'func' id=ID '(' p=params? ')' ;
std::any SemanticVisitor::visitFuncHeader(WPLParser::FuncHeaderContext *ctx) {
    std::string fn("[SemanticVisitor::visitFuncHeader] ");
    SymBaseType type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    std::string id = ctx->id->getText();
    std::vector<Param *> *params = nullptr;
    if (ctx->p != nullptr) {
        params = std::any_cast<std::vector<Param *> *>(ctx->p->accept(this));
    }
    Symbol *sym = new Symbol(id, type, params);
    // std::cout << fn << "add symbol: id: " << id << ", type: " << type
    //           << std::endl;
    Symbol *symbol = stmgr->addSymbol(sym);
    if (symbol == nullptr) {
        errors.addError(ctx->getStart(), fn + "Duplicate variable: " + id);
    }

    stmgr->enterScope();  // scope for the parameters
    if (ctx->p != nullptr) {
        for (Param *p : *params) {
            Symbol *sym = new Symbol(p->id, p->baseType);

            // std::cout << fn << "add symbol: id: " << p->id
            //           << ", type: " << p->baseType << std::endl;

            Symbol *symbol = stmgr->addSymbol(sym);
            if (nullptr == symbol) {
                errors.addError(ctx->getStart(),
                                fn + "Duplicate variable: " + id);
            }
        }
    }
    bindings->bind(ctx, symbol);  // bindings: property manager
    return nullptr;
}

// std::any SemanticVisitor::visitExternFuncHeader(
//     WPLParser::ExternFuncHeaderContext *ctx)  {
//     return visitChildren(ctx);
// }

std::any SemanticVisitor::visitParam(WPLParser::ParamContext *ctx) {
    SymBaseType type = std::any_cast<SymBaseType>(ctx->t->accept(this));
    std::string id = ctx->id->getText();
    Param *param = new Param(id, type);
    return param;
}

std::any SemanticVisitor::visitParams(WPLParser::ParamsContext *ctx) {
    std::vector<Param *> *params = new std::vector<Param *>;
    for (WPLParser::ParamContext *param : ctx->ps) {
        std::string id = param->id->getText();
        SymBaseType type = std::any_cast<SymBaseType>(param->t->accept(this));
        Param *prm = new Param(id, type);
        params->push_back(prm);
    }
    return params;
}

// ID      				  : LETTER (LETTER|DIGIT|UNDERSCORE)* ;
std::any SemanticVisitor::visitIDExpr(WPLParser::IDExprContext *ctx) {
    std::string fn("SemanticVisitor::visitIDExpr");
    std::string id = ctx->id->getText();
    Symbol *symbol = stmgr->findSymbol(id);
    if (symbol) {
        bindings->bind(ctx, symbol);  // bindings: property manager
        return symbol->baseType;
    }
    errors.addError(ctx->getStart(), fn + "Use of undefined variable: " + id);
    return nullptr;
}

std::any SemanticVisitor::visitConstant(WPLParser::ConstantContext *ctx) {
    return ctx->b != nullptr ? BOOL : ctx->i != nullptr ? INT : STR;
}

// procedure         : procHeader block ;
std::any SemanticVisitor::visitProcedure(WPLParser::ProcedureContext *ctx) {
    visitChildren(ctx);
    stmgr->exitScope();  // Entered in the header
    return nullptr;
}

// procHeader        : 'proc' id=ID '(' p=params? ')' ;
std::any SemanticVisitor::visitProcHeader(WPLParser::ProcHeaderContext *ctx) {
    SymBaseType type = UNDEFINED;
    std::string fn("[SemanticVisitor::visitProcHeader] ");
    std::string id = ctx->id->getText();
    std::vector<Param *> *params = nullptr;
    if (ctx->p != nullptr) {
        params = std::any_cast<std::vector<Param *> *>(ctx->p->accept(this));
    }

    // std::cout << fn << "add symbol: id: " << id << ", type: " << type
    //           << std::endl;
    Symbol *sym = new Symbol(id, type, params);
    Symbol *symbol = stmgr->addSymbol(sym);
    if (symbol == nullptr) {
        errors.addError(ctx->getStart(), fn + "Duplicate variable: " + id);
    }

    stmgr->enterScope();  // scope for the parameters
    if (ctx->p != nullptr) {
        for (Param *p : *params) {
            // std::cout << fn << "add symbol: id: " << p->id
            //           << ", type: " << p->baseType << std::endl;
            Symbol *sym = new Symbol(p->id, p->baseType);
            Symbol *symbol = stmgr->addSymbol(sym);
            if (nullptr == symbol) {
                errors.addError(ctx->getStart(),
                                fn + "Duplicate variable: " + id);
            }
        }
    }
    return nullptr;
}

/************* Semantic Analysis *****************/
std::any SemanticVisitor::visitUMinusExpr(WPLParser::UMinusExprContext *ctx) {
    auto t = std::any_cast<SymBaseType>(ctx->expr()->accept(this));
    if (t != INT) {  // Type mismatch
        errors.addSemanticError(
            ctx->getStart(),
            "INT expression expected, but was " + Symbol::getBaseTypeName(t));
        t = UNDEFINED;
    }
    return t;
}

std::any SemanticVisitor::visitNotExpr(WPLParser::NotExprContext *ctx) {
    auto t = std::any_cast<SymBaseType>(ctx->expr()->accept(this));
    if (t != BOOL) {  // Type mismatch
        errors.addSemanticError(
            ctx->getStart(),
            "BOOL expression expected, but was " + Symbol::getBaseTypeName(t));
        t = UNDEFINED;
    }
    return t;
}

std::any SemanticVisitor::visitBinaryArithExpr(
    WPLParser::BinaryArithExprContext *ctx) {
    SymBaseType type = INT;
    auto left = std::any_cast<SymBaseType>(ctx->left->accept(this));
    if (left != SymBaseType::INT) {  // Type mismatch
        errors.addSemanticError(ctx->getStart(),
                                "INT left expression expected, but was " +
                                    Symbol::getBaseTypeName(left));
        type = SymBaseType::UNDEFINED;
    }

    auto right = std::any_cast<SymBaseType>(ctx->right->accept(this));
    if (right != SymBaseType::INT) {  // Type mismatch
        errors.addSemanticError(ctx->getStart(),
                                "INT right expression expected, but was " +
                                    Symbol::getBaseTypeName(right));
        type = SymBaseType::UNDEFINED;
    }
    return type;
}

std::any SemanticVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx) {
    return ctx->expr()->accept(this);
}

std::any SemanticVisitor::visitAssignment(WPLParser::AssignmentContext *ctx) {
    SymBaseType type = UNDEFINED;
    if (ctx->target) {
        // target=ID '<-' e=expr ';'
        type = std::any_cast<SymBaseType>(ctx->e->accept(this));
        if (type == UNDEFINED) {
            errors.addSemanticError(
                ctx->getStart(), "Expression evaluates to an UNDEFINED type");
        }

        std::string id = ctx->target->getText();
        Symbol *symbol = stmgr->findSymbol(id);
        if (symbol == nullptr) {
            symbol = stmgr->addSymbol(id, type);
        } else {
            symbol->baseType = type;
        }
        bindings->bind(ctx, symbol);
    } else if (ctx->arrayIndex()) {
        // | arrayIndex '<-' e += expr ';';
        // arrayIndex        : id=ID '[' expr ']' ;
        type =
            std::any_cast<SymBaseType>(ctx->arrayIndex()->expr()->accept(this));
        if (type != INT) {
            errors.addSemanticError(
                ctx->getStart(),
                "INT index expected, but was " + Symbol::getBaseTypeName(type));
            type = UNDEFINED;
        }

        std::string id = ctx->arrayIndex()->id->getText();
        Symbol *symbol = stmgr->findSymbol(id);
        if (symbol == nullptr) {
            symbol = stmgr->addSymbol(id, type);
        } else {
            symbol->baseType = type;
        }
        bindings->bind(ctx, symbol);
    }
    return type;
}

std::any SemanticVisitor::visitRelExpr(WPLParser::RelExprContext *ctx) {
    SymBaseType type = BOOL;
    auto left = std::any_cast<SymBaseType>(ctx->left->accept(this));
    if (left != INT) {
        errors.addSemanticError(ctx->getStart(),
                                "INT left expression expected, but was " +
                                    Symbol::getBaseTypeName(left));
        type = UNDEFINED;
    }
    auto right = std::any_cast<SymBaseType>(ctx->right->accept(this));
    if (right != INT) {
        errors.addSemanticError(ctx->getStart(),
                                "INT right expression expected, but was " +
                                    Symbol::getBaseTypeName(right));
        type = UNDEFINED;
    }
    if (false == (ctx->LESS() || ctx->LEQ() || ctx->GTR() || ctx->GEQ())) {
        errors.addSemanticError(ctx->getStart(), "Operator needed");
        type = UNDEFINED;
    }

    return type;
}

std::any SemanticVisitor::visitConditional(WPLParser::ConditionalContext *ctx) {
    auto type = std::any_cast<SymBaseType>(ctx->e->accept(this));
    if (type != BOOL) {
        errors.addSemanticError(ctx->getStart(),
                                "BOOL expression expected, but was " +
                                    Symbol::getBaseTypeName(type));
        type = UNDEFINED;
    }
    return type;
}

std::any SemanticVisitor::visitLoop(WPLParser::LoopContext *ctx) {
    auto type = std::any_cast<SymBaseType>(ctx->e->accept(this));
    if (type != BOOL) {
        errors.addSemanticError(ctx->getStart(),
                                "BOOL expression expected, but was " +
                                    Symbol::getBaseTypeName(type));
        type = UNDEFINED;
    }
    return type;
}

std::any SemanticVisitor::visitBlock(WPLParser::BlockContext *ctx) {
    stmgr->enterScope();
    this->visitChildren(ctx);
    stmgr->exitScope();
    return nullptr;
}

std::any SemanticVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
    SymBaseType result = BOOL;
    result = std::any_cast<SymBaseType>(ctx->right->accept(this));
    auto left = std::any_cast<SymBaseType>(ctx->left->accept(this));
    if (result != left) {
        errors.addSemanticError(ctx->getStart(),
                                "Both sides of '=' must have the same type.");
        result = UNDEFINED;
    }
    return result;
}

// return            : 'return' expr? ';' ;
std::any SemanticVisitor::visitReturn(WPLParser::ReturnContext *ctx) {
    SymBaseType type = UNDEFINED;
    if (ctx->expr()) {
        type = std::any_cast<SymBaseType>(ctx->expr()->accept(this));
    }
    return type;
}

std::any SemanticVisitor::visitAndExpr(WPLParser::AndExprContext *ctx) {
    auto result = std::any_cast<SymBaseType>(ctx->right->accept(this));
    auto left = std::any_cast<SymBaseType>(ctx->left->accept(this));
    if (result != left || left != BOOL) {
        errors.addSemanticError(ctx->getStart(),
                                "Both sides of '=' must be BOOL type.");
        result = UNDEFINED;
    }
    return result;
}

std::any SemanticVisitor::visitOrExpr(WPLParser::OrExprContext *ctx) {
    SymBaseType result = BOOL;
    result = std::any_cast<SymBaseType>(ctx->right->accept(this));
    auto left = std::any_cast<SymBaseType>(ctx->left->accept(this));
    if (result != left || left != BOOL) {
        errors.addSemanticError(ctx->getStart(),
                                "Both sides of '=' must be BOOL type.");
        result = UNDEFINED;
    }
    return result;
}

// std::any SemanticVisitor::visitSelect(WPLParser::SelectContext *ctx) {
//     SymBaseType result = BOOL;
//     for (auto s : ctx->selectAlt()) {
//         auto st = std::any_cast<SymBaseType>(s->e->accept(this));
//         if (st != BOOL) {
//             errors.addSemanticError(ctx->getStart(),
//                                     "BOOL expected for select expr, but get "
//                                     +
//                                         Symbol::getBaseTypeName(st));
//             result = UNDEFINED;
//         }
//     }
//     return result;
// }

std::any SemanticVisitor::visitSelectAlt(WPLParser::SelectAltContext *ctx) {
    SymBaseType result = BOOL;
    auto st = std::any_cast<SymBaseType>(ctx->accept(this));
    if (st != BOOL) {
        errors.addSemanticError(ctx->getStart(),
                                "BOOL expected for select expr, but get " +
                                    Symbol::getBaseTypeName(st));
        result = UNDEFINED;
    }
    return result;
}

std::any SemanticVisitor::visitFuncCallExpr(
    WPLParser::FuncCallExprContext *ctx) {
    SymBaseType result = UNDEFINED;
    std::string fn = ctx->fname->getText();
    Symbol *symbol = stmgr->findSymbol(fn);
    if (nullptr == symbol) {
        errors.addSemanticError(ctx->getStart(),
                                "Function(" + fn + ") not found");
    } else {
        bindings->bind(ctx, symbol);
        result = symbol->baseType;
        int argc = ctx->args.size();
        int required_argc = symbol->params->size();
        if (argc != required_argc) {
            errors.addSemanticError(ctx->getStart(),
                                    "Need " + std::to_string(required_argc) +
                                        " arguments, but provided " +
                                        std::to_string(argc) + " arguments");
            result = UNDEFINED;
        } else {
            for (int i = 0; i < argc; ++i) {
                auto t1 =
                    std::any_cast<SymBaseType>(ctx->args[i]->accept(this));
                auto t2 = std::any_cast<SymBaseType>(symbol->params[i]);
                if (t1 != t2) {
                    errors.addSemanticError(
                        ctx->getStart(),
                        "Param type mismatch: required type: " +
                            Symbol::getBaseTypeName(t2) + ", but got " +
                            Symbol::getBaseTypeName(t1));
                    result = UNDEFINED;
                }
            }
        }
    }
    return result;
}

std::any SemanticVisitor::visitCall(WPLParser::CallContext *ctx) {
    SymBaseType result = UNDEFINED;
    std::string id = ctx->id->getText();
    Symbol *symbol = stmgr->findSymbol(id);
    if (nullptr == symbol) {
        errors.addSemanticError(ctx->getStart(),
                                "Function(" + id + ") not found");
    } else {
        bindings->bind(ctx, symbol);
        result = symbol->baseType;
        int argc = ctx->arguments()->arg().size();
        int required_argc = symbol->params->size();
        if (argc != required_argc) {
            errors.addSemanticError(ctx->getStart(),
                                    "Need " + std::to_string(required_argc) +
                                        " arguments, but provided " +
                                        std::to_string(argc) + " arguments");
            result = UNDEFINED;
        } else {
            for (int i = 0; i < argc; ++i) {
                auto t1 = std::any_cast<SymBaseType>(
                    ctx->arguments()->arg(i)->accept(this));
                auto t2 = std::any_cast<SymBaseType>(symbol->params[i]);
                if (t1 != t2) {
                    errors.addSemanticError(
                        ctx->getStart(),
                        "Param type mismatch: required type: " +
                            Symbol::getBaseTypeName(t2) + ", but got " +
                            Symbol::getBaseTypeName(t1));
                    result = UNDEFINED;
                }
            }
        }
    }
    return result;
}
