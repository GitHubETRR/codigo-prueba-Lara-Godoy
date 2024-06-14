#include <stdio.h>

int main(){
    int num_user_min, num_user_max;
    int suma_pares = 0;

    printf("Ingresa tu numero de inicio: \n");
    scanf("%d", &num_user_min);
    printf("Ingresa tu numero final: \n");
    scanf("%d", &num_user_max);

    for(num_user_min; num_user_min < num_user_max; num_user_min++){
        if (num_user_min % 2 == 0){
            suma_pares += num_user_min;
        }
    }
    printf("Suma: %d", suma_pares);
    return 0;
}