/**
 * @file WPLErrorHandler.h
 * @author your name (you@domain.com)
 * @brief A simple error handler that gathers errors and can print them out
 * @version 0.1
 * @date 2022-07-23
 */
#pragma once
#include <sstream>
#include <string>
#include <vector>

#include "antlr4-runtime.h"

enum ErrType { SEMANTIC, CODEGEN };

struct WPLError {
    antlr4::Token* token;
    std::string message;
    std::string type;

    // Constructor
    WPLError(antlr4::Token* tok, std::string msg, ErrType et) {
        token = tok;
        message = msg;
        type = et == SEMANTIC ? "SEMANTIC" : "CODEGEN";
    }

    std::string toString() {
        std::ostringstream e;
        e << type << ": [" << token->getLine() << ','
          << token->getCharPositionInLine() << "]: " << message;
        return e.str();
    }
};

class ErrorHandler {
   public:
    void addError(antlr4::Token* t, std::string msg);  // wpl

    void addSemanticError(antlr4::Token* t, std::string msg) {
        WPLError* e = new WPLError(t, msg, SEMANTIC);
        errors.push_back(e);
    }

    void addCodegenError(antlr4::Token* t, std::string msg) {
        WPLError* e = new WPLError(t, msg, CODEGEN);
        errors.push_back(e);
        ;
    }

    std::vector<WPLError*>& getErrors() { return errors; }

    std::string errorList() {
        std::ostringstream errList;
        for (WPLError* e : errors) {
            errList << e->toString() << std::endl;
        }
        return errList.str();
    }

    bool hasErrors() { return !errors.empty(); }

   private:
    std::vector<WPLError*> errors;
};
