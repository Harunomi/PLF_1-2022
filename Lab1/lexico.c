#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entradas: un entero con el total de entradas del argv y las entradas del argv
// Salidas: ninguna
// Descripcion: verifica que las entradas por consola sean correctas
void revisarEntradas(int totalEntradas,char *argv[]);

// Entradas: un arreglo de caracteres y un archivo tipo FILE
// Salidas: ninguna
// Descripcion: verifica que el arreglo de entrada corresponda a un numero entero
void revisarNumeroEntero(char entrada[], FILE *archivoSalida);

// Entradas: un arreglo de caracteres y un archivo tipo FILE
// Salidas: ninguna
// Descripcion: verifica que el arreglo de entrada corresponda a un numero real
void revisarNumeroReal(char entrada[], FILE *archivoSalida);

// Entradas: un arreglo de caracteres y un archivo tipo FILE
// Salidas: ninguna
// Descripcion: verifica que el arreglo de entrada corresponda a corresponda a un simbolo terminal
void revisarPalabrasReservadas(char entrada[], FILE *archivoSalida);

int main(int argc,char *argv[]){
    revisarEntradas(argc-1,argv);
    char stringEntrada[20];
    char stringSalida[20];
    char fila[1000];
    char *pedacito;
    char separacion[2] = " ";
    
    strcpy(stringEntrada,argv[1]);
    strcat(stringEntrada,".txt");
    strcpy(stringSalida,argv[2]);
    strcat(stringSalida,".txt");
    // creamos los archivos 
    FILE *archivoEntrada = fopen(stringEntrada, "r");
    FILE *archivoSalida = fopen(stringSalida,"w");
    fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
    // CICLO HASTA QUE SE LLEGUE A LA PENULTIMA FILA DEL ARCHIVO
    while(!feof(archivoEntrada)){
        // tomo el primer elemento de la fila separado por un espacio 
        pedacito = strtok(fila,separacion);
        while (pedacito !='\0'){ // leo ese elemento hasta el final de la fila
            // hago las revisiones
            revisarNumeroEntero(pedacito,archivoSalida);
            revisarNumeroReal(pedacito,archivoSalida);
            revisarPalabrasReservadas(pedacito,archivoSalida);
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
        revisarPalabrasReservadas(pedacito,archivoSalida);
        pedacito = strtok(NULL, separacion);   
    }
    // cerramos los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);
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
    int contadorMenos = 0;
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
        string[i] == '9'||
        string[i] == '-'||
        string[i] == '0'){
            if (string[i] == '-'){
                contadorMenos++;
            }
        }else{
            // caso en que se encuentre algo distinto a digitos
             return;
        }
        i = i + 1;
    }
    // en caso que haya solo digitos
    if(contadorMenos == 0){
        fprintf(archivoSalida,"NUM_ENTERO\n");
    }else if(contadorMenos == 1 && string[0] == '-' && i > 1){
        fprintf(archivoSalida,"NUM_ENTERO\n");
    }
}
void revisarNumeroReal(char entrada[], FILE *archivoSalida){
    int i = 0;
    int contador = 0; 
    int contadorMenos = 0;
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
        string[i] == '-' ||
        string[i] == '.'){
            // contamos la cantidad de puntos ('.') del string
            if (string[i] == '.'){
                contador++;
            }
            if (string[i] == '-'){
                contadorMenos++;
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
            if(contadorMenos == 0){
                fprintf(archivoSalida,"NUM_ENTERO\n");
            }else if(contadorMenos == 1 && string[0] == '-' && i>1){
                fprintf(archivoSalida,"NUM_ENTERO\n");
            }    
            return;
        }
        if (contadorMenos == 0){
            fprintf(archivoSalida,"NUM_REAL\n");
        }else if (contadorMenos == 1 && string[0] == '-' && i>1){
            fprintf(archivoSalida,"NUM_REAL\n");
        }
        
    }
    
}

void revisarPalabrasReservadas(char entrada[], FILE *archivoSalida){
    char string[1000];
    char modulo[2] = "%";
    strcpy(string,entrada); // se copia entrada en string, puesto que entrada viene con datos basura al usar strtok, como el (null) y con eso lo eliminamos.
    if (strcmp(string,"+") == 0){
        fprintf(archivoSalida,"+\n");
    }else if (strcmp(string,"-") == 0){
        fprintf(archivoSalida,"-\n");
    }else if (strcmp(string,"*") == 0){
        fprintf(archivoSalida,"*\n");
    }else if (strcmp(string,"/") == 0){
        fprintf(archivoSalida,"/\n");
    }else if (strcmp(string,"^") == 0){
        fprintf(archivoSalida,"^\n");
    }else if (strcmp(string, modulo) == 0){
        fprintf(archivoSalida,"%s\n",modulo);
    }else if (strcmp(string,"sqrt") == 0){
        fprintf(archivoSalida, "sqrt\n");
    }else if (strcmp(string,"(") == 0){
        fprintf(archivoSalida, "(\n");
    }else if (strcmp(string,")") == 0){
        fprintf(archivoSalida, ")\n");
    }
}
