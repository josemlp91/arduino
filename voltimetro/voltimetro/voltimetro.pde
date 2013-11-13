/**
* Representación de valor procedente de un sensor.
*/
import processing.serial.*;
import cc.arduino.*;
int[] xvals; // Array que almacenara los valores leídos
int val; // Valor leído
int arrayindex = 0; // Puntero o índice del array
Arduino arduino;
int potPin=0;
void setup()
{
size(256, 256);
xvals = new int[width];
arduino = new Arduino(this, Arduino.list()[0], 57600);
PFont font;
font = loadFont("sansserif-24.vlw");
textFont(font);
}
void draw()
{
background(0);
// shift array left by one
for(int i=1; i<width; i++) {
xvals[i-1] = xvals[i];
}
// añade un nuevo valor al final del array
//lee la entrada analógica (0..1024), divide su valor por 4 (0..255)
// to stay within canvas drawing limits
val = arduino.analogRead(potPin);
xvals[width-1] = val/4;
// dibuja el array
for(int i=1; i<width; i++) {
stroke(255);
point(i, 255-xvals[i]); //flip y coordinate so 0 is at bottom
}
textAlign(RIGHT);
text(val, 200, 30);
text(5.0*(xvals[width-1]/255.0)+"V",200,60);
}
