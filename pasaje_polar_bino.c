#include <stdio.h>
#include <math.h>

const int pi = 3.1415926535;

int main(void){
    int mod, ang;
    double rad, ejeY, ejeX;
    printf("ingrese el modulo: \n");
    scanf("%d", &mod);
    printf("ingrese el angulo en grados: \n");
    scanf("%d", &ang);

    rad = ang * (pi/180);
    ejeY = sin(rad)*mod;
    ejeX = cos(rad)*mod;

    printf("Parte imaginaria: %d", ejeY);
    printf("Parte real: %d", ejeX);
    return(0);
}