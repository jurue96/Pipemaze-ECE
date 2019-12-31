
#include <RGBmatrixPanel.h>

/* button setup (Wire to be NC)*/
const int switchPin = 2;

int currentState = LOW;
int lastState = LOW;

unsigned long lastDebounceTime;
unsigned long debounceTime = 50;

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

//#define CLK  8   // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define TWO_WAY   0
#define THREE_WAY 1
#define FOUR_WAY  2

//rotate clockwise
#define ZERO        1
#define NINETY      2
#define ONE_EIGHTY  3
#define TWO_SEVENTY 4

#define BUFFER  0
#define REGULAR 1

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

class pipe {
  public:
  byte pos_x;
  byte pos_y;
  byte zone_type;
  byte pipe_type;
  byte rotation;

  pipe();
  //~pipe();
  void rotate();
  void change_pos();
};

pipe::pipe(){
  this->pos_x = 0;
  this->pos_y = 0;
}

pipe test_pipe;

//pipe pipe_array[25];

/*void two_way_horizontal(byte x, byte y){
  //block edges
  //matrix.drawRect(0, 0, 12, 12, matrix.Color333(169, 169, 169));
  //matrix.fillRect(0, 0, 12, 12, matrix.Color444(0x92, 0x97, 0xbf));
  //top rec
  matrix.fillRect(3, 0, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 0, 6, 3, matrix.Color444(0x3a,0x3b,0x39));
  //bottom rec
  matrix.fillRect(3, 9, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 9, 6, 3, matrix.Color444(0x3a,0x3b,0x39));
  //middle rec
  matrix.fillRect(4, 2, 4, 8, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(4, 2, 4, 8, matrix.Color444(0x3a,0x3b,0x39));
}
*/

void two_way_v(byte x, byte y){
  matrix.drawRect(x, y, 12, 12, matrix.Color333(169, 169, 169));
  matrix.fillRect(x, y, 12, 12, matrix.Color444(0x92, 0x97, 0xbf));
  //top rec
  matrix.fillRect(x+3, y, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(x+3, y, 6, 3, matrix.Color444(0x3a,0x3b,0x39));
  //bottom rec
  matrix.fillRect(x+3, y+9, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(x+3, y+9, 6, 3, matrix.Color444(0x3a,0x3b,0x39));
  //middle rec
  matrix.fillRect(x+4, y+2, 4, 8, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(x+4, y+2, 4, 8, matrix.Color444(0x3a,0x3b,0x39));
}

void two_way_h(byte x, byte y){
  matrix.fillRect(x, y, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on bottom side
  matrix.drawRect(x + 3, y, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(x + 4, y + 1, 4, 1, matrix.Color444(0,0,0));
  //middle rectangle
  matrix.drawRect(x + 4, y + 2, 4, 8, matrix.Color444(4, 4, 4));
  matrix.fillRect(x + 5, y + 3, 2, 6, matrix.Color444(0,0,0));
  //rectangle on top side
  matrix.drawRect(x + 3, y + 9, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(x + 4, y + 10, 4, 1, matrix.Color444(0, 0, 0));
}

void three_way_0(byte x, byte y){
  
}

void three_way_90(byte x, byte y){
  
}

void three_way_180(byte x, byte y){
  
}

void three_way_270(byte x, byte y){
  
}

void four_way(byte x, byte y){
  
}

/*
 * @pipe object
 * base on pipe object values, print the pipe onto the display
 */
void print_pipe(pipe cur_pipe){
  byte degree = cur_pipe.rotation;
  switch(cur_pipe.pipe_type){
  case TWO_WAY:
    if (degree == ZERO || degree == ONE_EIGHTY)
      two_way_h(cur_pipe.pos_x, cur_pipe.pos_y);
    if (degree == NINETY || degree == TWO_SEVENTY)
      two_way_v(cur_pipe.pos_x, cur_pipe.pos_y);
    break;
  case THREE_WAY:
    if (degree == ZERO)
      three_way_0(cur_pipe.pos_x, cur_pipe.pos_y);
    if (degree == NINETY)
      three_way_90(cur_pipe.pos_x, cur_pipe.pos_y);
    if (degree == ONE_EIGHTY)
      three_way_180(cur_pipe.pos_x, cur_pipe.pos_y);
    if (degree == TWO_SEVENTY)
      three_way_270(cur_pipe.pos_x, cur_pipe.pos_y);
    break;
  case FOUR_WAY:
    four_way(cur_pipe.pos_x, cur_pipe.pos_y);
  }
}

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  matrix.begin();
  Serial.begin(9600);

  test_pipe.pos_x = 0;
  test_pipe.pos_y = 0;
  test_pipe.zone_type = REGULAR;
  test_pipe.pipe_type = TWO_WAY;
  test_pipe.rotation = ZERO;

  print_pipe(test_pipe);
  //three way up
  /*matrix.fillRect(3, 0, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 0, 6, 3, matrix.Color444(0x3a,0x3b,0x39));
 
  matrix.fillRect(0, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(0, 3, 3, 6, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(9, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(9, 3, 3, 6, matrix.Color444(0x3a,0x3b,0x39));

  matrix.drawRect(4, 2, 4, 6, matrix.Color444(0x3a,0x3b,0x39));
  matrix.drawRect(2, 4, 8, 4, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(5, 3, 2, 4, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.fillRect(3, 5, 6, 2, matrix.Color444(0xb0, 0xd9, 0xbb));
  */
  
  //three way down
/*  matrix.fillRect(3, 9, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 9, 6, 3, matrix.Color444(0x3a,0x3b,0x39));
 
  matrix.fillRect(0, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(0, 3, 3, 6, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(9, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(9, 3, 3, 6, matrix.Color444(0x3a,0x3b,0x39));

  matrix.drawRect(4, 4, 4, 6, matrix.Color444(0x3a,0x3b,0x39));
  matrix.drawRect(2, 4, 8, 4, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(5, 5, 2, 4, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.fillRect(3, 5, 6, 2, matrix.Color444(0xb0, 0xd9, 0xbb));
*/
  //three way left
  /*
  matrix.fillRect(3, 0, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 0, 6, 3, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(9, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(9, 3, 3, 6, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(3, 9, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 9, 6, 3, matrix.Color444(0x3a,0x3b,0x39));

  matrix.drawRect(4, 2, 4, 8, matrix.Color444(0x3a,0x3b,0x39));
  matrix.drawRect(4, 4, 6, 4, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(5, 3, 2, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.fillRect(5, 5, 4, 2, matrix.Color444(0xb0, 0xd9, 0xbb));
  */
  //three way right
 /*
  matrix.fillRect(3, 0, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 0, 6, 3, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(3, 9, 6, 3, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(3, 9, 6, 3, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(0, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(0, 3, 3, 6, matrix.Color444(0x3a,0x3b,0x39));

  matrix.drawRect(4, 2, 4, 8, matrix.Color444(0x3a,0x3b,0x39));
  matrix.drawRect(2, 4, 6, 4, matrix.Color444(0x3a,0x3b,0x39));

  matrix.fillRect(5, 3, 2, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.fillRect(3, 5, 4, 2, matrix.Color444(0xb0, 0xd9, 0xbb));
  */
  //four way
  /*matrix.fillRect(0, 0, 12, 12, matrix.Color444(0xa8, 0x7c, 0xa0));
  
  matrix.fillRect(3, 0, 6, 3, matrix.Color444(0x55, 0x55, 0x55));
  matrix.drawRect(3, 0, 6, 3, matrix.Color444(0x55,0x55,0x55));

  matrix.fillRect(3, 9, 6, 3, matrix.Color444(0x55, 0x55, 0x55));
  matrix.drawRect(3, 9, 6, 3, matrix.Color444(0x55,0x55,0x55));

  matrix.fillRect(0, 3, 3, 6, matrix.Color444(0x55, 0x55, 0x55));
  matrix.drawRect(0, 3, 3, 6, matrix.Color444(0x55,0x55,0x55));

  matrix.fillRect(9, 3, 3, 6, matrix.Color444(0xb0, 0xd9, 0xbb));
  matrix.drawRect(9, 3, 3, 6, matrix.Color444(0x55,0x55,0x55));

  matrix.drawRect(4, 2, 4, 8, matrix.Color444(0x55,0x55,0x55));
  matrix.drawRect(2, 4, 8, 4, matrix.Color444(0x55,0x55,0x55));

  matrix.fillRect(5, 3, 2, 6, matrix.Color444(0x55, 0x55, 0x55));
  matrix.fillRect(3, 5, 6, 2, matrix.Color444(0x55, 0x55, 0x55));
  */
}

void loop() {
  int readSwitch = digitalRead(switchPin);
  Serial.println(readSwitch);
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
        byte current_rot = test_pipe.rotation % 4;
        test_pipe.rotation = (current_rot == 0) ? 1 : (test_pipe.rotation + 1);  
        //Serial.println(test_pipe.rotation);
        print_pipe(test_pipe); 
      }
    }
  }
  lastState = readSwitch;


}
