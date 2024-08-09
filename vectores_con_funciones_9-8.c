#include <stdio.h>
#define tamano_vector 6

void Cargar_Vector(int[]);
void Mostrar_Vector(int[]);

int main(){
    int vec[tamano_vector];
    system("cls");
    Cargar_Vector(vec);
    Mostrar_Vector(vec);
    return 0;
}

void Cargar_Vector(int a[]){
    int i;
    for(i=0;i<tamano_vector;i++){
        printf("\nIngrese dato <%d> de <%d>: ", i+1, tamano_vector);
        scanf("%d", &a[i]);
    }
}

void Mostrar_Vector(int a[]){
    int i;
    for(i=0; i<tamano_vector; i++){
        printf("\nDato <%d>:%d", i+1, a[i]);
    }
}