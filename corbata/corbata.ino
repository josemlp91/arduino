
        int sensorPin = A0; //Pin del LDR 
        int myRelee = 0  ;  //Pin controla rele
        int sensorValue = 0;  //Valor leido por sensor

        int led=2;
        int led1=4;
        int led2=6;
        int led3=8;
        int analogPin=0;
void setup() {
 
  pinMode(led, OUTPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {

  int mn = 1024;     // mn only decreases
  int mx = 0;        // mx only increases

  // Perform 10000 reads. Update mn and mx for each one.
  for (int i = 0; i < 1000; ++i) {
    int val = analogRead(analogPin);
    mn = min(mn, val);
    mx = max(mx, val);
  }

  
  Serial.print("m=");
  Serial.print(mn);  
  Serial.print(" M=");
  Serial.print(mx);  
  Serial.print(" D=");
  Serial.print(mx-mn);  
  Serial.println();  

  int dif=mx-mn;
   
  if (dif<30){   //Establecemos el umbral a 256 (entre 0-1024)

    digitalWrite(led, LOW);
    digitalWrite(led1, LOW);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);    
    Serial.println("Un led encencido");
    
  }

  else if ((dif>=30) &&(dif<200) ) {  
    digitalWrite(led, HIGH);
    digitalWrite(led1,LOW);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);    
    Serial.println("Dos leds encendido");
 
  }

  
  else if ((dif>=200) &&(dif<330) ) {  
    digitalWrite(led, HIGH);
    digitalWrite(led1,HIGH);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);    
    Serial.println("Dos leds encendido");
 
  }

  else if ((dif>=330) &&(dif<470) ) {  
    digitalWrite(led, HIGH);
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, LOW);    
    Serial.println("Tres leds encendido");
 
  }


else {

    digitalWrite(led, HIGH);
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, HIGH);    
    Serial.println("Todos leds encendido");


}

   
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue); 
}
