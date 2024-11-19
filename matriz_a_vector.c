#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3
void mostrar_matriz(int [FILAS][COLUMNAS]);
void pasar_matriz_vector(int [FILAS][COLUMNAS],int [FILAS*COLUMNAS]);
void mostrar_vector(int [FILAS*COLUMNAS]);

int main (void){
    int matriz[FILAS][COLUMNAS]={{1,2,3},{4,5,6},{7,8,9}};
    int vector[FILAS*COLUMNAS]={7,7,7,7,7,7,7,7,7};
    mostrar_vector(vector);
    mostrar_matriz(matriz);
    pasar_matriz_vector(matriz,vector);
    mostrar_vector(vector);
    return 0;
}

void mostrar_matriz(int matriz[FILAS][COLUMNAS]){
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            printf("- %d -",matriz[i][j]);
        }
        printf("\n");
    }
}

void pasar_matriz_vector(int matriz[FILAS][COLUMNAS],int vector[FILAS*COLUMNAS]){
    for(int i=0,p=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            vector[p++]=matriz[i][j];
        }
    }
}

void mostrar_vector(int vector[FILAS*COLUMNAS]){
    for(int i=0;i<FILAS*COLUMNAS;i++){
        printf("- %d -",vector[i]);
    }
    printf("\n");
}