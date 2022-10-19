
// Generated from Calculator.g4 by ANTLR 4.10.1


#include "CalculatorLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CalculatorLexerStaticData final {
  CalculatorLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalculatorLexerStaticData(const CalculatorLexerStaticData&) = delete;
  CalculatorLexerStaticData(CalculatorLexerStaticData&&) = delete;
  CalculatorLexerStaticData& operator=(const CalculatorLexerStaticData&) = delete;
  CalculatorLexerStaticData& operator=(CalculatorLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag calculatorlexerLexerOnceFlag;
CalculatorLexerStaticData *calculatorlexerLexerStaticData = nullptr;

void calculatorlexerLexerInitialize() {
  assert(calculatorlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CalculatorLexerStaticData>(
    std::vector<std::string>{
      "ASSIGN", "DIVIDE", "EQUAL", "GREATER", "LESS", "MINUS", "MULTIPLY", 
      "NOT", "PLUS", "UNEQUAL", "LPAR", "RPAR", "SEMICOLON", "FALSE", "TRUE", 
      "INTEGER", "VARIABLE", "WS", "WORD", "COMMENT1", "COMMENT2"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "':='", "'/'", "'='", "'>'", "'<'", "'-'", "'*'", "'~'", "'+'", 
      "'~='", "'('", "')'", "';'", "'false'", "'true'"
    },
    std::vector<std::string>{
      "", "ASSIGN", "DIVIDE", "EQUAL", "GREATER", "LESS", "MINUS", "MULTIPLY", 
      "NOT", "PLUS", "UNEQUAL", "LPAR", "RPAR", "SEMICOLON", "FALSE", "TRUE", 
      "INTEGER", "VARIABLE", "WS", "WORD", "COMMENT1", "COMMENT2"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,21,127,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,
  	1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,
  	8,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,14,1,14,1,14,1,14,1,14,1,15,4,15,84,8,15,11,15,12,15,85,1,16,4,
  	16,89,8,16,11,16,12,16,90,1,17,4,17,94,8,17,11,17,12,17,95,1,17,1,17,
  	1,18,4,18,101,8,18,11,18,12,18,102,1,19,1,19,1,19,1,19,5,19,109,8,19,
  	10,19,12,19,112,9,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,5,20,121,8,20,
  	10,20,12,20,124,9,20,1,20,1,20,2,110,122,0,21,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,
  	37,19,39,20,41,21,1,0,3,1,0,48,57,2,0,65,90,97,122,3,0,9,10,13,13,32,
  	32,132,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,
  	11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,
  	0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,
  	0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,1,
  	43,1,0,0,0,3,46,1,0,0,0,5,48,1,0,0,0,7,50,1,0,0,0,9,52,1,0,0,0,11,54,
  	1,0,0,0,13,56,1,0,0,0,15,58,1,0,0,0,17,60,1,0,0,0,19,62,1,0,0,0,21,65,
  	1,0,0,0,23,67,1,0,0,0,25,69,1,0,0,0,27,71,1,0,0,0,29,77,1,0,0,0,31,83,
  	1,0,0,0,33,88,1,0,0,0,35,93,1,0,0,0,37,100,1,0,0,0,39,104,1,0,0,0,41,
  	116,1,0,0,0,43,44,5,58,0,0,44,45,5,61,0,0,45,2,1,0,0,0,46,47,5,47,0,0,
  	47,4,1,0,0,0,48,49,5,61,0,0,49,6,1,0,0,0,50,51,5,62,0,0,51,8,1,0,0,0,
  	52,53,5,60,0,0,53,10,1,0,0,0,54,55,5,45,0,0,55,12,1,0,0,0,56,57,5,42,
  	0,0,57,14,1,0,0,0,58,59,5,126,0,0,59,16,1,0,0,0,60,61,5,43,0,0,61,18,
  	1,0,0,0,62,63,5,126,0,0,63,64,5,61,0,0,64,20,1,0,0,0,65,66,5,40,0,0,66,
  	22,1,0,0,0,67,68,5,41,0,0,68,24,1,0,0,0,69,70,5,59,0,0,70,26,1,0,0,0,
  	71,72,5,102,0,0,72,73,5,97,0,0,73,74,5,108,0,0,74,75,5,115,0,0,75,76,
  	5,101,0,0,76,28,1,0,0,0,77,78,5,116,0,0,78,79,5,114,0,0,79,80,5,117,0,
  	0,80,81,5,101,0,0,81,30,1,0,0,0,82,84,7,0,0,0,83,82,1,0,0,0,84,85,1,0,
  	0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,32,1,0,0,0,87,89,7,1,0,0,88,87,1,0,
  	0,0,89,90,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,34,1,0,0,0,92,94,7,2,
  	0,0,93,92,1,0,0,0,94,95,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,97,1,0,
  	0,0,97,98,6,17,0,0,98,36,1,0,0,0,99,101,7,1,0,0,100,99,1,0,0,0,101,102,
  	1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,38,1,0,0,0,104,105,5,47,0,
  	0,105,106,5,42,0,0,106,110,1,0,0,0,107,109,9,0,0,0,108,107,1,0,0,0,109,
  	112,1,0,0,0,110,111,1,0,0,0,110,108,1,0,0,0,111,113,1,0,0,0,112,110,1,
  	0,0,0,113,114,5,42,0,0,114,115,5,47,0,0,115,40,1,0,0,0,116,117,5,47,0,
  	0,117,118,5,47,0,0,118,122,1,0,0,0,119,121,9,0,0,0,120,119,1,0,0,0,121,
  	124,1,0,0,0,122,123,1,0,0,0,122,120,1,0,0,0,123,125,1,0,0,0,124,122,1,
  	0,0,0,125,126,5,10,0,0,126,42,1,0,0,0,7,0,85,90,95,102,110,122,1,6,0,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calculatorlexerLexerStaticData = staticData.release();
}

}

CalculatorLexer::CalculatorLexer(CharStream *input) : Lexer(input) {
  CalculatorLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *calculatorlexerLexerStaticData->atn, calculatorlexerLexerStaticData->decisionToDFA, calculatorlexerLexerStaticData->sharedContextCache);
}

CalculatorLexer::~CalculatorLexer() {
  delete _interpreter;
}

std::string CalculatorLexer::getGrammarFileName() const {
  return "Calculator.g4";
}

const std::vector<std::string>& CalculatorLexer::getRuleNames() const {
  return calculatorlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CalculatorLexer::getChannelNames() const {
  return calculatorlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CalculatorLexer::getModeNames() const {
  return calculatorlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CalculatorLexer::getVocabulary() const {
  return calculatorlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalculatorLexer::getSerializedATN() const {
  return calculatorlexerLexerStaticData->serializedATN;
}

const atn::ATN& CalculatorLexer::getATN() const {
  return *calculatorlexerLexerStaticData->atn;
}




void CalculatorLexer::initialize() {
  std::call_once(calculatorlexerLexerOnceFlag, calculatorlexerLexerInitialize);
}
