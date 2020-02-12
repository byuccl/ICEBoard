#include "puzzle_main.h"

void puzzle3()
{
    lcd.clear();
    lcd.print("Puzzle 3");

    // Blink LED1
    while (1)
    {
        leds.setPixelColor(0, YELLOW);
        leds.show();
        delay(5000);
        leds.setPixelColor(0, OFF);
        leds.show();
        // delay(500);

        if (digitalRead(S4_PIN))
        {
            leds.setPixelColor(0, RED);
            leds.show();

            while (digitalRead(S4_PIN))
                ;
        }
        else
        {
            delay(3000);
            if (digitalRead(S4_PIN))
                break;
        }
    }

    puzzle_done();
}