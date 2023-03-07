// Generated from WPL.g4 by ANTLR 4.10.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link WPLParser}.
 */
public interface WPLListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link WPLParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(WPLParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(WPLParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#cuComponent}.
	 * @param ctx the parse tree
	 */
	void enterCuComponent(WPLParser.CuComponentContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#cuComponent}.
	 * @param ctx the parse tree
	 */
	void exitCuComponent(WPLParser.CuComponentContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#varDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterVarDeclaration(WPLParser.VarDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#varDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitVarDeclaration(WPLParser.VarDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#scalarDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterScalarDeclaration(WPLParser.ScalarDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#scalarDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitScalarDeclaration(WPLParser.ScalarDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#scalar}.
	 * @param ctx the parse tree
	 */
	void enterScalar(WPLParser.ScalarContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#scalar}.
	 * @param ctx the parse tree
	 */
	void exitScalar(WPLParser.ScalarContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#arrayDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterArrayDeclaration(WPLParser.ArrayDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#arrayDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitArrayDeclaration(WPLParser.ArrayDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(WPLParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(WPLParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#varInitializer}.
	 * @param ctx the parse tree
	 */
	void enterVarInitializer(WPLParser.VarInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#varInitializer}.
	 * @param ctx the parse tree
	 */
	void exitVarInitializer(WPLParser.VarInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#externDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterExternDeclaration(WPLParser.ExternDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#externDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitExternDeclaration(WPLParser.ExternDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#procedure}.
	 * @param ctx the parse tree
	 */
	void enterProcedure(WPLParser.ProcedureContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#procedure}.
	 * @param ctx the parse tree
	 */
	void exitProcedure(WPLParser.ProcedureContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#procHeader}.
	 * @param ctx the parse tree
	 */
	void enterProcHeader(WPLParser.ProcHeaderContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#procHeader}.
	 * @param ctx the parse tree
	 */
	void exitProcHeader(WPLParser.ProcHeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#externProcHeader}.
	 * @param ctx the parse tree
	 */
	void enterExternProcHeader(WPLParser.ExternProcHeaderContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#externProcHeader}.
	 * @param ctx the parse tree
	 */
	void exitExternProcHeader(WPLParser.ExternProcHeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(WPLParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(WPLParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#funcHeader}.
	 * @param ctx the parse tree
	 */
	void enterFuncHeader(WPLParser.FuncHeaderContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#funcHeader}.
	 * @param ctx the parse tree
	 */
	void exitFuncHeader(WPLParser.FuncHeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#externFuncHeader}.
	 * @param ctx the parse tree
	 */
	void enterExternFuncHeader(WPLParser.ExternFuncHeaderContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#externFuncHeader}.
	 * @param ctx the parse tree
	 */
	void exitExternFuncHeader(WPLParser.ExternFuncHeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#param}.
	 * @param ctx the parse tree
	 */
	void enterParam(WPLParser.ParamContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#param}.
	 * @param ctx the parse tree
	 */
	void exitParam(WPLParser.ParamContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#params}.
	 * @param ctx the parse tree
	 */
	void enterParams(WPLParser.ParamsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#params}.
	 * @param ctx the parse tree
	 */
	void exitParams(WPLParser.ParamsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(WPLParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(WPLParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(WPLParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(WPLParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#loop}.
	 * @param ctx the parse tree
	 */
	void enterLoop(WPLParser.LoopContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#loop}.
	 * @param ctx the parse tree
	 */
	void exitLoop(WPLParser.LoopContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#conditional}.
	 * @param ctx the parse tree
	 */
	void enterConditional(WPLParser.ConditionalContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#conditional}.
	 * @param ctx the parse tree
	 */
	void exitConditional(WPLParser.ConditionalContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#select}.
	 * @param ctx the parse tree
	 */
	void enterSelect(WPLParser.SelectContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#select}.
	 * @param ctx the parse tree
	 */
	void exitSelect(WPLParser.SelectContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#selectAlt}.
	 * @param ctx the parse tree
	 */
	void enterSelectAlt(WPLParser.SelectAltContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#selectAlt}.
	 * @param ctx the parse tree
	 */
	void exitSelectAlt(WPLParser.SelectAltContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#call}.
	 * @param ctx the parse tree
	 */
	void enterCall(WPLParser.CallContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#call}.
	 * @param ctx the parse tree
	 */
	void exitCall(WPLParser.CallContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(WPLParser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(WPLParser.ArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#arg}.
	 * @param ctx the parse tree
	 */
	void enterArg(WPLParser.ArgContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#arg}.
	 * @param ctx the parse tree
	 */
	void exitArg(WPLParser.ArgContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#return}.
	 * @param ctx the parse tree
	 */
	void enterReturn(WPLParser.ReturnContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#return}.
	 * @param ctx the parse tree
	 */
	void exitReturn(WPLParser.ReturnContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(WPLParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(WPLParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(WPLParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(WPLParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link WPLParser#arrayIndex}.
	 * @param ctx the parse tree
	 */
	void enterArrayIndex(WPLParser.ArrayIndexContext ctx);
	/**
	 * Exit a parse tree produced by {@link WPLParser#arrayIndex}.
	 * @param ctx the parse tree
	 */
	void exitArrayIndex(WPLParser.ArrayIndexContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AndExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAndExpr(WPLParser.AndExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AndExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAndExpr(WPLParser.AndExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IDExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterIDExpr(WPLParser.IDExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IDExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitIDExpr(WPLParser.IDExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ConstExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterConstExpr(WPLParser.ConstExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ConstExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitConstExpr(WPLParser.ConstExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SubscriptExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSubscriptExpr(WPLParser.SubscriptExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SubscriptExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSubscriptExpr(WPLParser.SubscriptExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code RelExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterRelExpr(WPLParser.RelExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code RelExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitRelExpr(WPLParser.RelExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArrayLengthExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterArrayLengthExpr(WPLParser.ArrayLengthExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArrayLengthExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitArrayLengthExpr(WPLParser.ArrayLengthExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UMinusExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUMinusExpr(WPLParser.UMinusExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UMinusExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUMinusExpr(WPLParser.UMinusExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code OrExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterOrExpr(WPLParser.OrExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code OrExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitOrExpr(WPLParser.OrExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryArithExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryArithExpr(WPLParser.BinaryArithExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryArithExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryArithExpr(WPLParser.BinaryArithExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code EqExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEqExpr(WPLParser.EqExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code EqExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEqExpr(WPLParser.EqExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code NotExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterNotExpr(WPLParser.NotExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code NotExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitNotExpr(WPLParser.NotExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParenExpr(WPLParser.ParenExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParenExpr(WPLParser.ParenExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FuncCallExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFuncCallExpr(WPLParser.FuncCallExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FuncCallExpr}
	 * labeled alternative in {@link WPLParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFuncCallExpr(WPLParser.FuncCallExprContext ctx);
}