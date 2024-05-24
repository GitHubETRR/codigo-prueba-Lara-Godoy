#include <stdio.h>

const int pi = 3.14;

int main(void){
    int mod, ang, rad;
    printf("ingrese el modulo: \n");
    scanf("%d", &mod);
    printf("ingrese el angulo en grados: \n");
    scanf("%d", &ang);

    rad = ang * (pi/180);
    double sin = sin(rad);
    double cos = cos(rad);
    ejeY = sin(rad)*mod;
    ejeX = cos(rad)*mod;

    printf("Parte imaginaria: %d", ejeY);
    printf("Parte real: %d", ejeX);
}