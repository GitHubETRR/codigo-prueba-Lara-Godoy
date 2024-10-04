
#include <stdio.h>

#define MAX_NOTAS 3
#define MAX_ESTUDIANTES 5

struct estudiante{
    char nombre[50];
    int edad;
    float notas[MAX_NOTAS];
    float prom;
}estudiantes;

void pedir_datos(struct estudiante *est);
float calcular_promedios(float notas[]);
void imprimir_datos_resumidos(struct estudiante estudiantes[], int cantidad_estudiante);


int main(){
    struct estudiante estudiantes[MAX_ESTUDIANTES];

    for (int i = 0; i < MAX_ESTUDIANTES; i++){
        pedir_datos(&estudiantes[i]);
        estudiantes[i].prom = calcular_promedios(estudiantes[i].notas);
    }
    imprimir_datos_resumidos(estudiantes, MAX_ESTUDIANTES);
    return 0;
}

void pedir_datos(struct estudiante *est){
    printf("Ingresa el nombre del estudiante: ");
    scanf("%s", est->nombre);

    printf("Ingresa la edad del estudiante: ");
    scanf("%d", &est->edad);

    for (int i = 0; i < MAX_NOTAS; i++) {
        printf("Ingresa la nota %d: ", i + 1);
        scanf("%f", &est->notas[i]);
    }   
}

float calcular_promedios(float notas[]){
    float suma = 0;
    for (int i = 0; i < MAX_NOTAS; i++){
        suma += estudiantes.notas[i];
    }
    return suma / MAX_NOTAS;
}

void imprimir_datos_resumidos(struct estudiante estudiantes[], int cantidad_estudiantes){
    printf("\n=== Datos resumidos de los estudiantes ===\n");
    
    for (int i = 0; i < cantidad_estudiantes; i++){
        printf("\nNombre: %s\n", estudiantes[i].nombre);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Promedio de notas: %.2f\n", estudiantes[i].prom);
    }
}