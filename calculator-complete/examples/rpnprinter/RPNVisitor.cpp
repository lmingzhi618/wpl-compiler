/**
 * @file RPNVisitor.cpp
 * @author gpollice
 * @brief Visitor that prints the expressions from a Calculator parse tree in
 *  Reverse Polish Notation (RPN)
 * @version 0.1
 * @date 2022-07-12
 */
#include <iostream>
#include "RPNVisitor.h"

std::any RPNVisitor::visitProgram (CalculatorParser::ProgramContext *ctx) {
  for (auto e : ctx->exprs) {
    e->accept(this);
    std::cout << std::endl;
  }
  return NULL;
}

std::any RPNVisitor::visitAssignExpression(CalculatorParser::AssignExpressionContext *ctx) {
  ctx->ex->accept(this);
  std::cout << ctx->v->getText() << ":=";
  return NULL;
}

std::any RPNVisitor::visitParenExpr(CalculatorParser::ParenExprContext *ctx) {
  ctx->ex->accept(this);
  return NULL;
}

std::any RPNVisitor::visitBooleanConstant(CalculatorParser::BooleanConstantContext *ctx) {
  std::cout << ctx->getText();
  return NULL;
}  

std::any RPNVisitor::visitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *ctx) {
  ctx->ex->accept(this);
  std::cout << "-";
  return NULL;
}

std::any RPNVisitor::visitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx) {
  ctx->ex->accept(this);
  std::cout << "~";
  return NULL;
}

std::any RPNVisitor::visitBinaryArithExpr(CalculatorParser::BinaryArithExprContext *ctx) {
  ctx->left->accept(this);
  ctx->right->accept(this);
  std::cout <<  ctx->op->getText();
  return NULL;
}

std::any RPNVisitor::visitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx) {
  ctx->left->accept(this);
  ctx->right->accept(this);
  std::cout <<  ctx->op->getText();
  return NULL;
}

std::any RPNVisitor::visitEqExpr(CalculatorParser::EqExprContext *ctx) {
  ctx->right->accept(this); // right associative
  ctx->left->accept(this);
  std::cout <<  ctx->op->getText();
  return NULL;
}

std::any RPNVisitor::visitVariableExpr(CalculatorParser::VariableExprContext *ctx) {
  std::cout << ctx->getText();
  return NULL;
}

std::any RPNVisitor::visitIConstExpr(CalculatorParser::IConstExprContext *ctx) {
  std::cout << ctx->getText();
  return NULL;
}