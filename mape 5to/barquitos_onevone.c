#include <stdio.h>
#include <string.h> 

#define LEDISTE 'x'
#define AGUA 'O'
#define OCUPADO 'B'
#define LIBRE ' '
#define COLUMNAS 3
#define FILAS 3
#define CASILLEROS (COLUMNAS*FILAS)
#define NUM_BARCOS 3
#define MAX_LETRAS 16

void tablero_en_0(int fondo[FILAS][COLUMNAS]);
void graficar_matrix(int mat[FILAS][COLUMNAS]);
void posicionar_barquitos(int fondo[FILAS][COLUMNAS]);
void pedir_nombre_jugador(char nombre[MAX_LETRAS]);
int disparar_1(int fondo[FILAS][COLUMNAS], int tiros[FILAS][COLUMNAS]);
int disparar_2(int fondo[FILAS][COLUMNAS], int tiros[FILAS][COLUMNAS]);
int verificar_ganador();
int pedir_datos_fila();
int pedir_datos_columna();

int main(){
    int fondo_1[FILAS][COLUMNAS];
    int tiros_1[FILAS][COLUMNAS];
    int fondo_2[FILAS][COLUMNAS];
    int tiros_2[FILAS][COLUMNAS];
    int aciertos_1=0, aciertos_2=0;
    int tiro_columna_1, tiro_fila_1;
    int tiro_columna_2, tiro_fila_2;
    char nombre_1[MAX_LETRAS];
    char nombre_2[MAX_LETRAS];

    tablero_en_0(fondo_1);
    tablero_en_0(tiros_1);
    tablero_en_0(fondo_2);
    tablero_en_0(tiros_2);
    graficar_matrix(fondo_1);
    graficar_matrix(fondo_2);
    pedir_nombre_jugador(nombre_1);
    printf("%s pone tus barquitos.", nombre_1);
    posicionar_barquitos(fondo_1);
    printf("Asi quedo tu tablero %s:", nombre_1);
    graficar_matrix(fondo_1);
    printf("Espera unos segundos.");
    sleep(5);
    system("cls");
    pedir_nombre_jugador(nombre_2);
    printf("%s pone tus barquitos.", nombre_2);
    posicionar_barquitos(fondo_2);
    printf("Asi quedo tu tablero %s:", nombre_2);
    graficar_matrix(fondo_2);
    printf("Espera unos segundos.");
    sleep(5);
    system("cls");
    while (1){
        printf("Dispara %s!\n", nombre_1);
        aciertos_1 += disparar(fondo_2, tiros_2);
        graficar_matrix(tiros_2);
        if (verificar_ganador(aciertos_1, NUM_BARCOS)) {
            printf("\033[32;1mGano %s!\033[0m\n", nombre_1);
            break;
        }
        printf("Dispara %s!\n", nombre_2);
        aciertos_2 += disparar(fondo_1, tiros_1);
        graficar_matrix(tiros_1);
        if (verificar_ganador(aciertos_2, NUM_BARCOS)) {
            printf("\033[32;1mGano %s!\033[0m\n", nombre_2);
            break;
        }
    }
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
                printf("|\033[36;1m%c\033[0m|",mat[i][j]);
            }else{
                printf("|%c|", mat[i][j]);  // Otros estados
            }
        }
        printf("\n");
    }
}

int pedir_datos_fila(){
    int fila;
    do {
        printf("\nFila: ");
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
            graficar_matrix(fondo);
        }else{
            printf("Ya pusiste un barco ahi. Intenta de nuevo.\n");
        }
    }
}

int disparar(int fondo[FILAS][COLUMNAS], int tiros[FILAS][COLUMNAS]){
    int aciertos=0;
    int fila = pedir_datos_fila();
    int columna = pedir_datos_columna();
    if (tiros[fila][columna] == LEDISTE){
        printf("\033[30;2mYa disparaste aca.\033[0m\n");
    }else{
        if (fondo[fila][columna] == OCUPADO){
            printf("\033[31;1mImpacto!\033[0m");
            tiros[fila][columna] = LEDISTE;
            fondo[fila][columna] = LEDISTE;
            aciertos++;
        }else{
            printf("\033[94;1mAgua!\033[0m");
            tiros[fila][columna] = AGUA;
            fondo[fila][columna] = AGUA;
        }
    }
    return aciertos;
}

int verificar_ganador(int aciertos, int num_barcos){
    return aciertos >= num_barcos;
}

void pedir_nombre_jugador(char nombre[MAX_LETRAS]){
    printf("Ingresa tu nombre: ");
    fflush(stdin);
    fgets(nombre, MAX_LETRAS, stdin);
    size_t len = strlen(nombre);
    if (len > 0 && nombre[len - 1] == '\n'){
        nombre[len - 1] = '\0';
    }
}