#include <RGBmatrixPanel.h>

/* button setup */
const int switchPin = 2;
const int ledPin = 5;

int ledState = LOW;
int currentState = LOW;
int lastState = LOW;

unsigned long lastDebounceTime;
unsigned long debounceTime = 50;

/* LED matrix setup */
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);
int locationx = 0;
int locationy = 0;
//location x, y is the corner of the square of the pipe area


void setup() {
  // button
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // LED matrix
  matrix.begin();
}

void loop() {
  int readSwitch = digitalRead(switchPin);

  //check to see if new read is same as old state, if not then new lastDebounceTime
  if(readSwitch != lastState){
    lastDebounceTime = millis();
  }
  
  // put your main code here, to run repeatedly:
  if((millis()-lastDebounceTime)>debounceTime){
    //we only want to do something if the state changes
    if(readSwitch!=currentState){
      currentState = readSwitch;
      if(currentState == HIGH){
        //toggle between on and off
        ledState = !ledState;
          if (ledState){
            draw_vertical_pipe();
          }
          else{
            draw_horizontal_pipe();
          }
      }
    }
  }
  lastState = readSwitch;
}

void draw_vertical_pipe(void){
  //Vertical Pipe
  //filling pipe rectangle
  matrix.fillRect(locationx, locationy, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on bottom side
  matrix.drawRect(locationx + 3, locationy, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 1, 4, 1, matrix.Color444(0,0,0));
  //middle rectangle
  matrix.drawRect(locationx + 4, locationy + 2, 4, 8, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 5, locationy + 3, 2, 6, matrix.Color444(0,0,0));
  //rectangle on top side
  matrix.drawRect(locationx + 3, locationy + 9, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 10, 4, 1, matrix.Color444(0, 0, 0));
}

void draw_horizontal_pipe(void){
  //Horizontal Pipe
  //filling pipe rectangle
  matrix.fillRect(locationx, locationy, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on right side
  matrix.drawRect(locationx, locationy + 3, 3, 6, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 1, locationy + 4, 1, 4, matrix.Color444(0,0,0));
  //middle rectangle
  matrix.drawRect(locationx + 2, locationy + 4, 8, 4, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 3, locationy + 5, 6, 2, matrix.Color444(0,0,0));
  //rectangle on left side
  matrix.drawRect(locationx + 9, locationy + 3, 3, 6, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 10, locationy + 4, 1, 4, matrix.Color444(0, 0, 0));
}
