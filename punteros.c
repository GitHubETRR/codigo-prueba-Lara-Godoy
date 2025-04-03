//los punteros pasan direcciones, no valores
//dentro del puntero hay una direccion
//si se aumenta un puntero aumenta la direccion
//los punteros se aumentan segun el tipo de variable al que apuntan
//se pueden pasar valores por referencia o por valor

#include <stdio.h>

int main(){
    float var = 12.25;
    char *p;
    p = &var;
    printf("0x%x\n", *(p++));
    printf("0x%x\n", *(p++));
    printf("0x%x\n", *(p++));
    printf("0x%x\n", *(p++));
    printf("\n");
    printf("0x%x\n", *p++);
    printf("0x%x\n", *p++);
    printf("0x%x\n", *p++);
    printf("0x%x\n", *p++);
}