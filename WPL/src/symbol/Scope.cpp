#include "Scope.h"

#include <sstream>

#include "Symbol.h"

Symbol *Scope::addSymbol(std::string id, SymType t) {
    Symbol *s = new Symbol(id, t);
    if (symbols.find(id) != symbols.end()) {
        return nullptr;
    }
    auto ret = (symbols.insert(std::pair(id, s))).first;
    return ret->second;
}

// Symbol &Scope::addSymbol(Symbol &symbol) {
//     if (symbols.count(symbol.id)) {
//         return *symbols[symbol.id];
//     }
//     symbols.insert(std::pair(symbol.id, &symbol));
//     return symbol;
// }

Symbol *Scope::findSymbol(std::string id) {
    Symbol *s;
    std::map<std::string, Symbol *>::const_iterator i = symbols.find(id);
    if (i == symbols.end()) {
        s = nullptr;
    } else {
        s = i->second;
    }
    return s;
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
