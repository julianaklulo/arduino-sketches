/* 
  Juliana Karoline de Sousa
  
  Projeto para o stand da Engenharia de Computação no evento Universidade Aberta da UFSCar
  https://www.youtube.com/watch?v=kkvau0lqzRc
  
  Usa um sensor HC-SR05, um led RGB e um display LCD 16x2.
  De acordo com a distancia medida pelo sensor, acende uma cor diferente do led
  e informa a distancia em cm no display LCD to a RGB display and an 16x2 LCD
  
*/
 
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 4, 7, 8, 9, 10);

// definiçao de constantes para pinos 
#define TRIG_PIN 13
#define ECHO_PIN 12

#define RED 6
#define GREEN 5
#define BLUE 3

// definiçao de constantes para facilitar a manutençao das distancias 
#define BLUE_LONG 60
#define BLUE_SHORT 30
#define GREEN_LONG 45
#define GREEN_SHORT 15
#define RED_LONG 30
#define RED_SHORT 0
 
void setup() {
  // inicia o display LCD
  lcd.begin(16,2);
  
  // seta o modo dos pinos do LED
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
 
  // seta o modo dos pinos do HC-SR05
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // apaga o LED (anodo comum, apaga com HIGH) 
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}
 
void loop() {
  // declaracao de variaveis
  long duration, distance;
 
  // le a distancia e converte para cm
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  
  // de acordo com a distancia, mapeia a cor do led usando pwm
  // azul: de 60cm a 30cm
  // verde: de 45cm a 15cm
  // vermelho: de 30cm a 0cm
  
  if (distance > RED_LONG)
    digitalWrite(RED, HIGH);
  else
    analogWrite(RED, map(distance, RED_LONG, RED_SHORT, 255, 0));
  
  if ((distance > GREEN_LONG) || (distance < GREEN_SHORT))
    digitalWrite(GREEN, HIGH);
  else
    analogWrite(GREEN, map(distance, GREEN_LONG, GREEN_SHORT, 255, 0));
  
  if ((distance > BLUE_LONG) || (distance < BLUE_SHORT))
    digitalWrite(BLUE, HIGH);
  else
    analogWrite(BLUE, map(distance, BLUE_LONG, BLUE_SHORT, 255, 0));
  
  // escreve a distancia no display
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("EnC 2014 UFSCar");
  lcd.setCursor(0,1);
  lcd.print("Distancia: ");
  if (distance > 50)
    lcd.print("> 50");
  else
    lcd.print(distance);
  lcd.print(" cm");
  
  // aguarda para poder ler o sensor novamente
  delay(400);
}
