/*
  Sketch for a single LED which is controlled by a simple UI.
 
  Copyright (c) 2012 Fabian Affolter <fabian@affolter-engineering.ch>
  All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define LED_1 13  // Arduino Digital I/O pin number 13

int state = 0;  // Digital output, state is 0, Low, off
int inState = 0;  // Set the initial state to 0

void setup() {                
  digitalWrite(LED_1, state);  // Set LED to OFF at reset
  pinMode(LED_1, OUTPUT);  // Set LED pin as output
  delay(2000);  // Wait for 2 s
  Serial.begin(9600);  // Setup the serial monitor for debugging
}

void loop() {
  char inVal = 0;  // Set the incoming value to 0
  if (Serial.available() > 0) {
    inVal = Serial.read() - '0';
    if (inVal == 1) {
      inState = 1;
    } else if (inVal == 0) {
      inState = 0;
    } else {
      Serial.println("Only 1 (on) and 0 (off) are supported.");
    }
    if (inState != state) {
      state = inState;
      digitalWrite(LED_1, state);  // Set the LED
      Serial.print("State is now: ");  // Prints the current state
      Serial.println(state);           // help with debugging
    }
  }
}
