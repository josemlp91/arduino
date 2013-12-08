#include <IRremote.h>
#include <SD.h>

/*Recordad
Pin 51 -> MOSI
Pin 50 -> MISO
Pin 52 -> SCK
Pin 53 -> Chip Select
Lo alimento con 3.3 voltios.
El formato de la tarjeta SD es FAT32.

*/

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
String DatosEscribir;
File myFile;
int CS=53;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(CS, OUTPUT);

  if (!SD.begin(CS)) {
    Serial.println("initialization failed!");
    return;
  }
  
   Serial.println("initialization done.");
   

}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    //Serial.println(results.value);
    switch (results.value ) {  
    case 4105841032:
      Serial.println("Apagar");
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
      Serial.println("Tecla: 0");
      DatosEscribir=DatosEscribir + "0";
      break;
      
   case 2331063592:
      Serial.println("ENTER");
      myFile = SD.open("test1.txt", FILE_WRITE);
      if (myFile) {
        myFile.println(DatosEscribir);
        Serial.println(DatosEscribir);
        myFile.close();
        Serial.println("done.");
             
        DatosEscribir="";
        
        myFile = SD.open("test1.txt");
      }
      else {Serial.println("No se crea el archivo");}
  
      if (myFile) {
      Serial.println("test.txt:");
      
      while (myFile.available()) {
      	Serial.write(myFile.read());
      }
      
      myFile.close();
      } else {
    	// if the file didn't open, print an error:
      Serial.println("No se lee el archivo");
      }
              
      break;
     
  }
  irrecv.resume(); // Receive the next value
  }
}


