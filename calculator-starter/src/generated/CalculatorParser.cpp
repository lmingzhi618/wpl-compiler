
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
      "text"
    },
    std::vector<std::string>{
      "", "':='", "'/'", "'='", "'>'", "'<'", "'-'", "'*'", "'~'", "'+'", 
      "'~='", "'('", "')'", "';'", "'false'", "'true'"
    },
    std::vector<std::string>{
      "", "ASSIGN", "DIVIDE", "EQUAL", "GREATER", "LESS", "MINUS", "MULTIPLY", 
      "NOT", "PLUS", "UNEQUAL", "LPAR", "RPAR", "SEMICOLON", "FALSE", "TRUE", 
      "INTEGER", "VARIABLE", "WORD", "WS", "ANY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,20,6,2,0,7,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,4,0,2,1,0,0,0,2,3,5,20,0,
  	0,3,4,5,0,0,1,4,1,1,0,0,0,0
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


//----------------- TextContext ------------------------------------------------------------------

CalculatorParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalculatorParser::TextContext::ANY() {
  return getToken(CalculatorParser::ANY, 0);
}

tree::TerminalNode* CalculatorParser::TextContext::EOF() {
  return getToken(CalculatorParser::EOF, 0);
}


size_t CalculatorParser::TextContext::getRuleIndex() const {
  return CalculatorParser::RuleText;
}

void CalculatorParser::TextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterText(this);
}

void CalculatorParser::TextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitText(this);
}


std::any CalculatorParser::TextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitText(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::TextContext* CalculatorParser::text() {
  TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, getState());
  enterRule(_localctx, 0, CalculatorParser::RuleText);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2);
    match(CalculatorParser::ANY);
    setState(3);
    match(CalculatorParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CalculatorParser::initialize() {
  std::call_once(calculatorParserOnceFlag, calculatorParserInitialize);
}
