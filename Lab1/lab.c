#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revisarEntradas(int totalEntradas,char *argv[]);

int main(int argc,char *argv[]){
    //revisarEntradas(argc-1,argv);
    char stringEntrada[20];
    char stringSalida[20];
    char fila[1000];
    char *pedacito;
    char separacion[2] = " ";
    int salida = 0;
    /*
    strcpy(stringEntrada,argv[1]);
    strcat(stringEntrada,".txt");
    strcpy(stringSalida,argv[2]);
    strcat(stringSalida,".txt");
    */
    // creamos los archivos 
    //FILE *archivoEntrada = fopen(stringEntrada, "r");
    //FILE *archivoSalida = fopen(stringSalida,"w");
    FILE *archivoEntrada = fopen("archivo_entrada.txt", "r");
    fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
    while(!feof(archivoEntrada)){
        pedacito = strtok(fila,separacion);
        printf("%s\n",pedacito);
        while (pedacito !='\0'){
            pedacito = strtok(NULL, separacion);
            printf("%s\n",pedacito);        
        }
        fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
    }
    fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
    pedacito = strtok(fila,separacion);
    printf("%s\n",pedacito);
    while (pedacito !='\0'){
        pedacito = strtok(NULL, separacion);
        printf("%s\n",pedacito);        
    }
   
    

    return 0;
}

void revisarEntradas(int totalEntradas,char *argv[]){
    if(totalEntradas == 0 ){
        printf("Error: Faltan par%cmetros.\n",160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else if(totalEntradas == 1){
        printf("Error: Falta par%cmetro.\n",160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else if(totalEntradas > 2){
        printf("Error: Demasiados par%cmetros.\n",160);
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
            fclose(archivoEntrada);
            fclose(archivoSalida);
            exit(1);
        }else if(archivoSalida != NULL){
            printf("Error: El archivo de salida ya existe.");
            fclose(archivoEntrada);
            fclose(archivoSalida);
            exit(1);
        }
        // caso de no haber errores, cerramos los archivos
        fclose(archivoEntrada);
        fclose(archivoSalida);

    }

}