%{
    #include "y.tab.h"
%}

%option noyywrap
real [0-9]+"."[0-9]+
entero [0-9]+
entero_negativo "-"[0-9]+
real_negativo "-"[0-9]+"."[0-9]+
%%
"^" {return *yytext;}
"+" {return *yytext;}
"-" {return *yytext;}
"/" {return *yytext;}
"*" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
"%" {return *yytext;}
"sqrt" {return SQRT;}
{real_negativo} {yylval.real=atof(yytext); return REAL_NEG;}
{entero_negativo} {yylval.entero=atoi(yytext); return ENTERO_NEG;}
{real} {yylval.real=atof(yytext); return NUM_REAL;}
{entero} {yylval.entero=atoi(yytext); return NUM_ENTERO;}
\n {return yytext[0];}
. { return -1;}

%%
