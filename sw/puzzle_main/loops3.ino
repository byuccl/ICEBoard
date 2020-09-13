#include "puzzles.h"
#include "iceBoard.h"

/* this didn't work
void forLoop(iterations) 
{
  int i;
      for (i = iterations; i > 0; i--)  
      {
        leds.setPixelColor(i - 1, PURPLE);
        leds.show();
        delay(2000);
      }
}
*/

void loops3()
{
    while (1)
    {
      leds.setPixelColor(LED1, GREEN);
      leds.setPixelColor(LED2, GREEN);
      leds.setPixelColor(LED3, GREEN);
      leds.setPixelColor(LED4, GREEN);
      leds.show();
      delay(2000);
  
      int buttonChoice = 4;
      int i = 0;
      
      if (digitalRead(BU_PIN))
      {
        buttonChoice = 1;
        for (i = buttonChoice; i > 0; i--)  
        {
          leds.setPixelColor(i - 1, PURPLE);
          leds.show();
          delay(2000);
        }
        break;    
      }
      
      else if (digitalRead(BR_PIN))
      {
        buttonChoice = 2;
        for (i = buttonChoice; i > 0; i--)  
        {
          leds.setPixelColor(i - 1, PURPLE);
          leds.show();
          delay(2000);
        }    
        break;  
      }
    
      else if (digitalRead(BD_PIN))
      {
        buttonChoice = 3;
        for (i = buttonChoice; i > 0; i--)  
        {
          leds.setPixelColor(i - 1, PURPLE);
          leds.show();
          delay(2000);
        }
        break;      
      }
    
      else if (digitalRead(BL_PIN))
      {
        buttonChoice = 4;
        for (i = buttonChoice; i > 0; i--)  
        {
          leds.setPixelColor(i - 1, PURPLE);
          leds.show();
          delay(2000);
        }
        break;     
      }
    }

    puzzle_done();
}
