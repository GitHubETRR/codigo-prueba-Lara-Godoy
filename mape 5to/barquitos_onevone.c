#include <stdio.h>

#define LEDISTE 'x'
#define AGUA 'O'
#define OCUPADO 'B'
#define LIBRE ' '
#define COLUMNAS 4
#define FILAS 4
#define CASILLEROS (COLUMNAS*FILAS)
#define NUM_BARCOS (5*(CASILLEROS)/9)

void tablero_en_0(int fondo[FILAS][COLUMNAS]);
void graficar_matrix(int mat[FILAS][COLUMNAS]);
void posicionar_barquitos(int fondo[FILAS][COLUMNAS]);
int pedir_datos_fila();
int pedir_datos_columna();

int main(){
    int fondo_1[FILAS][COLUMNAS];
    int tiros_1[FILAS][COLUMNAS];
    int fondo_2[FILAS][COLUMNAS];
    int tiros_2[FILAS][COLUMNAS];
    int encontrado_1=0, encontrado_2=0;
    int tiro_columna_1, tiro_fila_1;
    int tiro_columna_2, tiro_fila_2;

    tablero_en_0(fondo_1);
    tablero_en_0(tiros_1);
    tablero_en_0(fondo_2);
    tablero_en_0(tiros_2);
    graficar_matrix(fondo_1);
    graficar_matrix(fondo_2);
    printf("Jugador 1 pone tus barquitos.\n");
    posicionar_barquitos(fondo_1);
    printf("Asi quedo tu tablero");
    graficar_matrix(fondo_1);
    printf("Jugador 2 pone tus barquitos.\n");
    posicionar_barquitos(fondo_2);
    printf("Asi quedo tu tablero");
    graficar_matrix(fondo_2);
    return 0;
}

void tablero_en_0(int fondo[FILAS][COLUMNAS]){
    for (int i=0; i<FILAS; i++){
        for (int j=0; j<COLUMNAS; j++){
            fondo[i][j] = LIBRE;
        }
    }
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
            }else if (mat[i][j]==OCUPADO){
                printf("|\033[32;1m%c\033[0m|",mat[i][j]);
            }else{
                printf("|%c|", mat[i][j]);  // Otros estados
            }
        }
        printf("\n");
    }
}

int pedir_datos_fila(){
    //printf("\nIntenta derribar un buque!\n");
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

void posicionar_barquitos(int fondo[FILAS][COLUMNAS]){
    int puestos = 0;
    while (puestos < NUM_BARCOS){
        int fila, columna;
        fila = pedir_datos_fila();
        columna = pedir_datos_columna();
        if (fondo[fila][columna] == LIBRE){
            fondo[fila][columna] = OCUPADO;
            puestos++;
        }else{
            printf("Ya pusiste un barco ahi. Intenta de nuevo.\n");
        }
    }
}