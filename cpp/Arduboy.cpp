#include "Arduboy.h"

Arduboy::Arduboy() {

}

void Arduboy::begin()
{
//   boot(); // required
//   bootUtils();

//   bootLogo();

//   // Audio
//   tunes.initChannel(PIN_SPEAKER_1);
//   tunes.initChannel(PIN_SPEAKER_2);
//   audio.begin();
    jsBegin();
}

void Arduboy::setFrameRate(uint8_t rate)
{
// frameRate = rate;
// eachFrameMillis = 1000/rate;
    jsSetFrameRate(rate);
}

bool Arduboy::nextFrame()
{
//   long now = millis();
//   uint8_t remaining;

//   // post render
//   if (post_render) {
//     lastFrameDurationMs = now - lastFrameStart;
//     frameCount++;
//     post_render = false;
//   }

//   // if it's not time for the next frame yet
//   if (now < nextFrameStart) {
//     remaining = nextFrameStart - now;
//     // if we have more than 1ms to spare, lets sleep
//     // we should be woken up by timer0 every 1ms, so this should be ok
//     if (remaining > 1)
//       idle();
//     return false;
//   }

//   // pre-render

//   // technically next frame should be last frame + each frame but if we're
//   // running a slow render we would constnatly be behind the clock
//   // keep an eye on this and see how it works.  If it works well the
//   // lastFrameStart variable could be eliminated completely
//   nextFrameStart = now + eachFrameMillis;
//   lastFrameStart = now;
//   post_render = true;
//   return post_render;
return jsNextFrame();
}

void Arduboy::setCursor(int16_t x, int16_t y)
{
//   cursor_x = x;
//   cursor_y = y;
    jsSetCursor(x, y);
}

void Arduboy::clear()
{
  //fillScreen(BLACK);
  jsClear();
}

#define HEIGHT 128
#define WIDTH 64
int data[WIDTH * HEIGHT];
int timescalled = 0;

void Arduboy::display()
{
  //this->paintScreen(sBuffer);

  for (int y = 0; y < HEIGHT; y++) {
     int yw = y * WIDTH;
     for (int x = 0; x < WIDTH; x++) {
       data[yw + x] = (255 << 24) | (timescalled << 8) | 255;
     }
   }
   timescalled++;
  jsDisplay(&data[0]);
}

void Arduboy::print(const char* text) {
    jsPrint(text);
}