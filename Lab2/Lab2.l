%{
    #include <stdio.h>
%}

%option noyywrap

%%
"^" {fprintf(yyout,"^\n");}
"+" {fprintf(yyout,"+\n");}
"-" {fprintf(yyout,"-\n");}
"/" {fprintf(yyout,"/\n");}
"*" {fprintf(yyout,"*\n");}
"(" {fprintf(yyout,"(\n");}
")" {fprintf(yyout,")\n");}
"%" {fprintf(yyout,"%c\n",37);}
"sqrt" {fprintf(yyout,"SQRT\n");}
"-"[0-9]+"."[0-9]+ {fprintf(yyout,"NUM_REAL\n");}
"-"[0-9]+"." {fprintf(yyout,"NUM_REAL\n");}
[0-9]+"."[0-9]+ {fprintf(yyout,"NUM_REAL\n");}
"."[0-9]+ {fprintf(yyout,"NUM_REAL\n");}
"-"[0-9]+ {fprintf(yyout,"NUM_ENTERO\n");}
[0-9]+ {fprintf(yyout,"NUM_ENTERO\n");}
"-"[0-9]+"^"[0-9]+ {fprintf(yyout,"NUM_ENTERO\n");}
[0-9]+"^"[0-9]+ {fprintf(yyout,"NUM_ENTERO\n");}
[0-9]+"^""-"[0-9]+ {fprintf(yyout,"NUM_REAL\n");}
. {}
"\n" {}
%%

void main(int argc,char *argv[])
{
    if(argc-1 == 0 ){
        printf("Error: Faltan par%cmetros.\n", 160 );
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        return;
    }else if(argc-1 == 1 ){
        printf("Error: Falta par%cmetro.\n", 160 );
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        return;
    }else if(argc-1 > 2 ){
        printf("Error: Demasiados par%cmetros.\n", 160 );
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        return;
    }else{ 
        yyin = fopen(argv[1], "r");
        yyout = fopen(argv[2],"r");
        if(yyin == NULL){
            printf("Error: El archivo de entrada no existe.");
            fclose(yyin);
            fclose(yyout);
            return;
        }else if(yyout != NULL){
            printf("Error: El archivo de salida ya existe.");
            fclose(yyin);
            fclose(yyout);
            return;
        }
        fclose(yyin);
        fclose(yyout);
    }
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2],"w");
     
    yylex();
}