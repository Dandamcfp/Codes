// WORK IN PROGRESS
#include <HCSR04.h>
#define led 13
#define buzzer 12
#define led 13
#define TRIGGER 3
#define ECHO 4
#define motorA1 5
#define motorA2 6
#define motorB1 10
#define motorB2 9


// variaveis
char modo = 'a';
char acao = 'x';
bool state = 0;
char buf;
int distancia = 0;
char acao2 = 'j';


// Funções de Movimento
void frente() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  delay(200);
  acao = 'P';
}


void atrasA() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  delay(200);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
void atrasM() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  delay(200);
}


void direita() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(200);
}
void esquerda() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  delay(200);
}


void parado() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(200);
}


// Buzina
void buzinar() {
  // Primeiro "bipe"
  tone(buzzer, 1000);  // Toca um tom de 1000 Hz
  delay(250);          // Espera por 250 milissegundos
  noTone(buzzer);      // Desliga o buzzer
  delay(250);          // Espera por 250 milissegundos


  // Segundo "bipe"
  tone(buzzer, 1000);  // Toca um tom de 1000 Hz
  delay(250);          // Espera por 250 milissegundos
  noTone(buzzer);      // Desliga o buzzer
  delay(500);          // Espera por 500 milissegundos (pausa maior)
}


//////////////////////////
//========================
//////////////////////////


UltraSonicDistanceSensor distanceSensor(TRIGGER, ECHO);
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}
void leitura() {
  buf = Serial.read();
  if (buf == 'a' || buf == 'm') {
    modo = buf;
  } else {
    acao = buf;
  }
  delay(300);
}
void loop() {
  if (Serial.available() > 0) {
    //Definir modo e receber ação
    leitura();


    //Modo Manual
    if (modo == 'm') {
      if (acao == 'F') {
        frente();
        leitura();
      } else if (acao == 'L') {
        esquerda();
        leitura();
      } else if (acao == 'R') {
        direita();
        leitura();
      } else if (acao == 'B') {
        atrasM();
        leitura();
      } else if (acao == 'l') {
        digitalWrite(led, HIGH);
        leitura();
      } else if (acao == 'd') {
        leitura();
        digitalWrite(led, LOW);
      } else if (acao == 'H') {
        buzinar();
        leitura();
      } else {
        parado();
        leitura();
      }
      delay(10);
    } else if (modo == 'a') {
      if (acao2 == 'j') {
        distancia = distanceSensor.measureDistanceCm();
        Serial.println(distancia);
        delay(100);
        if (distancia > 50) {
          buzinar();
          frente();
          distancia = distanceSensor.measureDistanceCm();
          delay(200);
          digitalWrite(led, LOW);
        } else if (distancia <= 50) {
          buzinar();
          atrasA();
          digitalWrite(led, HIGH);
          delay(2000);
          direita();
          frente();
          distancia = distanceSensor.measureDistanceCm();
          delay(200);
        }
      }
    }
  }
}


/* if (buf == 'L'){
      digitalWrite(led_pin,HIGH);
      tone(buzzer,3500);
    }
    else if (buf == 'D'){
      digitalWrite(led_pin,LOW);  
      noTone(buzzer);
*/


