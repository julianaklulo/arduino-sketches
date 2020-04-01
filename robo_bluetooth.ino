const int motor1Pin1 = 2;
const int motor1Pin2 = 4;
const int enable1Pin = 9;

const int motor2Pin1 = 5;
const int motor2Pin2 = 6;
const int enable2Pin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
}

void loop() {
    char comando;
  
    if (Serial.available()) {
      comando = Serial.read();
      switch(comando) {
        case 'f':
          frente();
          break;
        case 't':
          tras();
          break;
        case 'd':
          direita();
          break;
        case 'e':
          esquerda();
          break;
        case 'p':
          parar();
          break;
      }
    }
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
