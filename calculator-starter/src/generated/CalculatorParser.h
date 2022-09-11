
// Generated from Calculator.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  CalculatorParser : public antlr4::Parser {
public:
  enum {
    ASSIGN = 1, DIVIDE = 2, EQUAL = 3, GREATER = 4, LESS = 5, MINUS = 6, 
    MULTIPLY = 7, NOT = 8, PLUS = 9, UNEQUAL = 10, LPAR = 11, RPAR = 12, 
    SEMICOLON = 13, FALSE = 14, TRUE = 15, INTEGER = 16, VARIABLE = 17, 
    WORD = 18, WS = 19, ANY = 20
  };

  enum {
    RuleText = 0
  };

  explicit CalculatorParser(antlr4::TokenStream *input);

  CalculatorParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CalculatorParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class TextContext; 

  class  TextContext : public antlr4::ParserRuleContext {
  public:
    TextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TextContext* text();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

