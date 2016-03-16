#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void lightsOn() {
  uint32_t c = Wheel(random(0,255));
  strip.setPixelColor(0, c);
  strip.setPixelColor(1, c);
  strip.setPixelColor(2, c);
  strip.setPixelColor(3, c);
  strip.show();
}

void lightsOff() {
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);  
  strip.show();
}

void loop() {
  int sensVal = analogRead(A0);
  if (sensVal < 100) {
    lightsOn();
  } else {
    lightsOff();
  }
  Serial.println(sensVal);
  delay(100);
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
