#pragma once
#include <map>
#include <string>

#include "Symbol.h"

// Scope implemented as Flattened Tree
class Scope {
   public:
    Scope() : parent(nullptr) {}
    Scope(Scope* p) : parent(p) {}
    Symbol* addSymbol(Symbol* s);  // return nullptr if duplicate - wpl
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

