
int sensorPin = A0; //Pin del LDR 
int myRelee = 0  ;  //Pin controla rele
int sensorValue = 0;  //Valor leido por sensor

void setup() {
 
  pinMode(myRelee, OUTPUT); //Ponemos el pin del rele de salida
  Serial.begin(9600);

}

void loop() {
   
  if (sensorValue<300){   //Establecemos el umbral a 300 (entre 0-1024)

    digitalWrite(myRelee, HIGH);  
    Serial.println("Relee apagado");
    delay(1000);  //Pequeño retardo cuando la lampara esta encendida.
  }
  
  else {  
    digitalWrite(myRelee, LOW);  
    Serial.println("Relee encendido");
 
  }
   
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue); 
}
