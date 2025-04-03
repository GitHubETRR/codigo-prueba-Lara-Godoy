#include <stdio.h>
#include <time.h>
#define cant_vector 6

int main(void){
    int vector[cant_vector];
    int i;
    srand(time(NULL));
    for(i=0; i <= cant_vector; i++){
        vector[i]=rand()%(100-20+1)+20;
        printf("\nValores del vector: \n");
        printf("vector[%d]=%2d\n", i, vector[i]);

    }
    return 0;
}