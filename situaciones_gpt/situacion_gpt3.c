#include <stdio.h>

int main(void){
    int cantidad;
    float precio_pedido;
    printf("Bienvenidos al Himalaya! \n");
    printf("Cuantos kg de bananas (55$) desea llevar?: \n");
    scanf("%d", &cantidad);
    precio_pedido = cantidad * 55;
    
    if (precio_pedido <= 100){
        printf("Debes abonar: %d", precio_pedido, "pesos");
    }else if ((100 < precio_pedido)&&(precio_pedido < 500)){
        precio_pedido = (10 * precio_pedido)/100;
        printf("Debes abonar: %f", precio_pedido, "pesos");
    }else{
        precio_pedido = (20 * precio_pedido)/100;
        printf("Debes abonar: %f", precio_pedido, "pesos");
    }
    return 0;
}

/*Si el total de la compra es menor o igual a $100, no se aplica ningún descuento.
Si el total de la compra está entre $100 y $500, se aplica un descuento del 10%.
Si el total de la compra es mayor a $500, se aplica un descuento del 20%.*/