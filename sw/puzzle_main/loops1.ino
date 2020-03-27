#include "puzzles.h"
#include "iceBoard.h"

#define LOOP1_DELAY_ON 3000
#define LOOP1_DELAY_OFF 1000

void loops1()
{

    while (!digitalRead(BD_PIN))
    {
        leds.setPixelColor(3, RED);
        leds.show();
        delay(LOOP1_DELAY_ON);
        leds.setPixelColor(3, OFF);
        leds.show();
        delay(LOOP1_DELAY_OFF);
        leds.setPixelColor(3, BLUE);
        leds.show();
        delay(LOOP1_DELAY_ON);
        leds.setPixelColor(3, OFF);
        leds.show();
        delay(LOOP1_DELAY_OFF);
        leds.setPixelColor(3, GREEN);
        leds.show();
        delay(LOOP1_DELAY_ON);
        leds.setPixelColor(3, OFF);
        leds.show();
        delay(LOOP1_DELAY_OFF);
    }
    puzzle_done();
}