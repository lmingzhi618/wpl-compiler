#include "Scope.h"

#include <sstream>

#include "Symbol.h"

Symbol *Scope::addSymbol(std::string id, SymType t) {
    if (symbols.count(id)) {
        return symbols[id];
    }
    Symbol *s = new Symbol(id, t);
    symbols.insert(std::pair(id, s));
    return s;
}

Symbol &Scope::addSymbol(Symbol &symbol) {
    if (symbols.count(symbol.identifier)) {
        return *symbols[symbol.identifier];
    }
    symbols.insert(std::pair(symbol.identifier, &symbol));
    return symbol;
}

Symbol *Scope::findSymbol(std::string id) {
    Symbol *s;
    if (symbols.count(id) == 0) {
        return nullptr;
    }
    return symbols[id];
}

std::string Scope::toString() const {
    std::ostringstream desc;
    desc << std::endl
         << "----------------------" << std::endl
         << "SCOPE: " << scopeId;
    if (parent) {
        desc << " PARENT: " << parent->scopeId;
    }
    desc << std::endl << '{';
    for (auto sys : symbols) {
        desc << std::endl << "    " << sys.second->toString();
    }
    desc << std::endl << '}' << std::endl << std::endl;
    return desc.str();
}
