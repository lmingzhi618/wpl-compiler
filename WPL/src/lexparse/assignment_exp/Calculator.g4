/*
 * Grammar file for the Calculator application.
 */
grammar Calculator;

program         :   (exprs+=expression ';')+ EOF ;

booleanConstant :   TRUE | FALSE ;

assignExpression:   <assoc=right> v=VARIABLE ':=' expression;

expression      :
                '(' ex=expression ')'
                | <assoc=right> op='-' ex=expression
                | <assoc=right> op='~' ex=expression
                | left=expression op=('*' | '/') right=expression
                | left=expression op=('+' | '-') right=expression
                | left=expression op=('<' | '>') right=expression
                | <assoc=right> 
                  left=expression op=('=' | '~=') right=expression
                | assignExpression
                | booleanConstant
                | VARIABLE
                | INTEGER ;

// Lexer rules
// Operators
ASSIGN      : ':=' ;
DIVIDE      : '/' ;
EQUAL       : '=' ;
GREATER     : '>' ;
LESS        : '<' ;
MINUS       : '-' ;
MULTIPLY    : '*' ;
NOT         : '~' ;
PLUS        : '+' ;
UNEQUAL     : '~=' ;

// Separators (punctuation)
LPAR        : '(' ;
RPAR        : ')' ;
SEMICOLON   : ';' ;

// Boolean constants
FALSE       : 'false' ;
TRUE        : 'true' ;

// Other
INTEGER     : [0-9]+ ;
VARIABLE    : [a-zA-Z]+ ;

WS          : [ \n\t\r]+ -> skip;
