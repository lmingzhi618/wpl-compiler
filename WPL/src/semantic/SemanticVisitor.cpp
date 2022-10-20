#include "SemanticVisitor.h"

#include <any>

/**
 * @brief Visit the expressions below the program
 */
// std::any SemanticVisitor::visitCompilationUnit(
//     WPLParser::CompilationUnitContext *ctx) {
//     stmgr->enterScope();  // initial scope (only one for this example)
//     for (auto e : ctx->exprs) {
//         e->accept(this);
//     }
//     return SymType::UNDEFINED;
// }

std::any SemanticVisitor::visitType(WPLParser::TypeContext *ctx) {
    return visitChildren(ctx);
}

// std::any visitConstant(WPLParser::ConstantContext *ctx) {}

/**
 * @brief IConstExpr.type = INT
 */
// std::any SemanticVisitor::visitIConstExpr(WPLParser::IConstExprContext *ctx)
// {
//     return SymType::INT;
// }
//
// std::any SemanticVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx) {
//     return ctx->ex->accept(this);
// }
//
///**
// * @brief UnaryMinusExpr.type = ex.type && ex.type == INT;
// * @return SymTyp::INT if no error, otherwise SymType::UNDEFINED
// */
// std::any SemanticVisitor::visitUnaryMinusExpr(
//    WPLParser::UnaryMinusExprContext *ctx) {
//    auto t = std::any_cast<SymType>(ctx->ex->accept(this));
//    if (t != SymType::INT) {  // Type mismatch
//        errors.addSemanticError(
//            ctx->getStart(),
//            "INT expression expected, but was " + Symbol::getSymTypeName(t));
//        t = SymType::UNDEFINED;
//    }
//    return t;
//}
//
// std::any SemanticVisitor::visitUnaryNotExpr(
//    WPLParser::UnaryNotExprContext *ctx) {
//    auto t = std::any_cast<SymType>(ctx->ex->accept(this));
//    if (t != SymType::BOOL) {  // Type mismatch
//        errors.addSemanticError(
//            ctx->getStart(),
//            "BOOL expression expected, but was " + Symbol::getSymTypeName(t));
//        t = SymType::UNDEFINED;
//    }
//    return t;
//}
//
// std::any SemanticVisitor::visitBinaryArithExpr(
//    WPLParser::BinaryArithExprContext *ctx) {
//    SymType type = INT;
//    auto left = std::any_cast<SymType>(ctx->left->accept(this));
//    if (left != SymType::INT) {  // Type mismatch
//        errors.addSemanticError(ctx->getStart(),
//                                "INT left expression expected, but was " +
//                                    Symbol::getSymTypeName(left));
//        type = SymType::UNDEFINED;
//    }
//    auto right = std::any_cast<SymType>(ctx->right->accept(this));
//    if (right != SymType::INT) {  // Type mismatch
//        errors.addSemanticError(ctx->getStart(),
//                                "INT right expression expected, but was " +
//                                    Symbol::getSymTypeName(right));
//        type = SymType::UNDEFINED;
//    }
//    return type;
//}
//
// std::any SemanticVisitor::visitBinaryRelExpr(
//    WPLParser::BinaryRelExprContext *ctx) {
//    SymType type = BOOL;
//    auto left = std::any_cast<SymType>(ctx->left->accept(this));
//    if (left != SymType::INT) {
//        errors.addSemanticError(ctx->getStart(),
//                                "BOOL left expression expected, but was " +
//                                    Symbol::getSymTypeName(left));
//        type = SymType::UNDEFINED;
//    }
//    auto right = std::any_cast<SymType>(ctx->right->accept(this));
//    if (right != SymType::INT) {
//        errors.addSemanticError(ctx->getStart(),
//                                "BOOL right expression expected, but was " +
//                                    Symbol::getSymTypeName(right));
//        type = SymType::UNDEFINED;
//    }
//    return type;
//}
//
// std::any SemanticVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
//    SymType result = BOOL;
//    result = std::any_cast<SymType>(ctx->right->accept(this));
//    auto left = std::any_cast<SymType>(ctx->left->accept(this));
//    if (result != left) {
//        errors.addSemanticError(ctx->getStart(),
//                                "Both sides of '=' must have the same type.");
//        result = SymType::UNDEFINED;
//    }
//    return result;
//}
//
///**
// * @brief assignExpression.defined = TRUE
// *        assignExpression.type = ex.type
// *
// * @return the type of the expression to which the variable is assigned
// */
// std::any SemanticVisitor::visitAssignExpression(
//    WPLParser::AssignExpressionContext *ctx) {
//    // Visit the expression
//    SymType result = std::any_cast<SymType>(ctx->ex->accept(this));
//    if (result == UNDEFINED) {
//        errors.addSemanticError(ctx->getStart(),
//                                "Expression evaluates to an UNDEFINED type");
//    }
//
//    std::string varId = ctx->v->getText();
//    Symbol *symbol = stmgr->findSymbol(varId);
//    if (symbol == nullptr) {
//        // Undefined: add it
//        symbol = stmgr->addSymbol(varId, result);
//    } else {
//        symbol->type = result;
//    }
//    // For the calculator, we don't have to check the type of the variable
//    // since it would be redefined here.
//    bindings->bind(ctx, symbol);
//    return result;
//}
//
///**
// * @brief v.defined == TRUE && VariableExpr.type = v.type
// *
// * @return The type of the variable as found in the symbol table or UNDEFINED
// if
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
//                                "Undefined avriable in expression: " + varId);
//    } else {
//        // bind the symbol to this node
//        bindings->bind(ctx, symbol);
//        result = symbol->type;
//    }
//    return result;
//}
