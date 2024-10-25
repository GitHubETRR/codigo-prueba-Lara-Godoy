/*Definir un número secreto en el código.
Permitir al usuario ingresar sus intentos.
Informar al usuario si su intento es demasiado alto, demasiado bajo o correcto.
Repetir el proceso hasta que el usuario adivine correctamente el número secreto.*/

#include <stdio.h>

int main(void){
    int num_secreto = 278540;
    int num_usuario, contador = 1;

    printf("Ingresa tu intento para adivinar un numero secreto: \n");
    scanf("%d", &num_usuario);
    while (num_usuario != num_secreto){
        if (num_usuario < num_secreto){
            printf("Error, intenta de nuevo un numero mayor: \n");
            scanf("%d", &num_usuario);
        }else{
            printf("Error, intenta de nuevo un numero menor: \n");
            scanf("%d", &num_usuario);
        }
    contador = contador + 1;
    }
    printf("Bien ahi, master, correcto. \n");
    printf("Intentaste: %d", contador, "veces.");
    return 0;
}
