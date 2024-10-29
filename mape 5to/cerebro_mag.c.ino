#include <Arduino.h>
#include <stdbool.h>

#define DELAY 1000
#define TIEMPO_PULSO 3000
#define MAX_CAT 4
#define CANT_PREG 6
#define CANT_RESP CANT_PREG
#define PULSO 12
#define DIP1 A0
#define DIP2 A1
#define PULSO_PIN A2
#define BAUDRATE 9600

int PREG[] = {2, 3, 4, 5, 6, 7};
int RESP[] = {8, 9, 10, 11, 12, 13};

const int PREGS[MAX_CAT][CANT_PREG] = {
    {1, 2, 3, 4, 5, 0},
    {0, 5, 4, 3, 2, 1},
    {2, 4, 5, 0, 3, 1},
    {1, 2, 3, 0, 5, 4},
};

bool verificar_comb(int, int);
void enviar_pulso();
void medir_pulso();
int ver_categoria(void);
int ver(int[]);

void setup() {
    for (int i = 0; i < CANT_PREG; i++) pinMode(PREG[i], INPUT_PULLUP);  // Preguntas
    for (int i = 0; i < CANT_RESP; i++) pinMode(RESP[i], INPUT_PULLUP);  // Respuestas

    pinMode(PULSO, OUTPUT);      // Pin de pulso de salida
    pinMode(PULSO_PIN, INPUT);   // Pin de pulso de entrada para medir

    pinMode(DIP1, INPUT_PULLUP);  // DIP-SWITCH 1
    pinMode(DIP2, INPUT_PULLUP);  // DIP-SWITCH 2
    Serial.begin(BAUDRATE);
}

void loop() {
    int cat = ver_categoria();
    int preg = ver(PREG);
    if (preg != CANT_PREG) {
        if (verificar_comb(preg, cat) == true) {
            Serial.println("EXITO!");
            enviar_pulso();    // Enviar pulso cuando hay éxito
            medir_pulso();     // Medir la duración del pulso
        } else {
            Serial.println("ERROR");
        }
    }
    delay(DELAY);  // Pausa para evitar lecturas rápidas
}

bool verificar_comb(int preg, int cat) {
    int resp = ver(RESP);
    int lectura = digitalRead(PREGS[cat][preg]);
    if (digitalRead(RESP[PREGS[cat][preg]]) == LOW) return true;
    return false;
}

// Función para enviar el pulso
void enviar_pulso() {
    pinMode(PULSO_PIN, OUTPUT);  // Configurar el pin A2 como salida
    digitalWrite(PULSO_PIN, HIGH);
    delay(TIEMPO_PULSO);
    digitalWrite(PULSO_PIN, LOW);
    pinMode(PULSO_PIN, INPUT);   // Volver a configurar el pin A2 como entrada para medir el pulso
}

// Función para medir la duración del pulso en A2
void medir_pulso() {
    unsigned long duracion = pulseIn(PULSO_PIN, HIGH, 1000000);  // Tiempo en microsegundos
    if (duracion > 0) {
        Serial.print("Duración del pulso: ");
        Serial.print(duracion);
        Serial.println(" microsegundos");
    } else {
        Serial.println("No se detectó el pulso.");
    }
}

int ver_categoria() {
    int dip1 = digitalRead(DIP1);
    int dip2 = digitalRead(DIP2);
    return ((dip2 << 1) | dip1);
}

int ver(int vect[]) {
    for (int i = 0; i < CANT_PREG; i++) {
        if (digitalRead(vect[i]) == LOW) {
            return i;
        }
    }
    return CANT_PREG;
}
