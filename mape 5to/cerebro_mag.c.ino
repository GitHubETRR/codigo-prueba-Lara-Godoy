#include <Arduino.h>
#include <stdbool.h>

#define PULSO_PIN 14
#define DELAY 1000
#define TIEMPO_PULSO 500
#define MAX_CAT 4
#define CANT_PREG 6
#define CANT_RESP CANT_PREG
#define PULSO 12
#define DIP1 A0
#define DIP2 A1
#define BAUDRATE 9600

int PREG[]={2,3,4,5,6,7};
int RESP[]={8,9,10,11,12,13};

const int PREGS[MAX_CAT][CANT_PREG]={
    {1,2,3,4,5,0},
    {0,5,4,3,2,1},
    {2,4,5,0,3,1},
    {1,2,3,0,5,4},
};


bool verificar_comb(int,int);
void enviar_pulso();
int ver_categoria(void);
int ver(int[]);

void setup() {
    for(int i=0;i<CANT_PREG;i++)pinMode(PREG[i], INPUT_PULLUP);  // Preguntas
    for(int i=0;i<CANT_RESP;i++)pinMode(RESP[i], INPUT_PULLUP);  // Respuestas
    
    pinMode(PULSO, OUTPUT); // Pulso

    pinMode(DIP1, INPUT_PULLUP);  // DIP-SWITCH 1
    pinMode(DIP2, INPUT_PULLUP);  // DIP-SWITCH 2
    Serial.begin(BAUDRATE);
}


void loop() {
    int cat=ver_categoria();
    int preg=ver(PREG);
    if(preg!=CANT_PREG){
        if(verificar_comb(preg,cat)==true){
            Serial.println("EXITO!");
        }else{
            Serial.println("ERROR");
        }   
    }
    delay(DELAY);  // Pausa para evitar lecturas rápidas
}

bool verificar_comb(int preg,int cat){
    int resp=ver(RESP);
    int lectura= digitalRead(PREGS[cat][preg]);
    if (digitalRead(RESP[PREGS[cat][preg]])==LOW)return true;  
    return false;  
}

void enviar_pulso(){
    digitalWrite(PULSO_PIN, HIGH); 
    delay(TIEMPO_PULSO); 
    digitalWrite(PULSO_PIN, LOW); 
}

int ver_categoria(){
    int dip1 = digitalRead(DIP1);
    int dip2 = digitalRead(DIP2);
    return ((dip2<<1) | dip1);
}

int ver(int vect[]){
    for (int i = 0; i < CANT_PREG; i++){
        if (digitalRead(vect[i]) == LOW  ){  
            return i;
        }
    }
    return CANT_PREG;  

}
