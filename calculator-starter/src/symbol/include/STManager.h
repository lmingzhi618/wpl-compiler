#pragma once
#include <vector>

#include "Scope.h"

class STManager {
   public:
    STManager(){};
    Scope& enterScope();
    Scope& exitScope();

    // Pass through methods
    Symbol* addSymbol(Symbol& s);
    // Symbol* addSymbol(std::string id, SymType t);
    Symbol* findSymbol(std::string id);

    // Miscellaneous (useful for testing)
    Scope& getCurrentScope() { return *currentScope; }
    int scopeCount() { return scopes.size(); }
    std::string toString() const;

   private:
    std::vector<Scope*> scopes;
    Scope* currentScope = nullptr;
    int scopeNumber = 0;
};
