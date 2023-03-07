#include <stdexcept>

#include "antlr4-runtime.h"

class TestErrorListener : public antlr4::BaseErrorListener {
    virtual void syntaxError(antlr4::Recognizer *recognizer,
                             antlr4::Token *offendingSymbol, size_t line,
                             size_t charPositionInline, const std::string &msg,
                             std::exception_ptr e) override {
        throw std::invalid_argument("test error thrown");
    }
};
