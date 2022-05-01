
/////////////////////////// PROJECT- PASSWORD PROTECTED DOOR LOCK SYSTEM /////////////////////////////////////

#include <Password.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


LiquidCrystal_I2C lcd(0x27,20,4);//InitialiZing I2C LCD
  
Password password = Password("1626"); //password to unlock, can be changed       

byte maxPasswordLength = 4; 
byte currentPasswordLength = 0;
const byte ROWS = 4;    // Four rows 
const byte COLS = 4;    // columns   

Servo myservo;  // create servo object to control a servo//twelve servo objects can be created on most boards


int pos = 0;
int lockpos =0;
// Define the Keymap       
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
}; 


// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins. byte      
 byte rowPins[ROWS] = {2,3,4,5}; //connect to row pinouts
 
// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.
byte colPins[COLS] = {6,7,8,9}; //connect to column pinouts


// Create the Keypad       
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);    


void setup()  
{    
    Serial.begin(9600);   
    myservo.attach(11);
    lcd.init();// initialize the lcd 
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Enter password");       
}    
void loop()    
{    
   char key = keypad.getKey();    
  
    if (key != NO_KEY)
    {
      delay(60); 
      switch (key)
      {
      case 'A': break; 
      case 'B': break; 
      case 'C': break; 
      case 'D': break; 
      case '#':checkPassword();break;
      case '*':myservo.write(180);break;
      default :lcd.print("*"); processNumberKey(key);
    
      }
    }
}    
 
void processNumberKey(char key) 
{
   Serial.print(key);
   currentPasswordLength++;
   password.append(key);
   
   if (currentPasswordLength == maxPasswordLength) 
   {
      checkPassword();
   } 
   
}

void checkPassword() 
{
   if (password.evaluate())
   {
      lcd.home();
      Serial.println(" OK.");
      lcd.print(" OK.");
      delay(2000);
      lcd.clear();
      opendoor();
   } 
   
   else 
   {
      lcd.home();
      Serial.println(" Wrong password!");
      lcd.print(" Wrong password!");
      delay(2000);
      lcd.clear();
   } 
   
   password.reset(); 
   currentPasswordLength = 0; 
}  

void opendoor()
{
  for (pos = 180; pos >= 0; pos -= 1)// goes from 180 degrees to 0 degrees // in steps of 1 degree
  { 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 50ms for the servo to reach the position
  }
}

 void lockdoor()
 {
   for (lockpos = 0; lockpos <= 180; lockpos += 1)// goes from 0 degrees to 180 degrees // in steps of 1 degree
  { 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 50ms for the servo to reach the position
  }
}
 
 
