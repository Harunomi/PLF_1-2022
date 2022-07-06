%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern int yylex();
void yyerror(char *s);
%}
%union{
    float real;
    int entero;
}
%token <entero> NUM_ENTERO
%token <real> NUM_REAL
%token <entero> ENTERO_NEG
%token <real> REAL_NEG
%type <entero> calculo_entero
%type <real> calculo_real
%token SQRT
%token ERROR
%left '+' '-'
%left '/' '*' '%'
%left '^'
%left SQRT
%left '(' ')'
%start s

%%
s: n  { }
    | ERROR {yyerror("a");}
;
n: calculo_real {printf("\n%f\n",$1); return 1;}
    | calculo_entero {printf("\n%d\n",$1); return 1;} 
;
calculo_real: NUM_REAL {$$ = $1;}
                | REAL_NEG {$$ = $1;}
                | calculo_real '+' calculo_real {$$ = $1 + $3;}
                | calculo_real '-' calculo_real {$$ = $1 - $3;}
                | calculo_real '*' calculo_real {$$ = $1 * $3;}
                | calculo_real '/' calculo_real {
                    if($3 == 0){
                        printf("\nNo se puede dividir por 0.\n");
                        yyerror("");
                    }else{
                        $$ = $1 / $3;
                    }
                }
                | calculo_real '^' calculo_real {$$ = pow($1,$3);}
                | calculo_real '%' calculo_real {
                    printf("\nNo existe el resto en los numeros reales.\n");
                }
                | SQRT calculo_real {$$ = sqrt($2);}
                | '(' calculo_real ')' {$$ = $2;}

;
calculo_entero: NUM_ENTERO {$$ = $1;}
                | ENTERO_NEG {$$ = $1;}
                | calculo_entero '+' calculo_entero {$$ = $1 + $3;}
                | calculo_entero '-' calculo_entero {$$ = $1 - $3;}
                | calculo_entero '*' calculo_entero {$$ = $1 * $3;}
                | calculo_entero '/' calculo_entero {
                    if($3 == 0){
                        printf("\nNo se puede dividir por 0.\n");
                        yyerror("");
                    }else{
                        $$ = $1 / $3;
                    }
                }
                | calculo_entero '^' calculo_entero {$$ = pow($1,$3);}
                | calculo_entero '%' calculo_entero {$$ = $1 % $3;}
                | SQRT calculo_entero {$$ = sqrt($2);}
                | '(' calculo_entero ')' {$$ = $2;}

;


%%

void yyerror(char *s)
{
    if(strcmp(s,"") == 0){
        printf("%s\n",s);
    }else{
        printf("\nExpresi%cn aritm%ctica incorrecta.\n",162,130);
    }
exit(1);
}
void main(int argc, char* argv[])
{
    if(argc > 1) {
        printf("Error: Ingreso de par%cmetrosen la l%cnea de comandos.\n", 160,161);
        printf("Uso: sintac.exe\n");
    }else{
        printf("\nIngrese la expresi%cn aritm%ctica: ",162,130);
        yyparse();
    }
}