#include <stdio.h>

int main(void){
    int dia, mes, anio;

    printf("Ingrese dia: \n");
    scanf("%d", &dia);
    printf("Ingrese mes: \n");
    scanf("%d", &mes);
    printf("Ingrese anio: \n");
    scanf("%d", &anio);

    printf("Cumple: %d", dia);
    printf("/%d", mes);
    printf("/%d", anio);
    return(0);
}