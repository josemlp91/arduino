#define LED 13
int val = 0;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    
    
    if (Serial.available()) {
        char c = Serial.read();
        if (c == 'H') {
            digitalWrite(LED, HIGH);
        }
        else if (c == 'L') {
            digitalWrite(LED, LOW);
        }
        
        
    }
    val = analogRead(0);//leer el valor del sensor de A0
    Serial.println(val);
    delay(1000);
}
