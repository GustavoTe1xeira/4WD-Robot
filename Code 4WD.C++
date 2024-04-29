#include <AFMotor.h>
#include <Ultrasonic.h>

#define trigger A2
#define echo A3

// Infravermelho
#define IR_Esquerda A4
#define IR_Direita A5

unsigned int microsec;
unsigned long refTimer = 0;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Ultrasonic ultrasonic(trigger, echo);


void frente() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void tras() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void parada() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void esquerda() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void procura() {
  frente();
  delay(300);
  esquerda();
  delay(300);
}

void setup() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Serial.begin(9600);
  pinMode(IR_Esquerda, INPUT);
  pinMode(IR_Direita, INPUT);
}

// TO-DO: Criar função para pegar a distância em centímetros

void isOnRing(distancia: int) {
  return distancia > 20 && digitalRead(IR_Esquerda) == 0 && digitalRead(IR_Direita) == 0
}

void loop() {

  microsec = ultrasonic.timing();

  if (true) {
    procura();
  }

  if (isOnRing(distancia)) {
    while (digitalRead(IR_Esquerda) == 0) {
      frente();
    }
    parada();
    delay(1000);
    tras();
    delay(1000);
  }

  if (digitalRead(IR_Esquerda) == 1 && digitalRead(IR_Direita) == 0) {
    tras();
    delay(500);
  }

  if (digitalRead(IR_Esquerda) == 0 && digitalRead(IR_Direita) == 1) {
    frente();
    delay(500);
  }
}
