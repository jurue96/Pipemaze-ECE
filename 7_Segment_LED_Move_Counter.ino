//always connect pin A5 on the arduino to the C pin on the 7-segment LED Backpack
//always connect pin A4 on the arduino to The D pin // // // ...

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

int switch1=10;
bool flag=LOW;

uint16_t counter = 0;

void setup() {
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);

  pinMode(switch1, INPUT);
}

  
void loop() {
  
  matrix.println(counter);
  matrix.writeDisplay();

  if (flag==LOW){
    if(digitalRead(switch1)==HIGH){
      counter=counter+1;
      matrix.println(counter);
      matrix.writeDisplay();
      flag=HIGH;
      }
      
  }
 else if(digitalRead(switch1)==LOW){
       flag=LOW;
     }
}
