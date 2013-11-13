  const int myRelee = 2;   // Declaramos la salida del relee  
                          // LOW encendido HIGH apagado  
  
 void setup(){  
   // Relee  
   pinMode(myRelee, OUTPUT);   
   // Declaramos que el pin sera salida  
   // Preparamos el puerto serie  
   Serial.begin(9600);  
 }  
  
 void loop(){  
   digitalWrite(myRelee, HIGH);  
   Serial.println("Relee encendido");  
   delay (2000);  
   digitalWrite(myRelee, LOW);  
   Serial.println("Relee apagado");  
   delay (2000);  
 }  

