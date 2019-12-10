%{
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);
extern FILE* yyin;

%}

%union {
  double num;
}

%token<num> NUM
%token<num> LPR
%token<num> RPR
%token<num> ADD
%token<num> SUB
%token<num> MUL
%token<num> DIV
%token<num> NL

%type<num> input
%type<num> line
%type<num> expr

%left SUB
%left ADD
%left MUL
%left DIV
%left LPR RPR

%%

input:
      | input line
      ;
line:   NL     { printf("?\n"); }
      | expr NL { printf("=%.2f\n", $1); }
      ;
expr:
        SUB expr { $$ = -$2; }
      | NUM { $$ = $1; }
      | expr DIV expr {if ($3 == 0) {yyerror("DIVIDE BY ZERO"); exit(1); } else $$ = $1 / $3; }
      | expr MUL expr { $$ = $1 * $3};
      | LPR expr RPR  { $$ = $2; }
      | expr ADD expr { $$ = $1 + $3};
      | expr SUB expr { $$ = $1 - $3};
      ;
%%
int main(int argc, char **argv) {
  yyin = stdin;
  yyparse();
}

void yyerror(const char *s) {
  printf("ERR: %s\n", s);
}
