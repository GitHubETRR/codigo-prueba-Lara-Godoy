#include <stdio.h>
#include <stdbool.h>

#define TAM_TXT 15
#define LIBRE 0
#define CANT_ASIENTOS (COLUMNAS*FILAS)
#define COLUMNAS 4
#define FILAS 2
#define OCUPADO 'x'
#define DESOCUPADO ' '

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha_venta_t;

typedef struct{
    char nombre[TAM_TXT];
    char apellido[TAM_TXT];
    fecha_venta_t fecha_venta;
    bool estado;  		// Estado: DISPONIBLE (0) o VENDIDO (1)	
}reservas_t;

int mostrar_disponibles(int asientos[CANT_ASIENTOS]);
void graficar_matrix(int mat[FILAS][COLUMNAS]);
int elegir_asiento(reservas_t asiento, fecha_venta_t vendido, int avion[FILAS][COLUMNAS]);

int main(){
    int asientos[CANT_ASIENTOS] = {LIBRE};
    int avion[FILAS][COLUMNAS];

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            avion[i][j] = DESOCUPADO;
        }
    }

    printf("Buenos dias.\n");
    int disponibles = mostrar_disponibles(asientos);
    printf("Hay %d de %d asientos libres.", disponibles, CANT_ASIENTOS);
    graficar_matrix(avion);

    elegir_asiento(reservas_t asiento, fecha_venta_t vendido, int avion[FILAS][COLUMNAS]);
    disponibles = mostrar_disponibles(avion);
    printf("Ahora hay %d de %d asientos libres.\n", disponibles, CANT_ASIENTOS);
    graficar_matrix(avion);

}

int mostrar_disponibles(int avion[FILAS][COLUMNAS]){
    int disp = 0;
    for (int i = 0; i < CANT_ASIENTOS; i++){
        if (asientos[i] == LIBRE){
            disp++;
        }
    }
    return disp;
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
            if (mat[i][j]==OCUPADO){
                printf("|%c|", mat[i][j]);
            }else{
                printf("|%c|", mat[i][j]);
            }
        }
        printf("\n");
    }
}

int elegir_asiento(reservas_t asiento, fecha_venta_t vendido, int avion[FILAS][COLUMNAS]){
    int asientos_requeridos;
    
    printf("Nombre: %s\n", asiento.nombre);
    printf("Apellido: %d\n", asiento.apellido);
    printf("Fecha de venta: %02d/%02d/%d\n", vendido.dia, vendido.mes, vendido.anio);


    while (asientos_requeridos < CANT_ASIENTOS){
        for (int i = 0; i < (asientos_requeridos - 1); i++){
            int fila, columna;
            fila = pedir_datos_fila();
            columna = pedir_datos_columna();
            if (avion[fila][columna] == DESOCUPADO){
                avion[fila][columna] = OCUPADO;
                asientos_requeridos--;
                printf("Asiento [%d, %d] reservado con éxito.\n", fila + 1, columna + 1);
                graficar_matrix(avion);
            }else{
                printf("Ocupado. Intenta de nuevo.\n");
            }
        }
    }
}

int pedir_datos_fila(){
    int fila;
    do {
        printf("Fila: ");
        scanf("%d", &fila);
        fila--;
    }while (fila < 0 || fila >= FILAS); 
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


