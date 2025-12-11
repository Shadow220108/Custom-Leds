#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    300
#define BRIGHTNESS  80
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define POWER_LIMIT_MA 12000

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLED);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, POWER_LIMIT_MA); 
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    fill_solid(leds, NUM_LEDS, CRGB::Black); 
    
    leds[i] = CRGB::Red;                 
    if (i > 0)    leds[i-1] = CRGB::DarkRed; 
    if (i > 1)    leds[i-2] = CRGB::DarkRed / 4; 
    
    FastLED.show();
    delay(10); 
  }
  
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    fill_solid(leds, NUM_LEDS, CRGB::Black); 
    
    leds[i] = CRGB::Red;
    if (i < NUM_LEDS - 1) leds[i+1] = CRGB::DarkRed;
    if (i < NUM_LEDS - 2) leds[i+2] = CRGB::DarkRed / 4;
    
    FastLED.show();
    delay(10); 
  }
}
