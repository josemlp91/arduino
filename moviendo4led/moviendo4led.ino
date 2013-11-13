
int sensorPin = A0; //Pin del LDR 
int myRelee = 0  ;  //Pin controla rele
int sensorValue = 0;  //Valor leido por sensor

int led=2
int led1=4
int led2=6
int led3=8

void setup() {
 
  pinMode(led, OUTPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
   
  if (sensorValue<256){   //Establecemos el umbral a 300 (entre 0-1024)

    digitalWrite(led, HIGH);
    digitalWrite(led1, LOW);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);    
    Serial.println("Un led encencido");
    
  }
  
  else if ((sensorValue>=256) &&(sensorValue<500) ) {  
    digitalWrite(led, HIGH);
    digitalWrite(led1,HIGH);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);    
    Serial.println("Dos leds encendido");
 
  }

  else if ((sensorValue>=500) &&(sensorValue<750) ) {  
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
