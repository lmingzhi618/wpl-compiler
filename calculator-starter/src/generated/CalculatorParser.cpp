
// Generated from Calculator.g4 by ANTLR 4.10.1


#include "CalculatorListener.h"
#include "CalculatorVisitor.h"

#include "CalculatorParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CalculatorParserStaticData final {
  CalculatorParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalculatorParserStaticData(const CalculatorParserStaticData&) = delete;
  CalculatorParserStaticData(CalculatorParserStaticData&&) = delete;
  CalculatorParserStaticData& operator=(const CalculatorParserStaticData&) = delete;
  CalculatorParserStaticData& operator=(CalculatorParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag calculatorParserOnceFlag;
CalculatorParserStaticData *calculatorParserStaticData = nullptr;

void calculatorParserInitialize() {
  assert(calculatorParserStaticData == nullptr);
  auto staticData = std::make_unique<CalculatorParserStaticData>(
    std::vector<std::string>{
      "program", "booleanConstant", "assignExpression", "expression"
    },
    std::vector<std::string>{
      "", "':='", "'/'", "'='", "'>'", "'<'", "'-'", "'*'", "'~'", "'+'", 
      "'~='", "'('", "')'", "';'", "'false'", "'true'"
    },
    std::vector<std::string>{
      "", "ASSIGN", "DIVIDE", "EQUAL", "GREATER", "LESS", "MINUS", "MULTIPLY", 
      "NOT", "PLUS", "UNEQUAL", "LPAR", "RPAR", "SEMICOLON", "FALSE", "TRUE", 
      "INTEGER", "VARIABLE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,18,56,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,4,0,12,8,0,11,0,
  	12,0,13,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,3,3,37,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,5,3,51,8,3,10,3,12,3,54,9,3,1,3,0,1,6,4,0,2,4,6,0,5,1,0,14,
  	15,2,0,2,2,7,7,2,0,6,6,9,9,1,0,4,5,2,0,3,3,10,10,62,0,11,1,0,0,0,2,17,
  	1,0,0,0,4,19,1,0,0,0,6,36,1,0,0,0,8,9,3,6,3,0,9,10,5,13,0,0,10,12,1,0,
  	0,0,11,8,1,0,0,0,12,13,1,0,0,0,13,11,1,0,0,0,13,14,1,0,0,0,14,15,1,0,
  	0,0,15,16,5,0,0,1,16,1,1,0,0,0,17,18,7,0,0,0,18,3,1,0,0,0,19,20,5,17,
  	0,0,20,21,5,1,0,0,21,22,3,6,3,0,22,5,1,0,0,0,23,24,6,3,-1,0,24,25,5,11,
  	0,0,25,26,3,6,3,0,26,27,5,12,0,0,27,37,1,0,0,0,28,29,5,6,0,0,29,37,3,
  	6,3,10,30,31,5,8,0,0,31,37,3,6,3,9,32,37,3,4,2,0,33,37,3,2,1,0,34,37,
  	5,17,0,0,35,37,5,16,0,0,36,23,1,0,0,0,36,28,1,0,0,0,36,30,1,0,0,0,36,
  	32,1,0,0,0,36,33,1,0,0,0,36,34,1,0,0,0,36,35,1,0,0,0,37,52,1,0,0,0,38,
  	39,10,8,0,0,39,40,7,1,0,0,40,51,3,6,3,9,41,42,10,7,0,0,42,43,7,2,0,0,
  	43,51,3,6,3,8,44,45,10,6,0,0,45,46,7,3,0,0,46,51,3,6,3,7,47,48,10,5,0,
  	0,48,49,7,4,0,0,49,51,3,6,3,5,50,38,1,0,0,0,50,41,1,0,0,0,50,44,1,0,0,
  	0,50,47,1,0,0,0,51,54,1,0,0,0,52,50,1,0,0,0,52,53,1,0,0,0,53,7,1,0,0,
  	0,54,52,1,0,0,0,4,13,36,50,52
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calculatorParserStaticData = staticData.release();
}

}

CalculatorParser::CalculatorParser(TokenStream *input) : CalculatorParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CalculatorParser::CalculatorParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CalculatorParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *calculatorParserStaticData->atn, calculatorParserStaticData->decisionToDFA, calculatorParserStaticData->sharedContextCache, options);
}

CalculatorParser::~CalculatorParser() {
  delete _interpreter;
}

const atn::ATN& CalculatorParser::getATN() const {
  return *calculatorParserStaticData->atn;
}

std::string CalculatorParser::getGrammarFileName() const {
  return "Calculator.g4";
}

const std::vector<std::string>& CalculatorParser::getRuleNames() const {
  return calculatorParserStaticData->ruleNames;
}

const dfa::Vocabulary& CalculatorParser::getVocabulary() const {
  return calculatorParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalculatorParser::getSerializedATN() const {
  return calculatorParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

CalculatorParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalculatorParser::ProgramContext::EOF() {
  return getToken(CalculatorParser::EOF, 0);
}

std::vector<tree::TerminalNode *> CalculatorParser::ProgramContext::SEMICOLON() {
  return getTokens(CalculatorParser::SEMICOLON);
}

tree::TerminalNode* CalculatorParser::ProgramContext::SEMICOLON(size_t i) {
  return getToken(CalculatorParser::SEMICOLON, i);
}

std::vector<CalculatorParser::ExpressionContext *> CalculatorParser::ProgramContext::expression() {
  return getRuleContexts<CalculatorParser::ExpressionContext>();
}

CalculatorParser::ExpressionContext* CalculatorParser::ProgramContext::expression(size_t i) {
  return getRuleContext<CalculatorParser::ExpressionContext>(i);
}


size_t CalculatorParser::ProgramContext::getRuleIndex() const {
  return CalculatorParser::RuleProgram;
}

void CalculatorParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void CalculatorParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any CalculatorParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::ProgramContext* CalculatorParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, CalculatorParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(8);
      antlrcpp::downCast<ProgramContext *>(_localctx)->expressionContext = expression(0);
      antlrcpp::downCast<ProgramContext *>(_localctx)->exprs.push_back(antlrcpp::downCast<ProgramContext *>(_localctx)->expressionContext);
      setState(9);
      match(CalculatorParser::SEMICOLON);
      setState(13); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CalculatorParser::MINUS)
      | (1ULL << CalculatorParser::NOT)
      | (1ULL << CalculatorParser::LPAR)
      | (1ULL << CalculatorParser::FALSE)
      | (1ULL << CalculatorParser::TRUE)
      | (1ULL << CalculatorParser::INTEGER)
      | (1ULL << CalculatorParser::VARIABLE))) != 0));
    setState(15);
    match(CalculatorParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanConstantContext ------------------------------------------------------------------

CalculatorParser::BooleanConstantContext::BooleanConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalculatorParser::BooleanConstantContext::TRUE() {
  return getToken(CalculatorParser::TRUE, 0);
}

tree::TerminalNode* CalculatorParser::BooleanConstantContext::FALSE() {
  return getToken(CalculatorParser::FALSE, 0);
}


size_t CalculatorParser::BooleanConstantContext::getRuleIndex() const {
  return CalculatorParser::RuleBooleanConstant;
}

void CalculatorParser::BooleanConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanConstant(this);
}

void CalculatorParser::BooleanConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanConstant(this);
}


std::any CalculatorParser::BooleanConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitBooleanConstant(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::BooleanConstantContext* CalculatorParser::booleanConstant() {
  BooleanConstantContext *_localctx = _tracker.createInstance<BooleanConstantContext>(_ctx, getState());
  enterRule(_localctx, 2, CalculatorParser::RuleBooleanConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    _la = _input->LA(1);
    if (!(_la == CalculatorParser::FALSE

    || _la == CalculatorParser::TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignExpressionContext ------------------------------------------------------------------

CalculatorParser::AssignExpressionContext::AssignExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalculatorParser::AssignExpressionContext::ASSIGN() {
  return getToken(CalculatorParser::ASSIGN, 0);
}

tree::TerminalNode* CalculatorParser::AssignExpressionContext::VARIABLE() {
  return getToken(CalculatorParser::VARIABLE, 0);
}

CalculatorParser::ExpressionContext* CalculatorParser::AssignExpressionContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}


size_t CalculatorParser::AssignExpressionContext::getRuleIndex() const {
  return CalculatorParser::RuleAssignExpression;
}

void CalculatorParser::AssignExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpression(this);
}

void CalculatorParser::AssignExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpression(this);
}


std::any CalculatorParser::AssignExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitAssignExpression(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::AssignExpressionContext* CalculatorParser::assignExpression() {
  AssignExpressionContext *_localctx = _tracker.createInstance<AssignExpressionContext>(_ctx, getState());
  enterRule(_localctx, 4, CalculatorParser::RuleAssignExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    antlrcpp::downCast<AssignExpressionContext *>(_localctx)->v = match(CalculatorParser::VARIABLE);
    setState(20);
    match(CalculatorParser::ASSIGN);
    setState(21);
    antlrcpp::downCast<AssignExpressionContext *>(_localctx)->ex = expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CalculatorParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalculatorParser::ExpressionContext::getRuleIndex() const {
  return CalculatorParser::RuleExpression;
}

void CalculatorParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AsgExprContext ------------------------------------------------------------------

CalculatorParser::AssignExpressionContext* CalculatorParser::AsgExprContext::assignExpression() {
  return getRuleContext<CalculatorParser::AssignExpressionContext>(0);
}

CalculatorParser::AsgExprContext::AsgExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::AsgExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsgExpr(this);
}
void CalculatorParser::AsgExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsgExpr(this);
}

std::any CalculatorParser::AsgExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitAsgExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IConstExprContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::IConstExprContext::INTEGER() {
  return getToken(CalculatorParser::INTEGER, 0);
}

CalculatorParser::IConstExprContext::IConstExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::IConstExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIConstExpr(this);
}
void CalculatorParser::IConstExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIConstExpr(this);
}

std::any CalculatorParser::IConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitIConstExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryArithExprContext ------------------------------------------------------------------

std::vector<CalculatorParser::ExpressionContext *> CalculatorParser::BinaryArithExprContext::expression() {
  return getRuleContexts<CalculatorParser::ExpressionContext>();
}

CalculatorParser::ExpressionContext* CalculatorParser::BinaryArithExprContext::expression(size_t i) {
  return getRuleContext<CalculatorParser::ExpressionContext>(i);
}

tree::TerminalNode* CalculatorParser::BinaryArithExprContext::MULTIPLY() {
  return getToken(CalculatorParser::MULTIPLY, 0);
}

tree::TerminalNode* CalculatorParser::BinaryArithExprContext::DIVIDE() {
  return getToken(CalculatorParser::DIVIDE, 0);
}

tree::TerminalNode* CalculatorParser::BinaryArithExprContext::PLUS() {
  return getToken(CalculatorParser::PLUS, 0);
}

tree::TerminalNode* CalculatorParser::BinaryArithExprContext::MINUS() {
  return getToken(CalculatorParser::MINUS, 0);
}

CalculatorParser::BinaryArithExprContext::BinaryArithExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::BinaryArithExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryArithExpr(this);
}
void CalculatorParser::BinaryArithExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryArithExpr(this);
}

std::any CalculatorParser::BinaryArithExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitBinaryArithExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqExprContext ------------------------------------------------------------------

std::vector<CalculatorParser::ExpressionContext *> CalculatorParser::EqExprContext::expression() {
  return getRuleContexts<CalculatorParser::ExpressionContext>();
}

CalculatorParser::ExpressionContext* CalculatorParser::EqExprContext::expression(size_t i) {
  return getRuleContext<CalculatorParser::ExpressionContext>(i);
}

tree::TerminalNode* CalculatorParser::EqExprContext::EQUAL() {
  return getToken(CalculatorParser::EQUAL, 0);
}

tree::TerminalNode* CalculatorParser::EqExprContext::UNEQUAL() {
  return getToken(CalculatorParser::UNEQUAL, 0);
}

CalculatorParser::EqExprContext::EqExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::EqExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpr(this);
}
void CalculatorParser::EqExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpr(this);
}

std::any CalculatorParser::EqExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitEqExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryNotExprContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::UnaryNotExprContext::NOT() {
  return getToken(CalculatorParser::NOT, 0);
}

CalculatorParser::ExpressionContext* CalculatorParser::UnaryNotExprContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}

CalculatorParser::UnaryNotExprContext::UnaryNotExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::UnaryNotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryNotExpr(this);
}
void CalculatorParser::UnaryNotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryNotExpr(this);
}

std::any CalculatorParser::UnaryNotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitUnaryNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableExprContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::VariableExprContext::VARIABLE() {
  return getToken(CalculatorParser::VARIABLE, 0);
}

CalculatorParser::VariableExprContext::VariableExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::VariableExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableExpr(this);
}
void CalculatorParser::VariableExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableExpr(this);
}

std::any CalculatorParser::VariableExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitVariableExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::ParenExprContext::LPAR() {
  return getToken(CalculatorParser::LPAR, 0);
}

tree::TerminalNode* CalculatorParser::ParenExprContext::RPAR() {
  return getToken(CalculatorParser::RPAR, 0);
}

CalculatorParser::ExpressionContext* CalculatorParser::ParenExprContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}

CalculatorParser::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void CalculatorParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

std::any CalculatorParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryRelExprContext ------------------------------------------------------------------

std::vector<CalculatorParser::ExpressionContext *> CalculatorParser::BinaryRelExprContext::expression() {
  return getRuleContexts<CalculatorParser::ExpressionContext>();
}

CalculatorParser::ExpressionContext* CalculatorParser::BinaryRelExprContext::expression(size_t i) {
  return getRuleContext<CalculatorParser::ExpressionContext>(i);
}

tree::TerminalNode* CalculatorParser::BinaryRelExprContext::LESS() {
  return getToken(CalculatorParser::LESS, 0);
}

tree::TerminalNode* CalculatorParser::BinaryRelExprContext::GREATER() {
  return getToken(CalculatorParser::GREATER, 0);
}

CalculatorParser::BinaryRelExprContext::BinaryRelExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::BinaryRelExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryRelExpr(this);
}
void CalculatorParser::BinaryRelExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryRelExpr(this);
}

std::any CalculatorParser::BinaryRelExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitBinaryRelExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryMinusExprContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::UnaryMinusExprContext::MINUS() {
  return getToken(CalculatorParser::MINUS, 0);
}

CalculatorParser::ExpressionContext* CalculatorParser::UnaryMinusExprContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}

CalculatorParser::UnaryMinusExprContext::UnaryMinusExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::UnaryMinusExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryMinusExpr(this);
}
void CalculatorParser::UnaryMinusExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryMinusExpr(this);
}

std::any CalculatorParser::UnaryMinusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BConstExprContext ------------------------------------------------------------------

CalculatorParser::BooleanConstantContext* CalculatorParser::BConstExprContext::booleanConstant() {
  return getRuleContext<CalculatorParser::BooleanConstantContext>(0);
}

CalculatorParser::BConstExprContext::BConstExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void CalculatorParser::BConstExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBConstExpr(this);
}
void CalculatorParser::BConstExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBConstExpr(this);
}

std::any CalculatorParser::BConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitBConstExpr(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::ExpressionContext* CalculatorParser::expression() {
   return expression(0);
}

CalculatorParser::ExpressionContext* CalculatorParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalculatorParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  CalculatorParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, CalculatorParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(36);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(24);
      match(CalculatorParser::LPAR);
      setState(25);
      antlrcpp::downCast<ParenExprContext *>(_localctx)->ex = expression(0);
      setState(26);
      match(CalculatorParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryMinusExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(28);
      antlrcpp::downCast<UnaryMinusExprContext *>(_localctx)->op = match(CalculatorParser::MINUS);
      setState(29);
      antlrcpp::downCast<UnaryMinusExprContext *>(_localctx)->ex = expression(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UnaryNotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(30);
      antlrcpp::downCast<UnaryNotExprContext *>(_localctx)->op = match(CalculatorParser::NOT);
      setState(31);
      antlrcpp::downCast<UnaryNotExprContext *>(_localctx)->ex = expression(9);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AsgExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(32);
      assignExpression();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<BConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(33);
      booleanConstant();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<VariableExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(34);
      match(CalculatorParser::VARIABLE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(35);
      match(CalculatorParser::INTEGER);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(52);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(50);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryArithExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(38);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(39);
          antlrcpp::downCast<BinaryArithExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalculatorParser::DIVIDE

          || _la == CalculatorParser::MULTIPLY)) {
            antlrcpp::downCast<BinaryArithExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(40);
          antlrcpp::downCast<BinaryArithExprContext *>(_localctx)->right = expression(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryArithExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(41);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(42);
          antlrcpp::downCast<BinaryArithExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalculatorParser::MINUS

          || _la == CalculatorParser::PLUS)) {
            antlrcpp::downCast<BinaryArithExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(43);
          antlrcpp::downCast<BinaryArithExprContext *>(_localctx)->right = expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryRelExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(44);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(45);
          antlrcpp::downCast<BinaryRelExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalculatorParser::GREATER

          || _la == CalculatorParser::LESS)) {
            antlrcpp::downCast<BinaryRelExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(46);
          antlrcpp::downCast<BinaryRelExprContext *>(_localctx)->right = expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(47);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(48);
          antlrcpp::downCast<EqExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalculatorParser::EQUAL

          || _la == CalculatorParser::UNEQUAL)) {
            antlrcpp::downCast<EqExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(49);
          antlrcpp::downCast<EqExprContext *>(_localctx)->right = expression(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(54);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CalculatorParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalculatorParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void CalculatorParser::initialize() {
  std::call_once(calculatorParserOnceFlag, calculatorParserInitialize);
}
