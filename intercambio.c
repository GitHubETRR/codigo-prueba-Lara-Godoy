#include <stdio.h>

void intercambiar(int *a, int *b);
int sumar(int *a, int *b);

int main() {
    int x = 10, y = 20;
    int resultado;

    printf("Antes de intercambiar: x = %d, y = %d\n", x, y);
    intercambiar(&x, &y);
    printf("Despues de intercambiar: x = %d, y = %d\n", x, y);

    resultado = sumar(&x, &y);
    printf("Valor de la suma de x + y: %d", resultado);
    
    return 0;
}

void intercambiar(int *a, int *b) {
    int temp = *a;  // Guardar el valor de *a (es decir, el valor de x)
    *a = *b;        // Asignar a *a el valor de *b (el valor de y)
    *b = temp;      // Asignar a *b el valor guardado en temp (que era el valor de x)
}

int sumar(int *a, int *b){
    int suma = 0;
    suma = *a + *b;
    return suma;
}
