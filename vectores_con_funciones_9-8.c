#include <stdio.h>
#define TAMANO_VECTOR 6

void Cargar_Vector(int[]);
void Mostrar_Vector(int[]);

int main(){
    int vec[TAMANO_VECTOR];
    system("cls");
    Cargar_Vector(vec);
    Mostrar_Vector(vec);
    return 0;
}

void Cargar_Vector(int a[]){
    int i;
    for(i=0;i<TAMANO_VECTOR;i++){
        printf("\nIngrese dato <%d> de <%d>: ", i+1, TAMANO_VECTOR);
        scanf("%d", &a[i]);
    }
}

void Mostrar_Vector(int a[]){
    int i;
    for(i=0; i<TAMANO_VECTOR; i++){
        printf("\nDato <%d>: %d", i+1, a[i]);
    }
}