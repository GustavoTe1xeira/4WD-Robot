#include <AFMotor.h>
#include <Ultrasonic.h>

#define trigger A2
#define echo   A3
#define sensor1 A4
#define sensor2 A5

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Ultrasonic ultrasonic(trigger, echo);

void setup() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop() {
  long microsec = ultrasonic.timing();
  float distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if (distancia > 20 && digitalRead(sensor1) == 0 && digitalRead(sensor2) == 0) {
    procura();
  }
  
  if (distancia < 20 && distancia > 0 && digitalRead(sensor1) == 0 && digitalRead(sensor2) == 0) {
    while (digitalRead(sensor1) == 0) {
      frente();
    }
    parada();
    delay(1000);
    tras();
    delay(1000);
  }
  
  if (digitalRead(sensor1) == 1 && digitalRead(sensor2) == 0) {
    tras();
    delay(500);
  }
  
  if (digitalRead(sensor1) == 0 && digitalRead(sensor2) == 1) {
    frente();
    delay(500);
  }
}

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
