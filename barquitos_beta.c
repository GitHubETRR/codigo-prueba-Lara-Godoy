#include <stdio.h>
#include <time.h>

#define OCUPADO 1
#define LIBRE 0

int pedir_datos_fila();
int pedir_datos_columna();
int aciertos(int fondo[][5], int fila, int columna, int encontrados);

int main(){
    int fondo[10][5]={
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
        {LIBRE,LIBRE,LIBRE,LIBRE,LIBRE}
    };
    int encontrados=0;
    int tiro_colum;
    int tiro_fila;

    time_t start_time, end_time;
    start_time = time(NULL);

    while (encontrados<10)
    {
        tiro_fila = pedir_datos_fila();
        tiro_colum = pedir_datos_columna();
        encontrados = aciertos(fondo, tiro_fila, tiro_colum, encontrados);;
        printf("Llevas %d de 10 buques derribados.\n", encontrados);
    }
    end_time = time(NULL);
    double total_time = difftime(end_time, start_time);
    printf("Felicitaciones, ganaste!\n");
    printf("Tiempo total: %.2f segundos\n", total_time);
    return 0;
}

int pedir_datos_fila(){
    printf("Intenta derribar un buque!\n");
    int fila;
    printf("Fila: ");
    scanf("%d", &fila);
    fila--;
    return fila;
}

int pedir_datos_columna(){
    int columna;
    printf("Columna: ");
    scanf("%d", &columna);
    columna--;
    return columna;
}

int aciertos(int fondo[][5], int fila, int columna, int encontrados){
    if (fondo[fila][columna]==OCUPADO){
            printf("Le pegaste!\n");
            fondo[fila][columna] = LIBRE;  // Marcar como libre después de un acierto
            encontrados++;
        }else{
            printf("Agua. Intenta de nuevo.\n");
        }
    return encontrados;
}