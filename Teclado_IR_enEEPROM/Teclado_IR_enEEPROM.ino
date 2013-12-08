#include <IRremote.h>
#include<EEPROM.h>



int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
String DatosEscribir;
int pinIn=0;
int i;
int valor;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    //Serial.println(results.value);
    switch (results.value ) {  
    case 4105841032:
      Serial.println("Mostrar Datos EEPROM \n");
      
      i=-1;
      valor=10;
      while ((i<512) && (valor>0)){
        i++;
        valor=EEPROM.read(i);
        Serial.print("\t");
        Serial.print(valor,DEC);  
      }

      break;
    
    case 3778927144:
      Serial.println("Tecla: 1");
      DatosEscribir=DatosEscribir + "1";
      break;
      
   case 2908251746:
      Serial.println("Tecla: 2");
      DatosEscribir=DatosEscribir + "2";
      break;
   
   case 657459652:
      Serial.println("Tecla: 3");
      DatosEscribir=DatosEscribir + "3";
      break;
      
    case 4120482440:
      Serial.println("Tecla: 4");
      DatosEscribir=DatosEscribir + "4";
      break;
      
   case 1931099650:
      Serial.println("Tecla: 5");
      DatosEscribir=DatosEscribir + "5";
      break;
      
  case 742730860:
      Serial.println("Tecla: 6");
      DatosEscribir=DatosEscribir + "6";
      break;
      
  case 1167253836:
      Serial.println("Tecla: 7");
      DatosEscribir=DatosEscribir + "7";
      break;
            
  case 1747313982:
      Serial.println("Tecla: 8");
      DatosEscribir=DatosEscribir + "8";
      break;
          
  case 2340753640:
      Serial.println("Tecla: 9");
      DatosEscribir=DatosEscribir + "9";
      break;
      
  case 3119867746:
      Serial.println(" \n Reset \n");
      for (i = 0; i < 512; i++) EEPROM.write(i, 0);
      break;
      
   case 2331063592:
      Serial.println("\n ENTER \n");
      int valor=analogRead(pinIn)/4;
      i=-1; int aux=1;
      while ((i<512) && (aux>0)){
        i++;
        aux=EEPROM.read(i);
        
        
      }
      
      EEPROM.write(i, valor);
      Serial.println("Guardado datos analogicos \n");             
      break;
     
  }
  
  irrecv.resume(); // Receive the next value
  }
}


