// Generated from Calculator.g4 by ANTLR 4.10.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CalculatorLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.10.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ASSIGN=1, DIVIDE=2, EQUAL=3, GREATER=4, LESS=5, MINUS=6, MULTIPLY=7, NOT=8, 
		PLUS=9, UNEQUAL=10, LPAR=11, RPAR=12, SEMICOLON=13, FALSE=14, TRUE=15, 
		INTEGER=16, VARIABLE=17, WS=18, WORD=19, COMMENT1=20, COMMENT2=21;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"ASSIGN", "DIVIDE", "EQUAL", "GREATER", "LESS", "MINUS", "MULTIPLY", 
			"NOT", "PLUS", "UNEQUAL", "LPAR", "RPAR", "SEMICOLON", "FALSE", "TRUE", 
			"INTEGER", "VARIABLE", "WS", "WORD", "COMMENT1", "COMMENT2"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "':='", "'/'", "'='", "'>'", "'<'", "'-'", "'*'", "'~'", "'+'", 
			"'~='", "'('", "')'", "';'", "'false'", "'true'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ASSIGN", "DIVIDE", "EQUAL", "GREATER", "LESS", "MINUS", "MULTIPLY", 
			"NOT", "PLUS", "UNEQUAL", "LPAR", "RPAR", "SEMICOLON", "FALSE", "TRUE", 
			"INTEGER", "VARIABLE", "WS", "WORD", "COMMENT1", "COMMENT2"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public CalculatorLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Calculator.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0015\u007f\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001"+
		"\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0004\u000f"+
		"T\b\u000f\u000b\u000f\f\u000fU\u0001\u0010\u0004\u0010Y\b\u0010\u000b"+
		"\u0010\f\u0010Z\u0001\u0011\u0004\u0011^\b\u0011\u000b\u0011\f\u0011_"+
		"\u0001\u0011\u0001\u0011\u0001\u0012\u0004\u0012e\b\u0012\u000b\u0012"+
		"\f\u0012f\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0005\u0013"+
		"m\b\u0013\n\u0013\f\u0013p\t\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014y\b\u0014"+
		"\n\u0014\f\u0014|\t\u0014\u0001\u0014\u0001\u0014\u0002nz\u0000\u0015"+
		"\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r"+
		"\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e"+
		"\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\'\u0014)\u0015\u0001\u0000"+
		"\u0003\u0001\u000009\u0002\u0000AZaz\u0003\u0000\t\n\r\r  \u0084\u0000"+
		"\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000"+
		"\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000"+
		"\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r"+
		"\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011"+
		"\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015"+
		"\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019"+
		"\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d"+
		"\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001"+
		"\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000"+
		"\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000\u0000\u0000"+
		"\u0001+\u0001\u0000\u0000\u0000\u0003.\u0001\u0000\u0000\u0000\u00050"+
		"\u0001\u0000\u0000\u0000\u00072\u0001\u0000\u0000\u0000\t4\u0001\u0000"+
		"\u0000\u0000\u000b6\u0001\u0000\u0000\u0000\r8\u0001\u0000\u0000\u0000"+
		"\u000f:\u0001\u0000\u0000\u0000\u0011<\u0001\u0000\u0000\u0000\u0013>"+
		"\u0001\u0000\u0000\u0000\u0015A\u0001\u0000\u0000\u0000\u0017C\u0001\u0000"+
		"\u0000\u0000\u0019E\u0001\u0000\u0000\u0000\u001bG\u0001\u0000\u0000\u0000"+
		"\u001dM\u0001\u0000\u0000\u0000\u001fS\u0001\u0000\u0000\u0000!X\u0001"+
		"\u0000\u0000\u0000#]\u0001\u0000\u0000\u0000%d\u0001\u0000\u0000\u0000"+
		"\'h\u0001\u0000\u0000\u0000)t\u0001\u0000\u0000\u0000+,\u0005:\u0000\u0000"+
		",-\u0005=\u0000\u0000-\u0002\u0001\u0000\u0000\u0000./\u0005/\u0000\u0000"+
		"/\u0004\u0001\u0000\u0000\u000001\u0005=\u0000\u00001\u0006\u0001\u0000"+
		"\u0000\u000023\u0005>\u0000\u00003\b\u0001\u0000\u0000\u000045\u0005<"+
		"\u0000\u00005\n\u0001\u0000\u0000\u000067\u0005-\u0000\u00007\f\u0001"+
		"\u0000\u0000\u000089\u0005*\u0000\u00009\u000e\u0001\u0000\u0000\u0000"+
		":;\u0005~\u0000\u0000;\u0010\u0001\u0000\u0000\u0000<=\u0005+\u0000\u0000"+
		"=\u0012\u0001\u0000\u0000\u0000>?\u0005~\u0000\u0000?@\u0005=\u0000\u0000"+
		"@\u0014\u0001\u0000\u0000\u0000AB\u0005(\u0000\u0000B\u0016\u0001\u0000"+
		"\u0000\u0000CD\u0005)\u0000\u0000D\u0018\u0001\u0000\u0000\u0000EF\u0005"+
		";\u0000\u0000F\u001a\u0001\u0000\u0000\u0000GH\u0005f\u0000\u0000HI\u0005"+
		"a\u0000\u0000IJ\u0005l\u0000\u0000JK\u0005s\u0000\u0000KL\u0005e\u0000"+
		"\u0000L\u001c\u0001\u0000\u0000\u0000MN\u0005t\u0000\u0000NO\u0005r\u0000"+
		"\u0000OP\u0005u\u0000\u0000PQ\u0005e\u0000\u0000Q\u001e\u0001\u0000\u0000"+
		"\u0000RT\u0007\u0000\u0000\u0000SR\u0001\u0000\u0000\u0000TU\u0001\u0000"+
		"\u0000\u0000US\u0001\u0000\u0000\u0000UV\u0001\u0000\u0000\u0000V \u0001"+
		"\u0000\u0000\u0000WY\u0007\u0001\u0000\u0000XW\u0001\u0000\u0000\u0000"+
		"YZ\u0001\u0000\u0000\u0000ZX\u0001\u0000\u0000\u0000Z[\u0001\u0000\u0000"+
		"\u0000[\"\u0001\u0000\u0000\u0000\\^\u0007\u0002\u0000\u0000]\\\u0001"+
		"\u0000\u0000\u0000^_\u0001\u0000\u0000\u0000_]\u0001\u0000\u0000\u0000"+
		"_`\u0001\u0000\u0000\u0000`a\u0001\u0000\u0000\u0000ab\u0006\u0011\u0000"+
		"\u0000b$\u0001\u0000\u0000\u0000ce\u0007\u0001\u0000\u0000dc\u0001\u0000"+
		"\u0000\u0000ef\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000fg\u0001"+
		"\u0000\u0000\u0000g&\u0001\u0000\u0000\u0000hi\u0005/\u0000\u0000ij\u0005"+
		"*\u0000\u0000jn\u0001\u0000\u0000\u0000km\t\u0000\u0000\u0000lk\u0001"+
		"\u0000\u0000\u0000mp\u0001\u0000\u0000\u0000no\u0001\u0000\u0000\u0000"+
		"nl\u0001\u0000\u0000\u0000oq\u0001\u0000\u0000\u0000pn\u0001\u0000\u0000"+
		"\u0000qr\u0005*\u0000\u0000rs\u0005/\u0000\u0000s(\u0001\u0000\u0000\u0000"+
		"tu\u0005/\u0000\u0000uv\u0005/\u0000\u0000vz\u0001\u0000\u0000\u0000w"+
		"y\t\u0000\u0000\u0000xw\u0001\u0000\u0000\u0000y|\u0001\u0000\u0000\u0000"+
		"z{\u0001\u0000\u0000\u0000zx\u0001\u0000\u0000\u0000{}\u0001\u0000\u0000"+
		"\u0000|z\u0001\u0000\u0000\u0000}~\u0005\n\u0000\u0000~*\u0001\u0000\u0000"+
		"\u0000\u0007\u0000UZ_fnz\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}