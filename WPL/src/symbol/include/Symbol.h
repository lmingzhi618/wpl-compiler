#pragma once
#ifndef SYMBOL_H_
#define SYMBOL_H_
#include <stdio.h>

#include <sstream>
#include <string>
#include <vector>
#include "llvm/IR/Value.h"

enum SymType { SCALAR, ARRAY, METHOD };
enum SymBaseType { UNDEFINED, INT, BOOL, STR };  // Var can be undefined

struct Param {
    std::string id;        // parameter ID
    SymBaseType baseType;  // The base type of the parameter
    Param(std::string id, SymBaseType bt) : id(id), baseType(bt) {}
};

struct Symbol {
    std::string id;
    SymType symType;
    SymBaseType baseType;  // The base type of the symbol: SCALAR = type;
                           // FUNC = return type, ARRAY = element type
                           // (Procedure doesn't have one)
    int length = 0;        // ARRAY only
    std::vector<Param *> *params = nullptr; // declare parameters
    std::vector<Param *> *args = nullptr;	// call arguments
    bool ellipsis = false; 

    bool defined;
    llvm::Value *val;
    Symbol(std::string id, SymBaseType t)
        : id(id),
          symType(SCALAR),
          baseType(t),
          length(0),
          params(nullptr),
          args(nullptr),
          defined(false),
          val(nullptr) {}

    Symbol(std::string id, SymBaseType t, int len)
        : id(id),
          symType(ARRAY),
          baseType(t),
          length(len),
          params(nullptr),
          args(nullptr),
          defined(false),
          val(nullptr) {}

    Symbol(std::string id, SymBaseType t, std::vector<Param *> *params)
        : id(id),
          symType(METHOD),
          baseType(t),
          length(0),
          params(params),
          args(nullptr),
          defined(false),
          val(nullptr) {}

    std::string toString() const {
        std::ostringstream desc;
        desc << '[' << id << ": ";
        if (symType == METHOD) {
            if (baseType == UNDEFINED) {
                desc << "proc ";
            } else {
                desc << getBaseTypeName(baseType) << " func ";
            }
            desc << "(";
            if (params) {
                for (auto p : *params) {
                    desc << "{" << getBaseTypeName(p->baseType) << ' ' << p->id
                         << "}";
                }
            }
            desc << ")";
        } else {
            desc << getBaseTypeName(baseType);
        }
        desc << ']';
        return desc.str();
    }

    static std::string getBaseTypeName(SymBaseType st) {
        std::string s;
        // printf("[Symbol::getBaseTypeName] st: %d\n", st);
        switch (st) {
            case INT:
                s = "INT";
                break;
            case BOOL:
                s = "BOOL";
                break;
            case STR:
                s = "STR";
                break;
            default:
                s = "UNDEFINED";
        }
        return s;
    }
};

#endif
