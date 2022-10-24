
#pragma once

#include "ErrorHandler.h"
#include "PropertyManager.h"
#include "STManager.h"
#include "WPLBaseVisitor.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "WPLVisitor.h"
#include "antlr4-runtime.h"

class SymbolVisitor : public WPLBaseVisitor {
   public:
    SymbolVisitor(STManager *stmgr, PropertyManager *pm)
        : stmgr(stmgr), bindings(pm) {}

    bool hasErrors() { return errors.hasErrors(); }
    std::string getErrors() { return errors.errorList(); }
    STManager *getSTManager() { return stmgr; }
    PropertyManager *getBindings() { return bindings; }

   private:
    STManager *stmgr;
    PropertyManager *bindings;
    ErrorHandler errors;
};

