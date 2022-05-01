#include<Servo.h>
Servo myservo;
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int pos;
void setup() {
  myservo.attach(7);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(13,OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  
  // Calculating the distance
  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  
  
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    myservo.write(pos); 
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; 
    Serial.print(distance);
    if(distance<=20)
  {digitalWrite(13,HIGH);// tell servo to go to position in variable 'pos'
    delay(15);  }
    else
    {digitalWrite(13,LOW);// tell servo to go to position in variable 'pos'
    delay(15);
      // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);// goes from 180 degrees to 0 degrees
    myservo.write(pos); 
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; 
    Serial.print(distance);
    if(distance<=20)
  {digitalWrite(13,HIGH);// tell servo to go to position in variable 'pos'
    delay(15);  }
    else
    {digitalWrite(13,LOW);// tell servo to go to position in variable 'pos'
    delay(15);
      // waits 15ms for the servo to reach the position
  }// tell servo to go to position in variable 'pos'
                         // waits 15ms for the servo to reach the position
  
  }
  }}
 
