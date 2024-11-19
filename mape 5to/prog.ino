#include <Arduino.h>
#include <stdbool.h>
#define MAX_CAT 4
#define CANT_PREG 6
const int PREG[]={0,1,2,3,4,5};
const int RESP[]={6,7,8,9,10,11};

const int PREGS[CANT_PREG][MAX_CAT]={
    {1,2,3,4,5,0},
    {0,5,4,3,2,1},
    {2,4,5,0,3,1},
    {1,2,3,0,5,4},

};

#define PULSO 12
#define DIP1 A0
#define DIP2 A1

void setup() {
    for(int i=0;i<6;i++)pinMode(PREG[i], INPUT);  // Preguntas
    for(int i=0;i<6;i++)pinMode(RESP[i], INPUT);  // Respuestas
    
    pinMode(PULSO, OUTPUT); // Pulso

    pinMode(DIP1, INPUT);  // DIP-SWITCH 1
    pinMode(DIP2, INPUT);  // DIP-SWITCH 2
    
}

bool verificar_comb(int preguntas[]);
void enviar_pulso();
int ver_categoria(void);
void loop() {
    int cat=ver_categoria();

    for (int i = 0; i < 6; i++){
        preguntas[i] = digitalRead(i);  
    }

    if (nueva_categoria_elegida != categoria_elegida){
        categoria_elegida = nueva_categoria_elegida;
        switch (categoria_elegida){
            case 0:  // DIP 00
                if (verificar_comb(preguntas[])){
                    enviar_pulso(); 
                }
                break;

            case 1:  // DIP 01
                if (verificar_comb(preguntas[])){
                    enviar_pulso(); 
                }
                break;

            case 2:  // DIP 10
                if (verificar_comb(preguntas[])){
                    enviar_pulso(); 
                }
                break;

            case 3:  // DIP 11
                if (verificar_comb(preguntas[])){
                    enviar_pulso(); 
                }
                break;

            default:
                break;
        }
    }
    delay(100);  // Pausa para evitar lecturas rápidas
}

bool verificar_comb(int preguntas[]){
    for (int i = 0; i < 6; i++){
        if (preguntas[i] != HIGH){  
            return false;
        }
    }
    return true;  
}

void enviar_pulso(){
    digitalWrite(12, HIGH); 
    delay(5000); 
    digitalWrite(12, LOW); 
}

int ver_categoria(){

    int dip1 = digitalRead(DIP1);
    int dip2 = digitalRead(DIP2);
    return ((dip2<<1) | dip1);
}