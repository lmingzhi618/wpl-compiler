// Generated from Calculator.g4 by ANTLR 4.10.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CalculatorParser}.
 */
public interface CalculatorListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CalculatorParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(CalculatorParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalculatorParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(CalculatorParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalculatorParser#booleanConstant}.
	 * @param ctx the parse tree
	 */
	void enterBooleanConstant(CalculatorParser.BooleanConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalculatorParser#booleanConstant}.
	 * @param ctx the parse tree
	 */
	void exitBooleanConstant(CalculatorParser.BooleanConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalculatorParser#assignExpression}.
	 * @param ctx the parse tree
	 */
	void enterAssignExpression(CalculatorParser.AssignExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalculatorParser#assignExpression}.
	 * @param ctx the parse tree
	 */
	void exitAssignExpression(CalculatorParser.AssignExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(CalculatorParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(CalculatorParser.ExpressionContext ctx);
}