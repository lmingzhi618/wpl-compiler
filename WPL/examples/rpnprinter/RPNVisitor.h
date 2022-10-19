#include "CalculatorBaseVisitor.h"
#include "antlr4-runtime.h"

class RPNVisitor : CalculatorBaseVisitor {
   public:
    std::any visitProgram(CalculatorParser::ProgramContext *ctx);
    std::any visitBooleanConstant(
        CalculatorParser::BooleanConstantContext *ctx);
    std::any visitAssignExpression(
        CalculatorParser::AssignExpressionContext *ctx);
    std::any visitParenExpr(CalculatorParser::ParenExprContext *ctx);
    std::any visitUnaryMinusExpr(CalculatorParser::UnaryMinusExprContext *ctx);
    std::any visitUnaryNotExpr(CalculatorParser::UnaryNotExprContext *ctx);
    std::any visitBinaryArithExpr(
        CalculatorParser::BinaryArithExprContext *ctx);
    std::any visitBinaryRelExpr(CalculatorParser::BinaryRelExprContext *ctx);
    std::any visitEqExpr(CalculatorParser::EqExprContext *ctx);
    std::any visitVariableExpr(CalculatorParser::VariableExprContext *ctx);
    std::any visitIConstExpr(CalculatorParser::IConstExprContext *ctx);
};
