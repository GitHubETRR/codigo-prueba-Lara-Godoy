#include <stdio.h>

#define LIMITE 50

struct menu_resto{
    char nombre_v0[LIMITE];
    int precio_v0;
    char nombre_v1[LIMITE];
    int precio_v1;
    /*char nombre_v2[LIMITE];
    int precio_v2;
    char nombre_v3[LIMITE];
    int precio_v3;*/
}carnes, ensaladas, pescados, postres;

struct menu_resto parrilla = {"Lomo", 23000, "Vacio", 22800};
//"Choripanes", 19800, "Hamburguesas", 25670
struct menu_resto ensaladas = {"Cesar", 10800, "Nicoise", 8900};
//, "Jardinera", 12300, "Rusa", 7800
struct menu_resto pescados = {"Lenguado", 21800, "Bacalao", 19780};
//, "Dorado", 20400, "Róbalo", 23450
struct menu_resto postres = {"Lemonpie", 11000, "Ensalada de frutas", 6700};
//, "Helado", 7800, "Brownie", 10000

void imprimir(struct menu_resto plato);

int main(){
    int eleccion, seccion;
    printf("El menu del restaurante: \n")
    printf("\nPlatos de la parrilla: \n");
    imprimir(parrilla);
    printf("\nEnsaladas: \n");
    imprimir(ensaladas);
    printf("\nPescados: \n");
    imprimir(pescados);
    printf("\nPostres: \n");
    imprimir(postres);

    printf("Bienvenido. Que deseas hacer?: \n");
    printf("1. Añadir un plato. \n");
    printf("2. Eliminar un plato. \n");
    printf("3. Pedir comida. \n");
    printf("4. Salir. \n");
    scanf("%d", &eleccion);

    switch (eleccion){
    case 1:
        printf("A que seccion queres sumarle otro plato?");
        printf("1. Parrilla. \n");
        printf("2. Ensaladas. \n");
        printf("3. Pescados. \n");
        printf("4. Postres. \n");
        scanf("%d", &seccion);
        switch (seccion){
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
    return 0;
}

void imprimir(struct menu_resto plato){
    printf("\n\n    Nombre: %s", plato.nombre_v0);
    printf("\n    Precio: %d", plato.precio_v0);
    printf("\n\n    Nombre: %s", plato.nombre_v1);
    printf("\n    Precio: %d \n", plato.precio_v1);
    /*printf("\n\nNombre: %s", plato.nombre_v2);
    printf("\nPrecio: %d", plato.precio_v2);
    printf("\n\nNombre: %s", plato.nombre_v3);
    printf("\nPrecio: %d", plato.precio_v3);*/
}