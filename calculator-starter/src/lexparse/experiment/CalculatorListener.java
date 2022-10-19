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
	 * Enter a parse tree produced by the {@code AsgExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAsgExpr(CalculatorParser.AsgExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AsgExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAsgExpr(CalculatorParser.AsgExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IConstExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterIConstExpr(CalculatorParser.IConstExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IConstExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitIConstExpr(CalculatorParser.IConstExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryArithExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBinaryArithExpr(CalculatorParser.BinaryArithExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryArithExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBinaryArithExpr(CalculatorParser.BinaryArithExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code EqExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterEqExpr(CalculatorParser.EqExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code EqExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitEqExpr(CalculatorParser.EqExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryNotExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryNotExpr(CalculatorParser.UnaryNotExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryNotExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryNotExpr(CalculatorParser.UnaryNotExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterVariableExpr(CalculatorParser.VariableExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitVariableExpr(CalculatorParser.VariableExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterParenExpr(CalculatorParser.ParenExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitParenExpr(CalculatorParser.ParenExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryRelExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBinaryRelExpr(CalculatorParser.BinaryRelExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryRelExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBinaryRelExpr(CalculatorParser.BinaryRelExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryMinusExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryMinusExpr(CalculatorParser.UnaryMinusExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryMinusExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryMinusExpr(CalculatorParser.UnaryMinusExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BConstExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBConstExpr(CalculatorParser.BConstExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BConstExpr}
	 * labeled alternative in {@link CalculatorParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBConstExpr(CalculatorParser.BConstExprContext ctx);
}