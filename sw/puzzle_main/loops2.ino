#include "puzzles.h"
#include "iceBoard.h"

void loops2()
{
    while (digitalRead(BC_PIN))
        ;
    int x = 0;

    leds.setPixelColor(LED1, GREEN);
    leds.show();

    while (x < 10)
    {
        while (!digitalRead(BC_PIN))
            ;
        while (digitalRead(BC_PIN))
            ;
        lcd.clear();
        lcd.print("X is ");
        lcd.print(x);

        leds.setPixelColor(LED2, leds.getPixelColor(LED3));
        leds.setPixelColor(LED3, leds.getPixelColor(LED4));
        leds.setPixelColor(LED4, leds.getPixelColor(LED8));
        leds.setPixelColor(LED8, leds.getPixelColor(LED7));
        leds.setPixelColor(LED7, leds.getPixelColor(LED6));
        leds.setPixelColor(LED6, leds.getPixelColor(LED5));
        leds.setPixelColor(LED5, leds.getPixelColor(LED1));
        leds.setPixelColor(LED1, leds.getPixelColor(LED2));
        leds.show();

        x++;
    }

    puzzle_done();
}