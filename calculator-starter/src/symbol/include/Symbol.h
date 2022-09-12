#pragma once
#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <sstream>
#include <string>

enum SymType { INT, BOOL, UNDEFINED };

struct Symbol {
    std::string identifier;
    SymType type;

    Symbol(std::string id, SymType t) {
        identifier = id;
        type = t;
    }

    std::string toString() const {
        std::ostringstream desc;
        std::string typeName = type == INT    ? "INT"
                               : type == BOOL ? "BOOL"
                                              : "UNDEFINED";
        desc << '[' << identifier << ", " << typeName << ']';
        return desc.str();
    }
};

#endif
