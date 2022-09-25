#include "SemanticVisitor.h"

std::any SemanticVisitor::visitProgram(CalculatorParser::ProgramContext *ctx) {}

std::any SemanticVisitor::visitAssignExpression(
    CalculatorParser::AssignExpressionContext *ctx) {
    // Visit the expression
    SymType result = std::any_cast<SymType>(ctx->ex->accept(this));
    if (result == UNDEFINED) {
        errors.addSemanticError(ctx->getStart(),
                                "Expression evaluates to an UNDEFINED type");
    }

    std::string varId = ctx->v->getText();
    Symbol *symbol = stmgr->findSymbol(varId);
    if (symbol == nullptr) {
        // Undefined: add it
        symbol = stmgr->addSymbol(varId, result);
    } else {
        symbol->type = result;
    }
    // For the calculator, we don't have to check the type of the variable
    // since it would be redefined here.
    return result;
}
