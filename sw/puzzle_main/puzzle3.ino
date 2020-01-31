#include "puzzle_main.h"

void puzzle3()
{
    // Blink LED1
    while (1)
    {
        leds.setPixelColor(1, YELLOW);
        leds.show();
        delay(5.0);
        leds.setPixelColor(1, OFF);
        leds.show();
        delay(1.0);

        if (digitalRead(BD_PIN))
            break;
    }

    puzzle_done();
}