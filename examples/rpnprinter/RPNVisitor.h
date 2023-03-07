#include "WPLBaseVisitor.h"
#include "antlr4-runtime.h"

class RPNVisitor : WPLBaseVisitor {
   public:
    std::any visitProgram(WPLParser::ProgramContext *ctx);
    std::any visitBooleanConstant(WPLParser::BooleanConstantContext *ctx);
    std::any visitAssignExpression(WPLParser::AssignExpressionContext *ctx);
    std::any visitParenExpr(WPLParser::ParenExprContext *ctx);
    std::any visitUnaryMinusExpr(WPLParser::UnaryMinusExprContext *ctx);
    std::any visitUnaryNotExpr(WPLParser::UnaryNotExprContext *ctx);
    std::any visitBinaryArithExpr(WPLParser::BinaryArithExprContext *ctx);
    std::any visitBinaryRelExpr(WPLParser::BinaryRelExprContext *ctx);
    std::any visitEqExpr(WPLParser::EqExprContext *ctx);
    std::any visitVariableExpr(WPLParser::VariableExprContext *ctx);
    std::any visitIConstExpr(WPLParser::IConstExprContext *ctx);
};
