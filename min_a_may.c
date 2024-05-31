#include <stdio.h>

int main (void){
    char letra;
    printf("Ingrese letra minuscula: ");
    scanf("%c", &letra);
    letra = letra - ('a' - 'A');
    printf("Su letra en mayuscula es: %c \n", letra);
    return 0;
}