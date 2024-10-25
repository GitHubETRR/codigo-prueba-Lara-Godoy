#include <stdio.h>

int suma(int a, int b);
int resta(int a, int b);
int multi(int a, int b);
int div(int a, int b);

int main(){
    int num_1, num_2;
    int resultado, eleccion;

    printf("Bienvenido. Que deseas hacer?: \n");
    printf("1. Suma. \n");
    printf("2. Resta. \n");
    printf("3. Multiplicacion. \n");
    printf("4. Division. \n");
    scanf("%d", &eleccion);

    printf("Ingrese el primer numero: ");
    scanf("%d", &num_1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num_2);

    switch (eleccion){
    case 1:
        resultado = suma(num_1, num_2);
        printf("\nResultado: %d", resultado);
        break;

    case 2:
        resultado = resta(num_1, num_2);
        printf("\nResultado: %d", resultado);
        break;
    
    case 3:
        resultado = multi(num_1, num_2);
        printf("\nResultado: %d", resultado);
        break;
    
    case 4:
        if (num_2 != 0){
            resultado = div(num_1, num_2);
            printf("\nResultado: %d", resultado);
        }else{
            printf("No se puede dividir por 0");
        }
        break;

    default:
            printf("Operación no válida.\n");
            break;
    return 0;
    }
}

int suma(int a, int b){
    return a + b;
}

int resta(int a, int b){
    return a - b;
}

int multi(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}