int x_out = A1; /* connect x_out of module to A1 of UNO board */
int y_out = A2; /* connect y_out of module to A2 of UNO board */
int z_out = A3; /* connect z_out of module to A3 of UNO board */
int buzzer=3;
int Reset_button=4;
void help();
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(Reset_button,INPUT);
   
}

void loop() {
  int x_adc_value, y_adc_value, z_adc_value; 
  double x_g_value, y_g_value, z_g_value;
  double roll, pitch, yaw;
  x_adc_value = analogRead(x_out); /* Digital value of voltage on x_out pin */ 
  y_adc_value = analogRead(y_out); /* Digital value of voltage on y_out pin */ 
  z_adc_value = analogRead(z_out); /* Digital value of voltage on z_out pin */ 
  Serial.print("x = ");
  Serial.print(x_adc_value);
  Serial.print("\t\t");
  Serial.print("y = ");
  Serial.print(y_adc_value);
  Serial.print("\t\t");
  Serial.print("z = ");
  Serial.print(z_adc_value);
  Serial.println("\t\t");
  delay(500);


   x_adc_value = analogRead(x_out); /* Digital value of voltage on x_out pin */ 
  y_adc_value = analogRead(y_out); /* Digital value of voltage on y_out pin */ 
  z_adc_value = analogRead(z_out); /* Digital value of voltage on z_out pin */ 
  if(Reset_button ==HIGH)
    {
      Serial.println("System resetting........");
      digitalWrite(buzzer,LOW);
    }
  if(y_adc_value <330 || y_adc_value>350 || z_adc_value<420 && Reset_button != HIGH)
  {
    
    delay(100);
     //while(Reset_button != HIGH)
      Serial.println("Accident");
      digitalWrite(buzzer,HIGH);
      help();
    }
    else
  {
    Serial.println("Safe");
    digitalWrite(buzzer,LOW);
  }
    //}
   // digitalWrite(buzzer,HIGH);
   // delay(5000);
    if(Reset_button == HIGH)
  
    {
      Serial.println("System resetting........");
      digitalWrite(buzzer,LOW);
      
    }
    
  
  
  }
 void help()
  {
    Serial.print("inhelp");
    
    delay(20000);
    if(Reset_button ==HIGH)
    {
      Serial.println("System resetting........");
      digitalWrite(buzzer,LOW);
    }
    else
    {help();}
  
   // {
      
      
   // }
  }
