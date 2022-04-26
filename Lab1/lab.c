#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revisarEntradas(int totalEntradas,char *argv[]);

void revisarNumeroEntero(char entrada[], FILE *archivoSalida);

void revisarNumeroReal(char entrada[], FILE *archivoSalida);

void revisarPalabrasReservadas(char entrada[], FILE *archivoSalida);

int main(int argc,char *argv[]){
    //revisarEntradas(argc-1,argv);
    char stringEntrada[20];
    char stringSalida[20];
    char fila[1000];
    char *pedacito;
    char separacion[2] = " ";
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
    FILE *archivoSalida = fopen("archivo_salida.txt", "w");
    fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
    // CICLO HASTA QUE SE LLEGUE A LA PENULTIMA FILA DEL ARCHIVO
    while(!feof(archivoEntrada)){
        // tomo el primer elemento de la fila separado por un espacio 
        pedacito = strtok(fila,separacion);
        while (pedacito !='\0'){ // leo ese elemento hasta el final de la fila
            // hago las revisiones
            revisarNumeroEntero(pedacito,archivoSalida);
            revisarNumeroReal(pedacito,archivoSalida);
            printf("%s\n",pedacito);
            // paso el asiguente elemento
            pedacito = strtok(NULL, separacion);
            
        }
        // paso a la siguiente fila
        fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
    }

    // repito los pasos anteriores para la ultima fila
    fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila

    pedacito = strtok(fila,separacion);
    while (pedacito !='\0'){
        revisarNumeroEntero(pedacito,archivoSalida);
        revisarNumeroReal(pedacito,archivoSalida);
        printf("%s\n",pedacito);
        pedacito = strtok(NULL, separacion);   
    }/*
    char separacion2[2] = "(";
    pedacito = strtok(fila,separacion2);
    printf("%s",fila);
    fclose(archivoEntrada);
    fclose(archivoSalida);
*/
    return 0;
}

void revisarEntradas(int totalEntradas,char *argv[]){
    if(totalEntradas == 0 ){
        printf("Error: Faltan par%cmetros.\n", 160 );
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else if(totalEntradas == 1 ){
        printf("Error: Falta par%cmetro.\n", 160 );
        printf("Uso: lexico.exe archivo_entrada archivo_salida");
        exit(1);
    }else if(totalEntradas > 2 ){
        printf("Error: Demasiados par%cmetros.\n", 160 );
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

void revisarNumeroEntero(char entrada[], FILE *archivoSalida){
    int i = 0;
    char string[1000];
    strcpy(string,entrada); // se copia entrada en string, puesto que entrada viene con datos basura al usar strtok, como el (null) y con eso lo eliminamos.
    while (string[i] != '\0'){
        if(string[i] == '1' ||
        string[i] == '2'||
        string[i] == '3'||
        string[i] == '4'||
        string[i] == '5'||
        string[i] == '6'||
        string[i] == '7'||
        string[i] == '8'||
        string[i] == '9'||
        string[i] == '0'){
        }else{
            // caso en que se encuentre algo distinto a digitos
            return;
        }
        i = i + 1;
        
    }
    // en caso que haya solo digitos
    fprintf(archivoSalida,"NUM_ENTERO\n");
}

void revisarNumeroReal(char entrada[], FILE *archivoSalida){
    int i = 0;
    int contador = 0; 
    char string[100];
    char separacion[2] = ".";
    char *pedacito;
    strcpy(string,entrada);
    while (string[i] != '\0'){
        if(string[i] == '1' ||
        string[i] == '2'||
        string[i] == '3'||
        string[i] == '4'||
        string[i] == '5'||
        string[i] == '6'||
        string[i] == '7'||
        string[i] == '8'||
        string[i] == '9'||
        string[i] == '0' ||
        string[i] == '.'){
            // contamos la cantidad de puntos ('.') del string
            if (string[i] == '.'){
                contador++;
            }
        }else{
            // caso en que haya cualquier cosa que no sean numeros o puntos
            return;
        }
        i = i + 1;
        
    }
    // si la cantidad de puntos es 1
    if (contador == 1 ){
        pedacito = strtok(string,separacion);
        pedacito = strtok(NULL, separacion);
        if(pedacito == '\0'){
            return;
        }
        if(atoi(pedacito) == 0){
            fprintf(archivoSalida,"NUM_ENTERO\n");    
            return;
        }
        fprintf(archivoSalida,"NUM_REAL\n");
    }
    
}

void revisarPalabrasReservadas(char entrada[], FILE *archivoSalida){
    char string[1000];
    strcpy(string,entrada); // se copia entrada en string, puesto que entrada viene con datos basura al usar strtok, como el (null) y con eso lo eliminamos.

}
