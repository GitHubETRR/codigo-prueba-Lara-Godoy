/*Fórmulas de conversión:
Valor en kilómetros = valor
Valor en metros = valor * 1000
Valor en milímetros = valor * 1,000,000
Valor en pulgadas = valor * 39,370.1
Valor en yardas = valor * 1,093.61
Valor en pies = valor * 3,280.84
Valor en millas = valor * 0.621371
Valor en millas náuticas = valor * 0.539957
*/

#include <stdio.h>

int main(){
    int eleccion;
    float valor, resultado;

    printf("Hola. Ingresa tu valor: \n");
    scanf("%f", &valor);

    printf("Elegi a que queres pasarlo: \n");
    printf("1. Kilometros.\n");
    printf("2. Metros.\n");
    printf("3. Milimetros.\n");
    printf("4. Pulgadas.\n");
    printf("5. Yardas.\n");
    printf("6. Pies.\n");
    printf("7. Millas.\n");
    printf("8. Millas nauticas.\n");
    scanf("%d", &eleccion);

    switch (eleccion){
    case 1:
        resultado = valor;
        printf("Resultado en kilometros = %.2f", resultado);
        break;
    
    case 2:
        resultado = valor * 1000;
        printf("Resultado en metros = %.2f", resultado);
        break;

    case 3:
        resultado = valor * 1000000;
        printf("Resultado en milimetros = %.2f", resultado);
        break;
    
    case 4:
        resultado = valor * 39370.1;
        printf("Resultado en pulgadas = %.4f", resultado);
        break;

    case 5:
        resultado = valor * 1093.61;
        printf("Resultado en yardas = %.4f", resultado);
        break;

    case 6:
        resultado = valor * 3280.84;
        printf("Resultado en pies = %.4f", resultado);
        break;
        
    case 7:
        resultado = valor * 0.621371;
        printf("Resultado en millas = %.4f", resultado);
        break;

    case 8:
        resultado = valor * 0.539957;
        printf("Resultado en millas nauticas = %.4f", resultado);
        break;

    default:
        printf("No hay tal opcion");
        break;
    }

    return 0;
}