int relay=3;
int button=4;
int trigpin=5;
int echopin=6;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(relay,OUTPUT);
pinMode(button,INPUT);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration *(.034/2);
  if(distance <1-0)

  {
  digitalWrite(relay,HIGH);
  delay(1000);
  }
  else
  {digitalWrite(relay,LOW);}

}
