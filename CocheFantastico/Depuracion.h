/****************************************/
/************** DEPURACIÓN **************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#ifndef _DEPURACION_H_

#define _DEPURACION_H_ 1

#include <Arduino.h>

/** DEFINICIONES **/

#define DEPURAR        false  //Activo mostrará por el puerto serial datos de depuración.
#define TEMPORIZADORES true  //Activo contará el tiempo de inicialización e iteraciones.
//Tiempo de delay para el bucle.
#define tiempoDelay 500000

/** FUNCIONES **/

void startTemporizador();
void stopTemporizador();

#endif
