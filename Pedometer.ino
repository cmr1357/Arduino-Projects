

//Pedometer
#include <LiquidCrystal.h>
#define sq(x) ((x)*(x))

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int xpin = A1;
const int ypin = A2;
const int zpin = A3;

float threshold = 5;
float xval[100] = {0};
float yval[100] = {0};
float zval[100] = {0};
float xavg, yavg, zavg;
int steps=0, flag = 0;

void setup() 
{
  
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  calibrate();
}


void loop()
{
 
  int acc = 0;
  float totvect[100] = {0};
  float totave[100] = {0};
  float xaccl;
  float yaccl;
  float zaccl;
  
  for (int a = 0; a < 100; a++)
  {
    xaccl = float(analogRead(xpin) - 408);
  
    yaccl = float(analogRead(ypin) - 352);
  
    zaccl = float(analogRead(zpin) - 425);
 
    float cal= sqrt(sq(xaccl ) + sq(yaccl)  + sq(zaccl));
    totvect[a] =cal;
    Serial.print("totavect[a]=");
    Serial.println(totvect[a]);
    Serial.print("totavect[a-1]=");
    Serial.println(totvect[a-1]);
    totave[a] = (totvect[a] - totvect[a - 1])  ;
    Serial.println("totave[a]");
    Serial.println(totave[a]);
  
    if (totave[a] > threshold )
    {
      steps = steps + 1;
      delay(1000);
      Serial.println(totvect[a]);
      
    }
    lcd.setCursor(0,1);
    lcd.print("Steps: ");
    lcd.print(steps);
  
  }
 
}



void calibrate()
{
  float sum = 0;
  float sum1 = 0;
  float sum2 = 0;
  for (int i = 0; i < 100; i++) {
    xval[i] = float(analogRead(xpin) - 408);
    sum = xval[i] + sum;
  }
  delay(100);
  xavg = sum / 100.0;
  Serial.println(xavg);
  for (int j = 0; j < 100; j++)
  {
    yval[j] = float(analogRead(ypin) - 352);
    sum1 = yval[j] + sum1;
  }
  yavg = sum1 / 100.0;
  Serial.println(yavg);
  delay(100);
  for (int q = 0; q < 100; q++)
  {
    zval[q] = float(analogRead(zpin) - 425);
    sum2 = zval[q] + sum2;
  }
  zavg = sum2 / 100.0;
  delay(100);
  Serial.println(zavg);
}
