// testshapes demo for RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 32x64 RGB LED matrix.

// WILL NOT FIT on ARDUINO UNO -- requires a Mega, M0 or M4 board

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

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
  int locationx = 0;
  int locationy = 0;
  //location x, y is the corner of the square of the pipe area
  matrix.begin();
  
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

  // I'm unsure what is left and what is right in this case, so some of the shapes may be mixed up.


  //corner pipe - down + right
  //filling pipe rectangle
  matrix.fillRect(locationx, locationy, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on down side
  matrix.drawRect(locationx + 3, locationy + 9, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 10, 4, 1, matrix.Color444(0, 0, 0));
  //rectangle on right side
  matrix.drawRect(locationx + 9, locationy + 3, 3, 6, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 10, locationy + 4, 1, 4, matrix.Color444(0, 0, 0));
  //connecting rectangle(s)
  //outer trace
  matrix.fillRect(locationx + 4, locationy + 4, 4, 5, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 8, locationy + 4, 1, 4, matrix.Color444(4, 4, 4));
  //inner fill
  matrix.fillRect(locationx + 5, locationy + 5, 2, 4, matrix.Color444(0, 0, 0));
  matrix.fillRect(locationx + 7, locationy + 5, 2, 2, matrix.Color444(0, 0, 0));

 //corner pipe - down + left
  //filling pipe rectangle
  matrix.fillRect(locationx, locationy, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on down side
  matrix.drawRect(locationx + 3, locationy + 9, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 10, 4, 1, matrix.Color444(0, 0, 0));
  //rectangle on left side
  matrix.drawRect(locationx, locationy + 3, 3, 6, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 1, locationy + 4, 1, 4, matrix.Color444(0,0,0));
  //connecting rectangle(s)
  //outer trace
  matrix.fillRect(locationx + 4, locationy + 4, 4, 5, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 3, locationy + 4, 1, 4, matrix.Color444(4, 4, 4));
  //inner fill
  matrix.fillRect(locationx + 5, locationy + 5, 2, 4, matrix.Color444(0, 0, 0));
  matrix.fillRect(locationx + 3, locationy + 5, 2, 2, matrix.Color444(0, 0, 0));


  //Corner pipe - up + right
  //filling pipe rectangle
  matrix.fillRect(locationx, locationy, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on up side
  matrix.drawRect(locationx + 3, locationy, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 1, 4, 1, matrix.Color444(0,0,0));
  //rectangle on right side
  matrix.drawRect(locationx + 9, locationy + 3, 3, 6, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 10, locationy + 4, 1, 4, matrix.Color444(0, 0, 0));
  //connecting rectangle(s)
  //outer trace
  matrix.fillRect(locationx + 4, locationy + 3, 4, 5, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 8, locationy + 4, 1, 4, matrix.Color444(4, 4, 4));
  //inner fill
  matrix.fillRect(locationx + 5, locationy + 3, 2, 4, matrix.Color444(0, 0, 0));
  matrix.fillRect(locationx + 7, locationy + 5, 2, 2, matrix.Color444(0, 0, 0));
 
  //corner pipe - up + left
  //filling pipe rectangle
  matrix.fillRect(locationx, locationy, 12, 12, matrix.Color444(1, 0, 5));
  //rectangle on top side
  matrix.drawRect(locationx + 3, locationy, 6, 3, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 1, 4, 1, matrix.Color444(0,0,0));
  //rectangle on left side
  matrix.drawRect(locationx, locationy + 3, 3, 6, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 1, locationy + 4, 1, 4, matrix.Color444(0,0,0));
  //connecting rectangle(s)
  //outer trace
  matrix.fillRect(locationx + 3, locationy + 4, 5, 4, matrix.Color444(4, 4, 4));
  matrix.fillRect(locationx + 4, locationy + 3, 4, 1, matrix.Color444(4, 4, 4));
  //inner fill
  matrix.fillRect(locationx + 5, locationy + 3, 2, 4, matrix.Color444(0, 0, 0));
  matrix.fillRect(locationx + 3, locationy + 5, 2, 2, matrix.Color444(0, 0, 0));

}
/*
class horizontalPipe() {
  public:
  int x;
  int y;
  RGBmatrixPanel matrix;
  horizontalPipe(int xPixel, int yPixel, RGBmatrixPanel m) {
    x = xPixel;
    y = yPixel;
    matrix = m;
  }
}
*/

void loop() {
  //nothing
}
