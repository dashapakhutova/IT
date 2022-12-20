#include <FastLED.h>
#define led_pin 13
int s;

#define NUM_LEDS 15
#define DATA_PIN 7
#define CLOCK_PIN 15

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
}

void loop() {
  while (Serial.available()){
    s = Serial.read();
  }
  if( s == '1'){
    digitalWrite(led_pin, HIGH);
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Red;
    }
    FastLED.show();
    delay(500);
  }
  else if(s == '0'){
    digitalWrite(led_pin, LOW);
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    delay(500);
  }
}
