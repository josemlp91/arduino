/*
  Autor: Mario Pérez Esteso
  Web: www.geekytheory.com
  Twitter: @geekytheory
  Facebook: www.facebook.com/geekytheory
*/
int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int Pin_pulsador = 2;
int Pin_analog = 0;

boolean LED_pico = false; 
int Valor_pico = 0;

void setup()                 
{
  for (int i = 0; i < 10; i++)
  {
     pinMode(ledPins[i], OUTPUT); 
  }
  pinMode(Pin_pulsador, INPUT);
  Serial.begin(9600);
}

void loop()                   
{
  if (digitalRead(Pin_pulsador))
  {
    LED_pico = ! LED_pico;
    Valor_pico = 0;
    delay(200);
  }
  int senyal_sonido = analogRead(Pin_analog);
  int LED_mayor = map(senyal_sonido, 0, 1023, 0, 10); //map(value, fromLow, fromHigh, toLow, toHigh)
  if (LED_mayor > Valor_pico) //Comparo LEDs
  {
    Valor_pico = LED_mayor;//Asigno el valor de LED_mayor a Valor_pico
  }
  for (int i = 0; i < 10; i++)
  {
      digitalWrite(ledPins[i], (i <= LED_mayor || (LED_pico && i == Valor_pico)));
      //Enciendo hasta el valor de LED más alto
  }
  Serial.println(senyal_sonido);
}