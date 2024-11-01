#include <Arduino.h>
#include <stdbool.h>

#define BAUDRATE 9600
#define DELAY 1000
#define TIEMPO_PULSO 100
#define MAX_CAT 4
#define CANT_PREG 6
#define LIBRE 0
#define BLOQUEADO 1
#define TIEMPO_TILT 500
#define CANT_TILT 6
#define CANT_RESP CANT_PREG

#define DIP1 A0
#define DIP2 A1
#define PULSO_PIN A2
#define RESET_CONT A3
#define TILT_PIN A4

int PREG[] = {2, 3, 4, 5, 6, 7};
int RESP[] = {8, 9, 10, 11, 12, 13};
int bloqueo[CANT_PREG] = {LIBRE};

const int PREGS[MAX_CAT][CANT_PREG] = {
    {1, 2, 3, 4, 5, 0},
    {0, 5, 4, 3, 2, 1},
    {2, 4, 5, 0, 3, 1},
    {1, 2, 3, 0, 5, 4},
//   0  1  2  3  4  5
};

bool verificar_comb(int, int);
void enviar_pulso();
void medir_pulso();
int ver_categoria(void);
int ver(int[]);
void reset(void);
void titilar(void);
void imprimir(void);

void setup(){
    Serial.begin(BAUDRATE);
    for (int i = 0; i < CANT_PREG; i++)
        pinMode(PREG[i], INPUT_PULLUP); // Preguntas
    for (int i = 0; i < CANT_RESP; i++)
        pinMode(RESP[i], INPUT_PULLUP); // Respuestas
    pinMode(PULSO_PIN, OUTPUT); // Pin de pulso de salida
    pinMode(RESET_CONT, OUTPUT);
    reset();
    pinMode(TILT_PIN, OUTPUT);
    digitalWrite(TILT_PIN, HIGH);
    pinMode(DIP1, INPUT_PULLUP); // DIP-SWITCH 1
    pinMode(DIP2, INPUT_PULLUP); // DIP-SWITCH 2
}

void loop(){
    static int cat = 0;
    int cat_new = ver_categoria();
    if (cat_new != cat){
        cat = cat_new;
        reset();
    }

    int preg = ver(PREG);
    if (preg != CANT_PREG){
        if (verificar_comb(preg, cat) == true){
            if (bloqueo[preg] == LIBRE){
                bloqueo[preg] = BLOQUEADO;
                enviar_pulso(); // Enviar pulso cuando hay éxito
                int i;
                for (i = 0; i < CANT_PREG; i++)if (bloqueo[i] == LIBRE)break;
                if (i == CANT_PREG)titilar();
            }
            while (ver(PREG) != CANT_PREG);
        }
        delay(DELAY); // Pausa para evitar lecturas rápidas
    }
}

bool verificar_comb(int preg, int cat){
    int resp = ver(RESP);
    int lectura = digitalRead(PREGS[cat][preg]);
    if (digitalRead(RESP[PREGS[cat][preg]]) == LOW)
        return true;
    return false;
}

void enviar_pulso(){
    digitalWrite(PULSO_PIN, HIGH);
    delay(TIEMPO_PULSO);
    digitalWrite(PULSO_PIN, LOW);
    delay(TIEMPO_PULSO);
}

int ver_categoria(){
    int dip1 = digitalRead(DIP1);
    int dip2 = digitalRead(DIP2);
    return ((dip2 << 1) | dip1);
}

int ver(int vect[]){
    for (int i = 0; i < CANT_PREG; i++){
        if (digitalRead(vect[i]) == LOW){
            return i;
        }
    }
    return CANT_PREG;
}

void reset(void){
    digitalWrite(RESET_CONT, LOW);
    delay(TIEMPO_PULSO);
    digitalWrite(RESET_CONT, HIGH);
    delay(TIEMPO_PULSO);
    for (int i = 0; i < CANT_PREG; i++)bloqueo[i] = LIBRE;

}

void titilar(void){
    for (int i = 0; i < CANT_TILT; i++){
        digitalWrite(TILT_PIN, LOW);
        delay(TIEMPO_TILT);
        digitalWrite(TILT_PIN, HIGH);
        delay(TIEMPO_TILT);
    }
    reset();

}