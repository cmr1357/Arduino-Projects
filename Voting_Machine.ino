/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sw1 =8;
int sw2 =9;
int sw3 =10;
int sw4 =13;
int led1=6;
int led2=7;
int buzzer=0;

int count1=0;
int count2=0;
int count3=0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.print("ELECTION 2021");
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(8, 1);
  // print the number of seconds since reset:
 if(digitalRead(sw1)==HIGH)
 {
    count1=count1+1;
    Serial.print("sw1 count=");
    lcd.print("A");
    Serial.println(count1);
    digitalWrite(led1,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(buzzer,LOW);
 }
 else if (digitalRead(sw2)==HIGH)
 {
    count2=count2+1;
    Serial.print("sw2 count=");
    lcd.print("B");
    Serial.println(count2);
    digitalWrite(led1,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(buzzer,LOW);
 }
 else if (digitalRead(sw3)==HIGH)
 {
    count3=count3+1;
    Serial.print("sw3 count=");
    lcd.print("C");
    Serial.println(count3);
    digitalWrite(led1,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(buzzer,LOW);
 }
 else if (digitalRead(sw4)==HIGH)
 {
    
    digitalWrite(led2,HIGH);
    
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    if(count1 >count2 && count1>count3)
    { lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Election Result:...");
      lcd.setCursor(0, 1);
      lcd.print("A is the winner");
    Serial.println("A is the winner");}
    if(count2 >count1 && count2>count3)
    {lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Election Result:...");
      lcd.setCursor(0, 1);
      lcd.print("B is the winner");
    Serial.println("B is the winner");}
    if(count3 >count2 && count3>count1)
    {lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Election Result:...");
      lcd.setCursor(0, 1);
      lcd.print("C is the winner");
    Serial.println("c is the winner");}
    if(count3 == count2 == count1)
    
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Election Result:...");
      lcd.setCursor(0, 1);
      lcd.print("Is a Tie");
      }
      delay(1000);
      digitalWrite(led2,LOW);
 }
}
