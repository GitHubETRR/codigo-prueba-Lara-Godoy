#include <stdio.h>
#define LIMITE 100

typedef struct{
    char nombre[LIMITE];
    int velocidad;
    int fuerza;
    int reflejos;
    float vida;
    char poderes1[LIMITE];
    char poderes2[LIMITE];
    char poderes3[LIMITE];
}caracteristicas_t;

void imprimir(caracteristicas_t);

caracteristicas_t spiderman = {"Spider-Man", 100, 100, 100, 100, "munequeras", "sentido aracnido", "se aferra a la mayoria de las superficies"};
caracteristicas_t duende_verde = {"Duende Verde", 100, 100, 100, 100, "granadas", "planeador", "curacion regenerativa"};
int main(){
    printf("Spider-Man\n");
    printf("Su identidad secreta es Peter Parker, un joven fotografo de Nueva York que, despues de ser mordido por una arana radiactiva, adquiere habilidades \nespeciales: fuerza sobrehumana, agilidad extraordinaria, y la capacidad de trepar paredes y disparar telaranas.\nA diferencia de muchos otros superheroes, Peter Parker enfrenta desafios cotidianos como pagar impuestos, lidiar con el trabajo y mantener relaciones personales.\n\n");
    imprimir(spiderman);
    printf("Duende Verde\n");
    printf("Su identidad secreta es Norman Osborn, un industrial millonario y padre de Harry Osborn, el mejor amigo de Peter Parker. \nNorman es el fundador y CEO de Oscorp, una compania tecnologica y quimica. Despues de experimentar con una formula quimica para aumentar su poder, Norman adquiere fuerza sobrehumana, agilidad, y resistencia, pero tambien sufre un colapso mental que lo lleva a convertirse en el temido Duende Verde.\nEl Duende Verde vuela sobre un planeador de alta tecnologia que esta equipado con una variedad de armas.\n\n");
    imprimir(duende_verde);
    return 0;
}

void imprimir(caracteristicas_t personaje){
    printf("Nombre:%s\n",personaje.nombre);
    printf("Velocidad:%d\n",personaje.velocidad);
    printf("Fuerza:%d\n",personaje.fuerza);
    printf("Reflejos:%d\n",personaje.reflejos);
    printf("Vida:%f\n",personaje.vida);
    printf("Poder/armadura 1:%s\n",personaje.poderes1);
    printf("Poder/armadura 2:%s\n",personaje.poderes2);
    printf("Poder/armadura 3:%s\n\n",personaje.poderes3);
}