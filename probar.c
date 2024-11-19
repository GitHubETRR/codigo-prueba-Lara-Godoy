#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 50
typedef enum{
    INGRESAR=1,
    MOSTRAR,
    ELIMINAR,
    EDITAR,
    SALIR
}opciones_t;
typedef struct alumno{
    char nombre[MAX_CHAR];
    char apellido[MAX_CHAR];
    int edad;
    char apodo[MAX_CHAR];
    float promedio;
    struct alumno * next;
}alumno_t;
alumno_t *_5TEL=NULL;
void mostrar(void);
void imprimir_alumno(alumno_t * alumno);
void ingresar(void);
void menu (void);
void liberar_memoria(void);

int main (void){
    menu ();
    liberar_memoria();
    return 0;
}

void imprimir_alumno(alumno_t * alumno){
    printf("\n--------------------\n");
    printf("Nombre: %s\n",alumno->nombre);
    printf("Apellido: %s\n",alumno->apellido);
    printf("Apodo: %s\n",alumno->apodo);
    printf("Edad: %d\n",alumno->edad);
    printf("Promedio: %f\n",alumno->promedio);
    printf("\n--------------------\n");

}

void menu (void){
    opciones_t op;
    do{
        printf("Menu\n");
        printf("1_Ingresar un alumno\n");
        printf("2_Mostrar toda la lista\n");
        printf("3_Eliminar un alumno\n");
        printf("4_Editar un alumno\n");
        printf("5_Salir\n");
        scanf("%d",&op);
        switch (op){
            case INGRESAR:
                ingresar();
                break;
            case MOSTRAR:
                mostrar();
                break;
            case ELIMINAR:

                break;
            case EDITAR:
                break;

        }   
    }while(op!=SALIR);
}

void ingresar(void){
    alumno_t * alum_ptr= (alumno_t *)malloc(sizeof(alumno_t));
    if(alum_ptr==NULL){
        printf("Out of Memory");
        exit(1);
    }

    printf("Nombre:");
    scanf("%s",alum_ptr->nombre);
    printf("Apellido:");
    scanf("%s",alum_ptr->apellido);
    printf("Apodo:");
    scanf("%s",alum_ptr->apodo);
    printf("Edad:");
    scanf("%d",&alum_ptr->edad);
    printf("Promedio:");
    scanf("%f",&alum_ptr->promedio);
    alum_ptr->next=NULL;
    printf("\n");
    if(_5TEL==NULL){
        _5TEL=alum_ptr;
    }
    else{
        alum_ptr->next=_5TEL;
        _5TEL=alum_ptr;
    }

}

void mostrar(void){
    alumno_t * list_alum=_5TEL;
    while(list_alum!=NULL){
        imprimir_alumno(list_alum);
        list_alum=list_alum->next;
    }
}

void liberar_memoria(void){
    alumno_t * list_alum=_5TEL;

    while(_5TEL!=NULL){
        _5TEL=_5TEL->next;
        free(list_alum);
    }
}