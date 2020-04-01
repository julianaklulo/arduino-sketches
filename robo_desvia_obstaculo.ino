#include <Servo.h>

const int motor1Pin1 = 2;
const int motor1Pin2 = 4;
const int enable1Pin = 9;

const int motor2Pin1 = 5;
const int motor2Pin2 = 6;
const int enable2Pin = 10;

const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;

const int pinoServo = 3;
Servo s;

const int posMeio = 90;
const int posDireita = 0;
const int posEsquerda = 180;

int distMeio;
int distDireita;
int distEsquerda;

const int ledEsquerda = 8;
const int ledDireita = 7;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledEsquerda, OUTPUT);
  pinMode(ledDireita, OUTPUT);

  Serial.begin(9600);

  s.attach(pinoServo);
  s.write(posMeio);
}

void loop() {
  frente();

  //le distancia no meio
  Serial.print("Meio: ");
  distMeio = calcDist();
  delay(1500);

  if (distMeio < 60) {
    parar();
    tras();
    delay(500);
    parar();

    //servo direita
    s.write(posDireita);
    delay(250);
    //le distancia direita
    Serial.print("Direita: ");
    distDireita = calcDist();
    delay(1500);

    //servo esquerda
    s.write(posEsquerda);
    delay(250);
    //le distancia esquerda
    Serial.print("Esquerda: ");
    distEsquerda = calcDist();
    delay(1500);

    //servo meio
    s.write(posMeio);
    delay(250);

    //se esquerda > direita
    if (distEsquerda > distDireita) {
      digitalWrite(ledEsquerda, HIGH);
      digitalWrite(ledDireita, LOW);
      Serial.println("Esquerda <-");
      esquerda();
      delay(300);
      frente();
    }
    else if (distDireita > distEsquerda) {
      digitalWrite(ledEsquerda, LOW);
      digitalWrite(ledDireita, HIGH);
      Serial.println("Direita ->");
      direita();
      delay(300);
      frente();
    }
    digitalWrite(ledEsquerda, LOW);
    digitalWrite(ledDireita, LOW);
  }
}

int calcDist() {
  int d = 0;

  for (int i = 0; i < 10; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    d += distance;
  }
  d /= 10;

  Serial.println(d);
  return d;
}

void frente() {
  digitalWrite(motor1Pin1, LOW); //Motor_1
  digitalWrite(motor1Pin2, HIGH); //Motor_1
  digitalWrite(motor2Pin1, LOW); //Motor_2
  digitalWrite(motor2Pin2, HIGH); //Motor_2
  delay(10);
}

void tras() {
  digitalWrite(motor1Pin1, HIGH); //Motor_1
  digitalWrite(motor1Pin2, LOW); //Motor_1
  digitalWrite(motor2Pin1, HIGH); //Motor_2
  digitalWrite(motor2Pin2, LOW); //Motor_2
  delay(10);
}
void direita() {
  digitalWrite(motor1Pin1, LOW); //Motor_1
  digitalWrite(motor1Pin2, HIGH); //Motor_1
  digitalWrite(motor2Pin1, HIGH); //Motor_2
  digitalWrite(motor2Pin2, LOW); //Motor_2
  delay(10);
}

void esquerda() {
  digitalWrite(motor1Pin1, HIGH); //Motor_1
  digitalWrite(motor1Pin2, LOW); //Motor_1
  digitalWrite(motor2Pin1, LOW); //Motor_2
  digitalWrite(motor2Pin2, HIGH); //Motor_2
  delay(10);
}

void parar() {
  digitalWrite(motor1Pin1, LOW); //Motor_1
  digitalWrite(motor1Pin2, LOW); //Motor_1
  digitalWrite(motor2Pin1, LOW); //Motor_2
  digitalWrite(motor2Pin2, LOW); //Motor_2
  delay(10);
}
