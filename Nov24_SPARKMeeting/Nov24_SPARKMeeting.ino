/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
int LEDPIN = 10;
int LEDPIN2 = 8;
int Sensor = A5;
int Sensor2 = A6;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(Sensor, INPUT_PULLUP);
  Serial.begin(Sensor2, INPUT_PULLUP);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
}



// the loop function runs over and over again forever
void loop() {
  int proximity = analogRead(Sensor);
  if(proximity == LOW){
    Serial.println("hello");
    digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(30); // wait for a second
  }
  else{                  
    digitalWrite(LEDPIN, LOW);    // turn the LED off by making the voltage LOW
    delay(30); // wait for a second
  }

  int proximity2 = analogRead(Sensor2);
  if(proximity2 == LOW){
    Serial.println("hello");
    digitalWrite(LEDPIN2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(30); // wait for a second
  }
  else{                  
    digitalWrite(LEDPIN2, LOW);    // turn the LED off by making the voltage LOW
    delay(30); // wait for a second
  }
}
