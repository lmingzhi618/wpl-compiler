
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  CalculatorLexer : public antlr4::Lexer {
public:
  enum {
    ASSIGN = 1, DIVIDE = 2, EQUAL = 3, GREATER = 4, LESS = 5, MINUS = 6, 
    MULTIPLY = 7, NOT = 8, PLUS = 9, UNEQUAL = 10, LPAR = 11, RPAR = 12, 
    SEMICOLON = 13, FALSE = 14, TRUE = 15, INTEGER = 16, VARIABLE = 17, 
    WS = 18
  };

  explicit CalculatorLexer(antlr4::CharStream *input);

  ~CalculatorLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

