#include <stdio.h>

void bienvenida(void);
int pedirDato(void);
int sumar(int,int);
void mostrarResultados(int);

int main(){
    int num1,num2,result;
    bienvenida();
    /* printf("Ingrese un valor positivo:\n");
    num1=pedirDato();
    printf("Ingrese el segundo valor positivo:\n");
    num2=pedirDato();*/
    //result=sumar(num1,num2);
   // result=sumar(num2,num1);
    result=sumar(2,6);

    mostrarResultados(result);
    return 0;
}

void bienvenida(void){
    printf("Hola bienvenido al programa que......\n");
}

int pedirDato(void){
    int dato;

    do{
        scanf("%d",&dato);
        if(dato<0){
            printf("Por favor vuelva ingresar un valor que sea positivo\n");;
        }
    }while(dato<0);
    return dato;    
}
int sumar(int op1,int op2){
    int res;
    res=op1+op2;
    return res;
}
void mostrarResultados(int valor){
    printf("el valor del resultado es: %d\n",valor);
}
