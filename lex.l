%{
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "parse.tab.h"
%}

%option noyywrap

%%
[ \t] {}
[0-9]*(\.[0-9]+)? {yylval = atof(yytext); return NUM;}
[\n]              {return NL;}
"+"               {return ADD;}
"-"               {return SUB;}
"*"               {return MUL;}
"/"               {return DIV;}
"("               {return LPR;}
")"               {return RPR;}
.                 {}
%%
