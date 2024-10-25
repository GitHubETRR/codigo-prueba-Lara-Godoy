#include <stdio.h>

int main(void){
    int cantidad, precio;
    float precio_pedido;
    printf("Bienvenidos al Himalaya! \n");
    printf("Cuantos kg de banana desea llevar?: \n");
    scanf("%d", &cantidad);
    printf("A cuanto esta el kg de bananas?: \n");
    scanf("%d", &precio);
    precio_pedido = cantidad * precio;
    
    if (precio_pedido <= 100){
        printf("Debes abonar: %d", precio_pedido, "pesos");
    }else if ((100 < precio_pedido)&&(precio_pedido < 500)){
        precio_pedido = (10 * precio_pedido)/100;
        printf("Debes abonar: %f", precio_pedido), "pesos";
    }else{
        precio_pedido = (20 * precio_pedido)/100;
        printf("Debes abonar: %f", precio_pedido, "pesos");
    }
    return 0;
}
