#pragma once
#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <sstream>
#include <string>

#include "llvm/IR/Value.h"

enum SymType { SCALAR, ARRAY, METHOD };
enum SymBaseType { UNDEFINED, INT, BOOL, STR };

struct Param {
    std::string id;
    SymBaseType baseType;
};

struct Symbol {
    std::string id;
    SymType symType;
    SymBaseType baseType;  // The base type of the symbol: SCALAR = type;a
                           // FUNC = return type, ARRAY = element type
    int length = 0;        // ARRAY only
    std::vector<Param *> *params = nullptr;

    bool defined;
    llvm::Value *val;
    Symbol(std::string id, SymType t, std::vector<Param *> *params = nullptr) {
        id = id;
        symType = t;
        params = params;
        defined = false;
        val = nullptr;
    }

    std::string toString() const {
        std::ostringstream desc;
        desc << '[' << id << ", " << getSymTypeName(symType) << ']';
        return desc.str();
    }

    static std::string getSymTypeName(SymType st) {
        std::string s;
        switch (st) {
            case INT:
                s = "INT";
                break;
            case BOOL:
                s = "BOOL";
                break;
            default:
                s = "UNDEFINED";
        }
        return s;
    }
};

#endif
