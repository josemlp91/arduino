/****************************************/
/********** EL COCHE FANTÁSTICO *********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include "Depuracion.h"
#include "ActuadorLuces.h"

/** VARIABLES **/

ActuadorLucesDirecto luces;
  
/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup(){
   Serial.begin(9600);
  //Por polimorfismo, iniciamos una u otra para hacer las mediciones.
  luces = ActuadorLucesDirecto();
  luces.iniciar();
}

/**
 * Bucle infinito de ejecución.
 */
void loop(){
  delayMicroseconds(tiempoDelay);
  startTemporizador();
  luces.secuencia();
  stopTemporizador();
  luces.desplazar();
}
