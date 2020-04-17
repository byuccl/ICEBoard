#include "puzzles.h"
#include "iceBoard.h"

void ifStatement1()
{
    while (1)
    {
        if (digitalRead(BL_PIN))
        {

            leds.setPixelColor(LED5, RED);
            leds.setPixelColor(LED6, ORANGE);
            leds.setPixelColor(LED7, YELLOW);
            leds.show();
            if (digitalRead(BR_PIN))
                break;
        }
        else
        {
            leds.setPixelColor(LED5, BLUE);
            leds.setPixelColor(LED6, AQUA);
        }
        leds.setPixelColor(LED7, GREEN);
        leds.show();
    }
    puzzle_done();
}