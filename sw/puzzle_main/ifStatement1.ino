#include "puzzles.h"
#include "iceBoard.h"

void ifStatement1()
{
    while (1)
    {
        if (digitalRead(BL_PIN))
        {

            leds.setPixelColor(4, RED);
            leds.setPixelColor(5, ORANGE);
            leds.setPixelColor(6, YELLOW);
            leds.show();
        }
        else
        {
            leds.setPixelColor(4, BLUE);
            leds.setPixelColor(5, AQUA);
            leds.setPixelColor(6, GREEN);
            leds.show();
            if (digitalRead(BR_PIN))
                break;
        }
    }
    puzzle_done();
}