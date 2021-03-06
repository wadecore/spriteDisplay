#include <Adafruit_NeoPixel.h>

const int PIXEL_PIN = 6;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(80, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int  rxByte= 0;

// Ayyo Sprite
uint8_t spriteSurprise[][3] = {   
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {34, 200, 34}, {34, 200, 34}, {34, 200, 34}, {34, 200, 34}, {34, 200, 34}, {34, 200, 34}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                       };

// Checki Sprite
uint8_t spriteChecki[][3] = {   
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, 
                            {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, 
                            {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255},
                            {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255},
                            {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255},
                       };

// NG Sprite
uint8_t spriteNG[][3] = {   
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, 
                            {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, 
                            {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, 
                            {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255},
                            {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                       };

// Test Sprite
uint8_t spriteTest[][3] = {
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                            {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, 
                       };

// Weh Sprite
uint8_t spriteWeh[][3] = {   
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, 
                            {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {21, 148, 156}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, 
                            {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {21, 148, 156}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, 
                            {0, 0, 0}, {21, 148, 156}, {21, 148, 156}, {21, 148, 156}, {21, 148, 156}, {21, 148, 156}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                       };

// Smiley Sprite
uint8_t spriteSmiley[][3] = {   
                            {0, 0, 0}, {255, 255, 0}, {255, 255, 0}, {255, 174, 0}, {0, 0, 0}, {0, 0, 0}, {255, 174, 0}, {255, 255, 0}, {255, 255, 0}, {0, 0, 0}, 
                            {255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, 
                            {0, 0, 0}, {255, 174, 0}, {255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {255, 174, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 255, 0}, {255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {255, 255, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {255, 174, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 174, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {255, 174, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 174, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                       };

// Ayyo Sprite
uint8_t spriteAyyo[][3] = {   
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, 
                            {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {34, 200, 255}, {34, 200, 255}, {34, 200, 255}, {34, 200, 255}, {34, 200, 255}, {34, 200, 255}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                       };

// Anger Sprite
uint8_t spriteAnger[][3] = {   
                            {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                       };

// Nope Sprite
uint8_t spriteNope[][3] = {   
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                       };

// Save Sprite
uint8_t spriteSave[][3] = {   
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {50, 50, 50}, {50, 50, 50}, {50, 50, 50}, {50, 50, 50}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {50, 50, 50}, {50, 50, 50}, {0, 0, 0}, {50, 50, 50}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {50, 50, 50}, {50, 50, 50}, {0, 0, 0}, {50, 50, 50}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 255, 255}, {50, 50, 50}, {50, 50, 50}, {50, 50, 50}, {50, 50, 50}, {255, 255, 255}, {255, 0, 0}, {0, 0, 0},
                            {0, 0, 0}, {255, 0, 0}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 0, 0}, {0, 0, 0}, 
                            {0, 0, 0}, {255, 0, 0}, {255, 255, 255}, {50, 50, 50}, {50, 50, 50}, {50, 50, 50}, {50, 50, 50}, {255, 255, 255}, {255, 0, 0}, {0, 0, 0},
                       };


void setup() 
{
  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
  
  Serial.begin(38400);
  Serial.flush();       // Clear receive buffer.
}
void loop()
{  
  for(uint8_t i = 0; i < 80; i++)
  {
    int r = spriteAyyo[i][0];
    int g = spriteAyyo[i][1];
    int b = spriteAyyo[i][2]; 
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
  
  if (Serial.available() > 0)
  {          // Check receive buffer.
      rxByte = Serial.read();            // Save character received. 
      Serial.flush();                    // Clear receive buffer.

    switch (rxByte) {
      
      case 111:                          // If received 111
        Serial.print("Saving...");
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteSave[i][0];
          int g = spriteSave[i][1];
          int b = spriteSave[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 112:                          // If received 112
        Serial.print("Thats no good");
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteNG[i][0];
          int g = spriteNG[i][1];
          int b = spriteNG[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 113:                          // If received 113
        Serial.print("TEST");
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteTest[i][0];
          int g = spriteTest[i][1];
          int b = spriteTest[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 114:                          // If received 114
        Serial.print("Nope");
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteNope[i][0];
          int g = spriteNope[i][1];
          int b = spriteNope[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 115:                          // If received 115
        Serial.print("oh hey flashy");      
        theaterChase(strip.Color(127, 127, 127), 50); // White
      break;

      case 116:                          // If received 116
        Serial.print("Weh");      
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteWeh[i][0];
          int g = spriteWeh[i][1];
          int b = spriteWeh[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 117:                          // If received 117
        Serial.print("Mad AF");      
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteAnger[i][0];
          int g = spriteAnger[i][1];
          int b = spriteAnger[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 118:                          // If received 118
        Serial.print("Smileys in ur Email");      
        
        for(uint8_t i = 0; i < 80; i++)
        {
          int r = spriteSmiley[i][0];
          int g = spriteSmiley[i][1];
          int b = spriteSmiley[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(2000);
      break;

      case 119:                          // If received 119
        Serial.print("Hella Red");      
        theaterChase(strip.Color(127, 0, 0), 20); // Red
      break;
      
      case 120:                          // If received 120
        Serial.print("Hella Green");      
        theaterChase(strip.Color(0, 127, 0), 20); // Green
      break;
      
      case 121:                          // If received 121
        Serial.print("Hella Blue");      
        theaterChase(strip.Color(0, 0, 127), 20); // Blue
      break;
      
      case 122:                          // If received 122
        Serial.print("WOW A RAINBOW");      
        rainbow(20);
      break;
          
      case 123:                          // If received 123
        Serial.print("DOUBLE RAINBOW");      
        rainbowCycle(20);
      break;
      
      case 124:                          // If received 124
        Serial.print("ALL THE WAY ACROSS THE SKY");      
        theaterChaseRainbow(20);
      break;

      case 125:                          // If received 125
        Serial.print(" O K . ");         
        for(uint8_t i = 0; i < 80; i++)
        {     
          int r = spriteChecki[i][0];
          int g = spriteChecki[i][1];
          int b = spriteChecki[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(1000);        
      break;

      case 126:                          // If received 126
        Serial.print("HECK.");            
        for(uint8_t i = 0; i < 80; i++)
        {  
          int r = spriteSurprise[i][0];
          int g = spriteSurprise[i][1];
          int b = spriteSurprise[i][2]; 
          strip.setPixelColor(i, strip.Color(r, g, b));
        }   
        strip.show();
        delay(1000);        
      break;
      
      default:                           
        Serial.println("not a command, dummy!");
      break;
    }
  }
}








// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
