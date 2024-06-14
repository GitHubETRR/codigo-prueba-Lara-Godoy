/*Desarrolla un programa que simule una calculadora básica. 
El programa debe permitir al usuario seleccionar una operación (suma, resta, multiplicación, división) e 
ingresar dos números. 
Dependiendo de la operación seleccionada, el programa debe realizar la operación y mostrar el resultado.*/

#include <stdio.h>
#include <math.h>

int main (){
    int eleccion;
    float suma, resta_1, resta_2, multi, exp_1, exp_2;
    float numero_a, numero_b;
    float divi_1, divi_2;
    printf("Bienvenido. Que deseas hacer?: \n");
    printf("1. Suma. \n");
    printf("2. Resta. \n");
    printf("3. Multiplicacion. \n");
    printf("4. Division. \n");
    printf("5. Potencia. \n");
    scanf("%d", &eleccion);

    printf("Ingresa el primer numero: \n");
    scanf("%f", &numero_a);
    printf("Ingresa el segundo numero: \n");
    scanf("%f", &numero_b);

    switch (eleccion)
    {
    case 1:
        suma = numero_a + numero_b;
        printf("Resultado de la suma: %.2f", suma);
        break;
    
    case 2:
        resta_1 = numero_a - numero_b;
        resta_2 = numero_b - numero_a;
        printf("Resultado del primer numero menos el segundo: %.2f", resta_1);
        printf("\nResultado del segundo numero menos el primero %.2f", resta_2);
        break;
    
    case 3:
        multi = numero_a * numero_b;
        printf("Resultado de la multiplicacion: %.2f", multi);
        break;
    
    case 4:
        if (numero_a != 0 && numero_b != 0){
            divi_1 = numero_a / numero_b;
            divi_2 = numero_b / numero_a;
            printf("Resultado del primero sobre el segundo: %.2f", divi_1);
            printf("\nResultado del segundo sobre el primero: %.2f", divi_2);
        }else{
            printf("No se puede dividir por 0.");
        }
        break;
    
    case 5:
        exp_1 = pow(numero_a, numero_b);
        exp_2 = pow(numero_b,  numero_a);
        printf("Resultado del primer numero al segundo: %.2f", exp_1);
        printf("\nResultado del segundo numero al primero: %.2f", exp_2);
        break;
    
    default:
        printf("Operacion invalida.");
        break;
    }
    return 0;
}