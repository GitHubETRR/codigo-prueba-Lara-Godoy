#include <stdio.h>
int main(void){
    int area, largo, ancho;
    printf("largo: ");
    scanf("%d", &largo);
    printf("ancho: ");
    scanf("%d", &ancho);
    area=ancho*largo;
    printf("Area: %d", area);
    return 0;
}