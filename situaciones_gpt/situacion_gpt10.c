/*Leer 7 temperaturas diarias ingresadas por el usuario.
Calcular el promedio de las temperaturas.
Encontrar la temperatura más alta y la más baja.
Imprimir el promedio, la temperatura más alta y la más baja.*/

#include <stdio.h>

int main(){
    int temperatura;
    float promedio;
    int i = 0, suma;

    printf("Bienvenido.");
    for (i, i <= 7, i++){
        printf("\n Ingrese la temperatura: %d");
        scanf("%f", &temperatura);
        suma += temperatura;
    }
    promedio = suma / 7;
    return 0;
}