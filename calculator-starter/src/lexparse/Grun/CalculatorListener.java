// Generated from Calculator.g4 by ANTLR 4.10.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CalculatorParser}.
 */
public interface CalculatorListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CalculatorParser#text}.
	 * @param ctx the parse tree
	 */
	void enterText(CalculatorParser.TextContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalculatorParser#text}.
	 * @param ctx the parse tree
	 */
	void exitText(CalculatorParser.TextContext ctx);
}