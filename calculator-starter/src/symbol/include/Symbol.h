#pragma once
#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <sstream>
#include <string>

#include "llvm/IR/Value.h"

enum SymType { INT, BOOL, UNDEFINED };

struct Symbol {
    std::string identifier;
    SymType type;
    bool defined;
    llvm::Value *val;
    Symbol(std::string id, SymType t) {
        identifier = id;
        type = t;
        defined = false;
        val = nullptr;
    }

    std::string toString() const {
        std::ostringstream desc;
        desc << '[' << identifier << ", " << getSymTypeName(type) << ']';
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
