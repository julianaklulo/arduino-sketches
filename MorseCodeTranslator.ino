/*
  Código de exemplo para o desenvolvimento do 1º Projeto da Apostila de
  Introdução à Internet das Coisas (IoT) usando Arduino e Intel Galileo
  
  Mais informações e material completo em: 
  http://iot.dc.ufscar.br/
    
  Departmanto de Computação
  UFSCar - São Carlos

  01/05/2015: Primeira versão - Antonio Carlos (falcaopetri@gmail.com)
  03/05/2015: Removido a codificação de números e caracteres especiais - Antonio Carlos
  17/09/2015: Modificado para funcionar com display de LCD e módulo bluetooth HC-05 - Juliana Karoline
*/

#include <LiquidCrystal.h>

#define MORSE_OUT 7

#define DOT   120
#define DASH   3*DOT

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); // Comunicação Serial
  lcd.begin(16,2);
  pinMode(MORSE_OUT, OUTPUT);
}

void loop() {
  
  if (Serial.available()) {
    char leitura = Serial.read();    // Pega um caracter da serial por vez
    imprimirMorse(leitura);
    lcd.clear();
  }
  delay(500);
}

int posC = 0;
int posM = 0;

void imprimirMorse (char c) {
  c = toupper(c);
  String morse = getMorseCode(c);

  Serial.print(c);
 // lcd.setCursor(posC, 0);
  lcd.setCursor(0, 0);
  posC++;
  lcd.print(c);
  if (posC > 15) {
    posC = 0;
    lcd.setCursor(posC, 0);
    lcd.print("                ");
  }
   
  for (int i = 0; i < morse.length(); ++i) {
    lcd.setCursor(posM, 1);
    posM++;
    lcd.print(morse[i]);
    Serial.print(morse[i]);
    if (morse[i] == '.')
      dot();
    else if (morse[i] == '-')
      dash();
    else if (morse[i] == ' ')
      silencio();
    if (posM > 15) {
      posM = 0; 
      lcd.setCursor(posM, 1);
      lcd.print("                ");
    }
    Serial.println();
  }
  posM = 0;
}

String getMorseCode (char c) {
  switch (c) {
  case 'A': 
    return ".-";
  case 'B': 
    return "-...";
  case 'C': 
    return "-.-.";
  case 'D': 
    return "-..";
  case 'E': 
    return ".";
  case 'F': 
    return "..-.";
  case 'G': 
    return "--.";
  case 'H': 
    return "....";
  case 'I': 
    return "..";
  case 'J': 
    return ".---";
  case 'K': 
    return "-.-";
  case 'L': 
    return ".-..";
  case 'M': 
    return "--";
  case 'N': 
    return "-.";
  case 'O': 
    return "---";
  case 'P': 
    return ".--.";
  case 'Q': 
    return "--.-";
  case 'R': 
    return ".-.";
  case 'S': 
    return "...";
  case 'T': 
    return "-";
  case 'U': 
    return "..-";
  case 'V': 
    return "...-";
  case 'W': 
    return ".--";
  case 'X': 
    return "-..-";
  case 'Y': 
    return "-.--";
  case 'Z': 
    return "--..";
  case ' ': 
    return "     "; // Espaço, 7 unidades de silêncio
  default: 
    return "     ";       
  }
}

void silencio() {
  delay(DOT);
}

void dot() {
  digitalWrite(MORSE_OUT, HIGH);
  delay(DOT);
  digitalWrite(MORSE_OUT, LOW);
  silencio();
}

void dash() {
  digitalWrite(MORSE_OUT, HIGH);
  delay(DASH);
  digitalWrite(MORSE_OUT, LOW);
  silencio();
}

