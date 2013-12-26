#include <crono.h>
#include <TimerOne.h>

char lectura;
crono c=crono(10);

void setup() {                
  char lectura;
   c.Start();
   Timer1.initialize(6000000);
   Timer1.attachInterrupt( timerFunction );
 
  Serial.begin(9600); 
}

void timerFunction() { c.MedidaParcial();}

// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available()>0){ 
        lectura = Serial.read();
        
        switch ( lectura ) {
            case 'S':
              c.Start();
              
              break;
            case 's':
              c.Stop();
              break;
              
             case 'P':
             c.MedidaParcial();
             break;
             
             case 'M':
             Serial.print(c.GetMediaMedidas());
             break;
              
             case 'T':
             Serial.println(c.GetTiempoTotal());
            break;
           
           case 'U':
          Serial.println (c.GetUltimaMedida());
          break;
         
          case 'N':
         Serial.println (c.GetnumMedidas());
        break; 
              
}
  }}
        

