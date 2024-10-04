//Agregar niveles
//Numero secreto aleatorio
//Imprimir coincidencias

#include <stdio.h>
#include <string.h>

int main(void){
    char modo[10];
    int num_secreto = 5372863;
    int num_usuario, contador = 1;

    printf("Bienvenido a adivina el numero.");
    printf("Hay tres modos: \nIsi mode! \nMedium mode! \nTRYHARD MODE!");
    printf("¿Cual queres jugar?");
    scanf("%s", &modo);

/*    printf("Ingresa tu intento para adivinar un numero secreto: \n");
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
    printf("Intentaste: %d", contador, "veces.");*/
    return 0;
}
