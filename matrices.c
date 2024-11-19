#include <stdio.h>

int main(){
    int matriz[4][4]={{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    //mimatriz[fila][columna]={0x01,0x02,0x03,0x04}

    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}