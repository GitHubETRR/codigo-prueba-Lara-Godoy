#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LEDISTE 'x'
#define AGUA 'O'
#define OCUPADO 'x'
#define LIBRE ' '
#define COLUMNAS 5
#define FILAS 5
#define CASILLEROS (COLUMNAS*FILAS)
#define NUM_BARCOS (5*(CASILLEROS)/9)

int pedir_datos_fila();
int pedir_datos_columna();
int aciertos(int tiros[FILAS][COLUMNAS],int fondo[FILAS][COLUMNAS], int fila, int columna, int encontrados);
void tablero_en_0(int fondo[FILAS][COLUMNAS]);
void poner_barcos(int fondo[FILAS][COLUMNAS]);
void graficar_matrix(int mat[FILAS][COLUMNAS]);

int main(){
    int fondo[FILAS][COLUMNAS];
    int tiros[FILAS][COLUMNAS];
    int encontrados=0;
    int tiro_colum;
    int tiro_fila;

    time_t start_time, end_time;
    start_time = time(NULL);
    srand(time(NULL));

    tablero_en_0(fondo);
    tablero_en_0(tiros);
    graficar_matrix(fondo);
    poner_barcos(fondo);
    
    while (encontrados<NUM_BARCOS){
        tiro_fila = pedir_datos_fila();
        tiro_colum = pedir_datos_columna();
        encontrados = aciertos(tiros,fondo, tiro_fila, tiro_colum, encontrados);
        printf("Llevas %d de %d buques derribados.\n", encontrados, NUM_BARCOS);
    }
    end_time = time(NULL);
    double total_time = difftime(end_time, start_time);
    printf("Felicitaciones, ganaste!\n");
    printf("Tiempo total: %.2f segundos\n", total_time);
    return 0;
}

int pedir_datos_fila(){
    printf("\nIntenta derribar un buque!\n");
    int fila;
    do {
        printf("Fila: ");
        scanf("%d", &fila);
        fila--;
    }while (fila < 0 || fila >= FILAS);  // Validacion de la fila
    return fila;
}

int pedir_datos_columna(){
    int columna;
    do{
        printf("Columna: ");
        scanf("%d", &columna);
        columna--;
    } while(columna < 0 || columna >= COLUMNAS);
    return columna;
}

int aciertos(int tiros[FILAS][COLUMNAS],int fondo[FILAS][COLUMNAS], int fila, int columna, int encontrados){
    if (fondo[fila][columna]==OCUPADO){
            printf("Le pegaste!\n");
            fondo[fila][columna] = LIBRE;  // Marcar como libre despues de un acierto
            tiros[fila][columna] = LEDISTE;  
            encontrados++;
        }else if(tiros[fila][columna] == LIBRE){
            printf("Agua. Intenta de nuevo.\n");
            tiros[fila][columna] = AGUA;  // Marcar como libre despues de un acierto
        }else{
            printf("Ya tiraste aca. Intenta en otro lugar.\n");
        }
        graficar_matrix(tiros);
    return encontrados;
}

void graficar_matrix(int mat[FILAS][COLUMNAS]){
    printf("\n ");
    for (int j = 0; j < COLUMNAS; j++) {
        printf("%3d", j + 1);
    }
    printf("\n");
    for(int i=0;i<FILAS;i++){
        printf("%2d", i + 1);
        for(int j=0;j<COLUMNAS;j++){
            if (mat[i][j]==LEDISTE){
                printf("|\033[31;1m%c\033[0m|",mat[i][j]);
            }else if (mat[i][j]==AGUA){
                printf("|\033[94;1m%c\033[0m|",mat[i][j]);
            }else{
                printf("|%c|", mat[i][j]);
            }
        }
        printf("\n");
    }
}

void tablero_en_0(int fondo[FILAS][COLUMNAS]){
    for (int i=0; i<FILAS; i++){
        for (int j=0; j<COLUMNAS; j++){
            fondo[i][j] = LIBRE;
        }
    }
}

void poner_barcos(int fondo[FILAS][COLUMNAS]){
    int puestos = 0;
    while (puestos < NUM_BARCOS){
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;
        if (fondo[fila][columna] == LIBRE){
            fondo[fila][columna] = OCUPADO;
            puestos++;
        }
    }
}