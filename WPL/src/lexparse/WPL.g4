/*
 * Grammar file for WPI Programming Language (WPL).
 */
grammar WPL;

// Parser rules
compilationUnit   : cuComponent+ EOF;

cuComponent       : varDeclaration | procedure | function | externDeclaration ;
varDeclaration    : scalarDeclaration | arrayDeclaration ;
scalarDeclaration : (t=type| VAR) scalars+=scalar (',' scalars+=scalar)* ';' ;
scalar            : id=ID varInitializer? ;
arrayDeclaration  : t=type '[' INTEGER ']' id=ID ';' ;       // No dynamic arrays, type not inferred
type              : b=BOOL | i=INT | s=STR ;  
varInitializer    : '<-' c=constant ;
externDeclaration : 'extern' (externProcHeader | externFuncHeader) ';';

procedure         : procHeader block ;
procHeader        : 'proc' id=ID '(' p=params? ')' ;
externProcHeader  : 'proc' id=ID '(' ((params ',' ELLIPSIS) | params? | ELLIPSIS?) ')' ;
function          : funcHeader block  ;
funcHeader        : t=type 'func' id=ID '(' p=params? ')' ;
externFuncHeader  : t=type 'func' id=ID '(' ((params ',' ELLIPSIS) | params? | ELLIPSIS?) ')' ;

param             : t=type id=ID;
params            : (ps+=param (',' ps+=param)*) ;
block            : '{' (statement | varDeclaration | block)+ '}' ;   // Change to expr ???

statement         : assignment
                  | loop
                  | select
                  | conditional
                  | call
                  | block
                  | return
                  ;

loop              : 'while' e=expr 'do' block ;
conditional       : 'if' e=expr 'then'? block ('else' block)? ;
select            : 'select' '{' selectAlt+ '}' ;
selectAlt         : e=expr ':' s=statement ;  
call              : id=ID '(' arguments? ')' ';' ;
arguments         : (arg (',' arg)*) ;  
arg               : (id=ID | c=constant) ; 
return            : 'return' expr? ';' ;

constant          : i=INTEGER | s=STRING | b=BOOLEAN ;
assignment        : target=ID '<-' e=expr ';' 
                  | arrayIndex '<-' e=expr ';' ;
arrayIndex        : id=ID '[' expr ']' ;

expr              : 
                  fname=ID '(' (args+=expr (',' args+=expr)*)? ')'        # FuncCallExpr
                  | arrayIndex                                            # SubscriptExpr
                  | <assoc=right> '-' expr                                # UMinusExpr
                  | <assoc=right> '~' expr                                # NotExpr
                  | left=expr (MUL | DIV) right=expr                      # BinaryArithExpr 
                  | left=expr (PLUS | MINUS) right=expr                   # BinaryArithExpr
                  | left=expr (LESS | LEQ | GTR | GEQ) right=expr         # RelExpr
                  | <assoc=right> left=expr (EQUAL | NEQ) right=expr      # EqExpr
                  | left=expr AND right=expr                              # AndExpr
                  | left=expr OR right=expr                               # OrExpr
                  | '(' expr ')'                                          # ParenExpr
                  | arrayname=ID '.' 'length'                             # ArrayLengthExpr
                  | id=ID                                                 # IDExpr
                  | constant                                              # ConstExpr
                  ;

// Lexer rules
// Keywords
BOOL              : 'boolean' ;
INT               : 'int' ;
STR               : 'str' ;
VAR               : 'var' ;

PROC              : 'proc' ;
FUNC              : 'func' ;
EXTERN            : 'extern' ;
RETURN            : 'return' ;
WHILE             : 'while' ;
DO                : 'do' ;
SELECT            : 'select' ;
END               : 'end' ;
IF                : 'if' ;
THEN              : 'then' ;
ELSE              : 'else' ;
LENGTH            : 'length' ;

// Operators
AND               : '&' ;
ASSIGN            : '<-' ;
EQUAL					    :	'=' ;
GEQ               : '>=' ;
GTR               : '>' ;
LEQ               : '<=' ;
LESS					    :	'<' ;
MINUS					    :	'-' ;
NEQ               : '~=' ;
OR                : '|' ;
PLUS					    :	'+' ;
DIV 					    :	'/' ;
MUL 					    :	'*' ;
NOT 					    :	'~' ;

// Punctuation and delimiters
COMMA             : ',' ;
SEMICOLON         : ';' ;
ELLIPSIS          : '...' ;
DOT               : '.' ;

LBRACKET          : '[' ;
RBRACKET          : ']' ;
LPAR              : '(' ;
RPAR              : ')' ;
LBRACE					  : '{' ;
RBRACE					  :	'}' ;

// Literals, identifiers, and whitespace
WS 						    :	[ \t\r\n\f]+ -> skip ;
INTEGER					  :	DIGIT+ ;
BOOLEAN           : 'true' | 'false' ;
ID      				  : LETTER (LETTER|DIGIT|UNDERSCORE)* ;
STRING			      : '"' ('\\'. | ~[\n])*? '"' ;

// Comments
COMMENT				     : 	(INLINE_COMMENT|STD_COMMENT) -> skip ;
fragment INLINE_COMMENT  :	'#' .*? ('\n'|EOF);
fragment STD_COMMENT	 :	'(*' (STD_COMMENT | .)*? '*)' ;
fragment UNDERSCORE      :   '_' ;

// Fragments
fragment DIGIT			:	[0-9] ;
fragment UPPER          :   [A-Z] ;
fragment LOWER          :   [a-z] ;
fragment LETTER			:	UPPER | LOWER ;
