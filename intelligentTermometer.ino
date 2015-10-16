#include <math.h>;
#include <rgb_lcd.h>
#include <Wire.h>

float temperature, resistance;
int a;
int B = 3975;                  //B value of the thermistor

int redColor, greenColor, blueColor;

int buzzer = 4;

// instanciate the lcd object 
rgb_lcd lcd;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(A0, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  // reading the temperature
  a = analogRead(A0);
  resistance = (float)(1023 - a) * 10000 / a; //get the resistance of the sensor;
  temperature = 1 / (log(resistance / 10000) / B + 1 / 298.15) - 273.15; //convert to temperature via datasheet&nbsp;;
  
  // generating the colors to set the display backlight proportionally to the temperature
  redColor = map(temperature, 30, 45, 0 , 255);
  greenColor = map(temperature, 30, 45, 255, 0);
  blueColor = map(temperature, 30, 45, 255, 0);
  
  // setting the colors
  lcd.setRGB(redColor, greenColor, blueColor);
  
  // check if temperature is over 38 degrees, if so activate the buzzer for 1s
  if (temperature > 38) {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
  }
 
 // print out the temperature in the display
  lcd.setCursor(0,0);
  lcd.print("Temperature is");
  lcd.setCursor(0,1);
  lcd.print(temperature);
  
  // wait a second before analog reading again
  delay(1000);
  
}
