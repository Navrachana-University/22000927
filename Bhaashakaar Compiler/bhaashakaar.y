%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int line_num;
extern FILE* yyin;
void yyerror(const char* s);
void yyrestart(FILE *input_file);

int temp_var_counter = 0;
int label_counter = 0;

typedef struct ExpressionResult {
    char* code;
    char* addr;
} ExpressionResult;

char* new_temp() {
    char* temp = (char*)malloc(16);
    sprintf(temp, "t%d", temp_var_counter++);
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(16);
    sprintf(label, "L%d", label_counter++);
    return label;
}

ExpressionResult* create_expr_result() {
    ExpressionResult* result = (ExpressionResult*)malloc(sizeof(ExpressionResult));
    result->code = strdup("");
    result->addr = NULL;
    return result;
}

void append_code(ExpressionResult* result, const char* code) {
    char* new_code = (char*)malloc(strlen(result->code) + strlen(code) + 1);
    strcpy(new_code, result->code);
    strcat(new_code, code);
    free(result->code);
    result->code = new_code;
}
%}

%union {
    int ival;
    char* sval;
    struct ExpressionResult* expr;
}

%token PROGRAM END VAR RETURN INT IF ELSE WHILE FOR FUNCTION PRINT
%token PLUS MINUS TIMES DIVIDE MOD GT LT ASSIGN
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token <ival> INT_LITERAL
%token <sval> STRING_LITERAL
%token <sval> IDENTIFIER

%type <expr> program_start program program_body program_declaration
%type <expr> statement if_statement while_statement for_statement
%type <expr> statement_list block_statement function_declaration
%type <expr> variable_declaration assignment_expression expression
%type <expr> relational_expression additive_expression multiplicative_expression
%type <expr> unary_expression postfix_expression primary_expression
%type <expr> type basic_type

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGN
%left LT GT
%left PLUS MINUS
%left TIMES DIVIDE MOD

%start program_start

%%

program_start:
    program
    ;

program:
    program_body
    {
        $$ = $1;
    }
    ;

program_body:
    program_declaration
    {
        $$ = $1;
    }
    | program_body program_declaration
    {
        $$ = $1;
        append_code($$, $2->code);
    }
    ;

program_declaration:
    PROGRAM IDENTIFIER LBRACE function_declaration RBRACE END
    {
        $$ = $4;
        printf("// Three-address code for Hindi program '%s'\n", $2);
        printf("%s", $4->code);
    }
    | PROGRAM IDENTIFIER LBRACE function_declaration statement_list RBRACE END
    {
        $$ = $5;
        append_code($$, $4->code);
        printf("// Three-address code for Hindi program '%s'\n", $2);
        printf("%s", $$->code);
    }
    ;

statement_list:
    statement
    {
        $$ = $1;
    }
    | statement_list statement
    {
        $$ = $1;
        append_code($$, $2->code);
    }
    ;

statement:
    variable_declaration SEMICOLON
    {
        $$ = $1;
    }
    | assignment_expression SEMICOLON
    {
        $$ = $1;
    }
    | PRINT expression SEMICOLON
    {
        $$ = $2;
        char code[128];
        sprintf(code, "print %s\n", $2->addr);
        append_code($$, code);
    }
    | if_statement
    {
        $$ = $1;
    }
    | while_statement
    {
        $$ = $1;
    }
    | for_statement
    {
        $$ = $1;
    }
    | block_statement
    {
        $$ = $1;
    }
    | RETURN expression SEMICOLON
    {
        $$ = $2;
        char code[128];
        sprintf(code, "return %s\n", $2->addr);
        append_code($$, code);
    }
    | RETURN SEMICOLON
    {
        $$ = create_expr_result();
        append_code($$, "return\n");
    }
    | SEMICOLON
    {
        $$ = create_expr_result();
    }
    ;

block_statement:
    LBRACE statement_list RBRACE
    {
        $$ = $2;
    }
    | LBRACE RBRACE
    {
        $$ = create_expr_result();
    }
    ;

if_statement:
    IF LPAREN expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* true_label = new_label();
        char* end_label = new_label();
        char code[1024];
        sprintf(code,
            "%sif %s goto %s\ngoto %s\n%s:\n%s%s:\n",
            $3->code, $3->addr, true_label, end_label,
            true_label, $5->code, end_label);
        append_code($$, code);
    }
    | IF LPAREN expression RPAREN block_statement ELSE block_statement
    {
        $$ = create_expr_result();
        char* true_label = new_label();
        char* false_label = new_label();
        char* end_label = new_label();
        char code[2048];
        sprintf(code,
            "%sif %s goto %s\ngoto %s\n%s:\n%s\ngoto %s\n%s:\n%s%s:\n",
            $3->code, $3->addr, true_label, false_label,
            true_label, $5->code, end_label,
            false_label, $7->code, end_label);
        append_code($$, code);
    }
    ;

while_statement:
    WHILE LPAREN expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* start_label = new_label();
        char* body_label = new_label();
        char* end_label = new_label();
        char code[1024];
        sprintf(code,
            "%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s\ngoto %s\n%s:\n",
            start_label, $3->code, $3->addr, body_label, end_label,
            body_label, $5->code, start_label, end_label);
        append_code($$, code);
    }
    ;

for_statement:
    FOR LPAREN variable_declaration SEMICOLON expression SEMICOLON assignment_expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* start_label = new_label();
        char* body_label = new_label();
        char* update_label = new_label();
        char* end_label = new_label();
        char code[2048];
        sprintf(code,
            "%s%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s%s:\n%s\ngoto %s\n%s:\n",
            $3->code, start_label, $5->code, $5->addr, body_label, end_label,
            body_label, $9->code, update_label, $7->code, start_label, end_label);
        append_code($$, code);
    }
    | FOR LPAREN assignment_expression SEMICOLON expression SEMICOLON assignment_expression RPAREN block_statement
    {
        $$ = create_expr_result();
        char* start_label = new_label();
        char* body_label = new_label();
        char* update_label = new_label();
        char* end_label = new_label();
        char code[2048];
        sprintf(code,
            "%s%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s%s:\n%s\ngoto %s\n%s:\n",
            $3->code, start_label, $5->code, $5->addr, body_label, end_label,
            body_label, $9->code, update_label, $7->code, start_label, end_label);
        append_code($$, code);
    }
    ;

function_declaration:
    FUNCTION IDENTIFIER LPAREN RPAREN block_statement
    {
        $$ = $5;
        char code[128];
        sprintf(code, "// Function: %s\n", $2);
        append_code($$, code);
    }
    ;

variable_declaration:
    VAR type IDENTIFIER
    {
        $$ = create_expr_result();
        char code[128];
        sprintf(code, "// Declaration: %s\n", $3);
        append_code($$, code);
    }
    | VAR type IDENTIFIER ASSIGN expression
    {
        $$ = $5;
        char code[128];
        sprintf(code, "%s = %s\n", $3, $5->addr);
        append_code($$, code);
    }
    ;

type:
    basic_type
    {
        $$ = $1;
    }
    ;

basic_type:
    INT { $$ = create_expr_result(); }
    ;

assignment_expression:
    IDENTIFIER ASSIGN expression
    {
        $$ = $3;
        char code[128];
        sprintf(code, "%s = %s\n", $1, $3->addr);
        append_code($$, code);
    }
    ;

expression:
    relational_expression
    {
        $$ = $1;
    }
    ;

relational_expression:
    additive_expression
    {
        $$ = $1;
    }
    | relational_expression LT additive_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s < %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    | relational_expression GT additive_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s > %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    ;

additive_expression:
    multiplicative_expression
    {
        $$ = $1;
    }
    | additive_expression PLUS multiplicative_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s + %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    | additive_expression MINUS multiplicative_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s - %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    ;

multiplicative_expression:
    unary_expression
    {
        $$ = $1;
    }
    | multiplicative_expression TIMES unary_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s * %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    | multiplicative_expression DIVIDE unary_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s / %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    | multiplicative_expression MOD unary_expression
    {
        $$ = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s %% %s\n", $1->code, temp, $1->addr, $3->addr);
        append_code($$, code);
        $$->addr = temp;
    }
    ;

unary_expression:
    postfix_expression
    {
        $$ = $1;
    }
    ;

postfix_expression:
    primary_expression
    {
        $$ = $1;
    }
    ;

primary_expression:
    IDENTIFIER
    {
        $$ = create_expr_result();
        $$->addr = strdup($1);
    }
    | INT_LITERAL
    {
        $$ = create_expr_result();
        char buf[32];
        sprintf(buf, "%d", $1);
        $$->addr = strdup(buf);
    }
    | STRING_LITERAL
    {
        $$ = create_expr_result();
        $$->addr = strdup($1);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d\n", s, line_num);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file1> [<input_file2> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        yyin = fopen(argv[i], "r");
        if (!yyin) {
            perror("Cannot open input file");
            continue;
        }

        line_num = 1;
        temp_var_counter = 0;
        label_counter = 0;
        yyrestart(yyin);

        printf("\n// Processing file: %s\n", argv[i]);
        yyparse();

        fclose(yyin);
    }

    return 0;
}