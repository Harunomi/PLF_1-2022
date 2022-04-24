#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revisarEntradas(int totalEntradas,char *argv[]);

int main(int argc,char *argv[]){
    revisarEntradas(argc-1,argv);
    char stringEntrada[20];
    char stringSalida[20];
    strcpy(stringEntrada,argv[1]);
    strcat(stringEntrada,".txt");
    strcpy(stringSalida,argv[2]);
    strcat(stringSalida,".txt");
    // creamos los archivos 
    FILE *archivoEntrada = fopen(stringEntrada, "r");
    FILE *archivoSalida = fopen(stringSalida,"w");
    
    

    return 0;
}

void revisarEntradas(int totalEntradas,char *argv[]){
    if(totalEntradas == 0 ){
        printf("Error: Faltan parametros.\n");
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else if(totalEntradas == 1){
        printf("Error: Falta parametro.");
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else if(totalEntradas > 2){
        printf("Error: Demasiados parametros.");
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else{ // revisamos que los archivos de salida sean correctos
        // agregamos la extension .txt a las entradas
        char stringEntrada[20];
        char stringSalida[20];
        strcpy(stringEntrada,argv[1]);
        strcat(stringEntrada,".txt");
        strcpy(stringSalida,argv[2]);
        strcat(stringSalida,".txt");
        // creamos los archivos 
        FILE *archivoEntrada = fopen(stringEntrada, "r");
        FILE *archivoSalida = fopen(stringSalida,"r");
        // revisamos que el archivo de entrada no sea nulo
        if(archivoEntrada == NULL){
            printf("Error: El archivo de entrada no existe.");
            exit(1);
        }else if(archivoSalida != NULL){
            printf("Error: El archivo de salida ya existe.");
            exit(1);
        }

    }

}