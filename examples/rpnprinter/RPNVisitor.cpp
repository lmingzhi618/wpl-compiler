#include "RPNVisitor.h"

#include <iostream>

std::any RPNVisitor::visitProgram(WPLParser::ProgramContext *ctx) {
    for (auto e : ctx->exprs) {
        e->accept(this);
        std::cout << std::endl;
    }
    return NULL;
}

std::any RPNVisitor::visitAssignExpression(
    WPLParser::AssignExpressionContext *ctx) {
    ctx->ex->accept(this);          // ex: expression
    std::cout << ctx->v->getText()  // v: VARIABLE
              << ":=";
    return NULL;
}

std::any RPNVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx) {
    ctx->ex->accept(this);
    return NULL;
}

std::any RPNVisitor::visitBooleanConstant(
    WPLParser::BooleanConstantContext *ctx) {
    std::cout << ctx->getText();
    return NULL;
}

std::any RPNVisitor::visitUnaryMinusExpr(
    WPLParser::UnaryMinusExprContext *ctx) {
    ctx->ex->accept(this);
    std::cout << "-";
    return NULL;
}

std::any RPNVisitor::visitUnaryNotExpr(WPLParser::UnaryNotExprContext *ctx) {
    ctx->ex->accept(this);
    std::cout << "~";
    return NULL;
}

std::any RPNVisitor::visitBinaryArithExpr(
    WPLParser::BinaryArithExprContext *ctx) {
    ctx->left->accept(this);
    ctx->right->accept(this);
    std::cout << ctx->op->getText();
    return NULL;
}

std::any RPNVisitor::visitBinaryRelExpr(WPLParser::BinaryRelExprContext *ctx) {
    ctx->left->accept(this);
    ctx->right->accept(this);
    std::cout << ctx->op->getText();
    return NULL;
}

std::any RPNVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
    ctx->right->accept(this);  // right associative
    ctx->left->accept(this);
    std::cout << ctx->op->getText();
    return NULL;
}

std::any RPNVisitor::visitVariableExpr(WPLParser::VariableExprContext *ctx) {
    std::cout << ctx->getText();
    return NULL;
}

std::any RPNVisitor::visitIConstExpr(WPLParser::IConstExprContext *ctx) {
    std::cout << ctx->getText();
    return NULL;
}
