#include "Scope.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Symbol.h"

// Symbol *Scope::addSymbol(std::string id, SymBaseType t) {
//     Symbol *s = new Symbol(id, t);
//     if (symbols.find(id) != symbols.end()) {
//         return nullptr;
//     }
//     auto ret = (symbols.insert(std::pair(id, s))).first;
//     return ret->second;
// }

Symbol *Scope::addSymbol(Symbol *symbol) {
    if (symbols.count(symbol->id) > 0) {
        return nullptr;
    }
    //  The pair::second element in the pair is set to true if a new element was
    //  inserted or false if an equivalent key already existed.
    auto ret = (symbols.insert(std::pair(symbol->id, symbol))).first;
    return ret->second;
}

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
    if (symbols.size() == 0) {
        return "";
    }
    std::ostringstream desc;
    desc << std::endl
         << "----------------------" << std::endl
         << "SCOPE: " << scopeId;
    if (parent) {
        desc << " PARENT: " << parent->scopeId;
    }
    // std::cout << "symbol len: " << symbols.size() << std::endl;
    desc << std::endl << '{';
    for (auto s : symbols) {
        desc << std::endl << "    " << s.second->toString();
    }
    desc << std::endl << '}' << std::endl << std::endl;
    return desc.str();
}
