#include "RPNVisitor.h"

#include <iostream>

std::any RPNVisitor::visitProgram(CalculatorParser::ProgramContext *ctx) {
    for (auto e : ctx->exprs) {
        e->accept(this);
        std::cout << std::endl;
    }
    return NULL;
}

std::any RPNVisitor::visitAssignExpression(
    CalculatorParser::AssignExpressionContext *ctx) {
    ctx->ex->accept(this);          // ex: expression
    std::cout << ctx->v->getText()  // v: VARIABLE
              << ":=";
    return NULL;
}

std::any RPNVisitor::visitParenExpr(CalculatorParser::ParenExprContext *ctx) {
    ctx->ex->accept(this);
    return NULL;
}

std::any RPNVisitor::visitBooleanConstant(
    CalculatorParser::BooleanConstantContext *ctx) {
    std::cout << ctx->getText();
    return NULL;
}

std::any RPNVisitor::visitUnaryMinusExpr(
    CalculatorParser::UnaryMinusExprContext *ctx) {
    ctx->ex->accept(this);
    std::cout << "-";
    return NULL;
}

std::any RPNVisitor::visitUnaryNotExpr(
    CalculatorParser::UnaryNotExprContext *ctx) {
    ctx->ex->accept(this);
    std::cout << "~";
    return NULL;
}

std::any RPNVisitor::visitBinaryArithExpr(
    CalculatorParser::BinaryArithExprContext *ctx) {
    ctx->left->accept(this);
    ctx->right->accept(this);
    std::cout << ctx->op->getText();
    return NULL;
}

std::any RPNVisitor::visitBinaryRelExpr(
    CalculatorParser::BinaryRelExprContext *ctx) {
    ctx->left->accept(this);
    ctx->right->accept(this);
    std::cout << ctx->op->getText();
    return NULL;
}

std::any RPNVisitor::visitEqExpr(CalculatorParser::EqExprContext *ctx) {
    ctx->right->accept(this);  // right associative
    ctx->left->accept(this);
    std::cout << ctx->op->getText();
    return NULL;
}

std::any RPNVisitor::visitVariableExpr(
    CalculatorParser::VariableExprContext *ctx) {
    std::cout << ctx->getText();
    return NULL;
}

std::any RPNVisitor::visitIConstExpr(CalculatorParser::IConstExprContext *ctx) {
    std::cout << ctx->getText();
    return NULL;
}
