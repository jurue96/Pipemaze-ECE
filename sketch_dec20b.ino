
#include <RGBmatrixPanel.h>

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
#define ZERO        0
#define NINETY      1
#define ONE_EIGHTY  2
#define TWO_SEVENTY 3

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
  ~pipe();
  void rotate();
  void change_pos();
}

pipe pipe_array[25];

void two_way_horizontal(byte x, byte y){
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

void two_way_vertical(byte x. byte y){
  
}
/*
 * @pipe object
 * base on pipe object values, print the pipe onto the display
 */
void print_pipe(pipe cur_pipe){
  switch(cur_pipe.pipe_type){
  case TWO_WAY:
    rotation = cur_pipe.rotation;
    if (rotation == ZERO || rotation == ONE_EIGHTY)
      two_way_h(cur_pipe.pos_X, cur_pipe.pos_y);
    if (rotation == NINETY || rotation == TWO_SEVENTY)
      two_way_v(cur_pipe.pos_x, cur_pipe.pos_y);
    break;
  case THREE_WAY:
    rotation = cur_pipe.rotation;
    if (rotation == ZERO)
      three_way_0(cur_pipe.pos_x, cur_pipe.pos_y);
    if (rotation == NINET)
      three_way_90(cur_pipe.pos_x, cur_pipe.pos_y);
    if (rotation == ONE_EIGHTY)
      three_way_180(cur_pipe.pos_x, cur_pipe.pos_y);
    if (rotation == TWO_SEVENTY)
      three_way_270(cur_pipe.pos_x, cur_pipe.pos_y);
    break;
  case FOUR_WAY:
    four_way(cur_pipe.pos_x, cur_pipe.pos_y);
  }
}

void setup() {
  matrix.begin();
  //block edges
  //matrix.drawRect(0, 0, 12, 12, matrix.Color333(169, 169, 169));
  matrix.fillRect(0, 0, 12, 12, matrix.Color444(0x92, 0x97, 0xbf));
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

void loop() {
  // put your main code here, to run repeatedly:

}
