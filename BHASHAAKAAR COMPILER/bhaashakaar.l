%{
#include "bhaashakaar.tab.h"
#include <stdio.h>
#include <string.h>

int line_num = 1;
%}

%%

"program"        { return PROGRAM; }
"ant"            { return END; }
"var"            { return VAR; }
"return"         { return RETURN; }
"int"            { return INT; }
"agar"           { return IF; }
"nahi_to"        { return ELSE; }
"jab_tak"        { return WHILE; }
"ke_liye"        { return FOR; }
"sankhya"        { return FUNCTION; }
"chhap"          { return PRINT; }

"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return TIMES; }
"/"              { return DIVIDE; }
"%"              { return MOD; }
">"              { return GT; }
"<"              { return LT; }
"="              { return ASSIGN; }

"("              { return LPAREN; }
")"              { return RPAREN; }
"{"              { return LBRACE; }
"}"              { return RBRACE; }
";"              { return SEMICOLON; }

[0-9]+           { yylval.ival = atoi(yytext); return INT_LITERAL; }
\".*\"           { yylval.sval = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval.sval = strdup(yytext);
                    return IDENTIFIER;
                  }

[ \t\r]+          ; // ignore whitespace
\n                { line_num++; }

.                 { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}