#pragma once
#include <map>

#include "Symbol.h"

class Scope {
   public:
    Scope() : parent(nullptr) {}
    Scope(Scope* p) : parent(p) {}
    // Symbol& addSymbol(Symbol& s);
    Symbol* addSymbol(std::string id, SymType t);
    Symbol* findSymbol(std::string id);
    Scope* getParent() { return parent; }
    void setId(int id) { scopeId = id; }  // used by STManager
    int getId() { return scopeId; }
    std::string toString() const;

   private:
    int scopeId = -1;  // The index in the symbol table manager
    Scope* parent;
    std::map<std::string, Symbol*> symbols;  // k: id, v: symbol
};

