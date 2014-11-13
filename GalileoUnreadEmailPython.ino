/*
  Juliana Karoline de Sousa
  Galileo Email Checker
  Original code from SparkFun
  Adapted to show in an 16x2 LCD display
*/

#include <SD.h>
#include <LiquidCrystal.h>

const int emailUpdateRate = 10000;
long emailLastMillis = 0;
int emailCount = 0;

LiquidCrystal lcd(2, 4, 7, 8, 9, 10);
  
void setup() {
  lcd.begin(16,2);
  SD.begin();
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Checking mail...");
  
  // Only check email if emailUpdateRate ms have passed
  if (millis() > emailLastMillis + emailUpdateRate) {
    emailLastMillis = millis(); // update emailLastMillis
    int tempCount = getEmailCount();     // Get unread email count, and store into temporary variable
    if (tempCount != emailCount) { // If it's a new value, update
      // Do this to prevent blinking the same number
      emailCount = tempCount; // update emailCount variable
      printLcd(emailCount); // print in the LCD display
    }
  }
    
  // Bit of protection in case millis overruns:
  if (millis() < emailLastMillis)
    emailLastMillis = 0;
}

// getEmailCount runs the pyMail.py script, and reads the output.
// It'll return the value printed by the pyMail.py script.
int getEmailCount() {
  int digits = 0;
  int temp[10];
  int emailCnt = 0;

  // Send a system call to run our python script and route the
  // output of the script to a file.
  system("python /media/realroot/pyMailCheck.py > /media/realroot/emails");
  File emailsFile = SD.open("emails"); // open emails for reading

  // read from emails until we hit the end or a newline
  while ((emailsFile.peek() != '\n') && (emailsFile.available()))
    temp[digits++] = emailsFile.read() - 48; // Convert from ASCII to a number

  emailsFile.close(); // close the emails file
  system("rm /media/realroot/emails"); // remove the emails file

  // Turn the inidividual digits into a single integer:
  for (int i=0; i<digits; i++)
    emailCnt += temp[i] * pow(10, digits - 1 - i);
  
  return emailCnt;
}

void printLcd(int qtdMail) { 
  lcd.setCursor(0,0);
  lcd.print("Mail checked!...");
  lcd.setCursor(0,1);
  lcd.print("Unread mail: ");
  lcd.print(qtdMail);
}
