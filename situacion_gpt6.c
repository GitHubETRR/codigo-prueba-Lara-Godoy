/*Desarrolla un programa que calcule y muestre los primeros n números de la serie de Fibonacci. 
La serie de Fibonacci comienza con 0 y 1, y cada número siguiente es la suma de los dos números anteriores. 
El programa debe solicitar al usuario cuántos números de la serie desea ver.*/

#include <stdio.h>

int main(){
    int cantidad_series, num_prox, i = 1;
    int n1 = 0, n2 = 1;

    printf("Bienvenido, ingresa la cantidad de series de Fibonacci.\n");
    scanf("%d", &cantidad_series);

    for(i; i<cantidad_series; i++){
        printf("\nNumero: %d", n1);
        num_prox = n1 + n2;
        n1 = n2;
        n2 = num_prox;
    }
    return 0;
}