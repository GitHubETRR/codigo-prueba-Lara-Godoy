/*Escribir una función que reciba como parámetro un vector de enteros y el tamaño 
definido por Uds. y calcule la suma de todos los elementos del vector.*/

#include <stdio.h>
#define tam_vector 7
void Cargar_Vector(int[]);
int Suma_Valores(int[]);
int Promedio(int, int);

int main(){
    int vector[tam_vector];
    int i;
    int suma_total, prom;
    Cargar_Vector(vector);
    Promedio(vector);
    printf("La suma total de los valores del vector es: %d\n", suma_total);
    printf("Promedio: %d", prom);
    return 0;
}

void Cargar_Vector(int a[]){
    int i;
    for(i=0;i<tam_vector;i++){
        printf("\nIngrese dato <%d> de <%d>: ", i+1, tam_vector);
        scanf("%d", &a[i]);
    }
}

int Suma_Valores(int a[]){
    int i, suma_total = 0;
    for(i=0; i<tam_vector; i++){
        suma_total += a[i];
    }
    return suma_total;
}

int Promedio(int a[], int suma_total){
    int prom;
    prom = suma_total / tam_vector;
    return prom;
}