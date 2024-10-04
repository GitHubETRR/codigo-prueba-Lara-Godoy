/*El programa debe pedir al usuario que ingrese una calificación.
Después de ingresar cada calificación, el programa debe calcular y mostrar el promedio de 
las calificaciones ingresadas.*/

#include <stdio.h>

int main(void){
    int notas_dadas, num;
    float cali, promedio, suma_total = 0.0;
    //suma_total = 0.0 para asegurarnos de que la variable comienza desde cero
    printf("Ingresa las notas que te dieron: \n");
    scanf("%d", &notas_dadas);
    for(num = 0; num < notas_dadas; num++){
        printf("Ingresa la nota %d: ", num + 1);
        //num + 1 ---> para que aparezca cual es la nota.
        scanf("%f", &cali);
        suma_total += cali;
    }
    promedio = suma_total / notas_dadas;
    printf("Promedio: %.2f\n", promedio);
    return 0;
}