
#include "iceBoard.h"

void setup()
{
    iceboard_setup_io();
}

void loop()
{
    int puzzle_idx = digitalRead(S1_PIN) * 8 + digitalRead(S2_PIN) * 4 + digitalRead(S3_PIN) * 2 + digitalRead(S4_PIN);

    switch (puzzle_idx)
    {
    case 1:
        puzzle1();
        break;
    case 2:
        puzzle2();
        break;
    case 3:
        puzzle3();
        break;
    }
    while (1)
        ;
}

void puzzle_done()
{

    // Play noise
    analogWrite(BUZZER_PIN, 128);
    delay(500);
    analogWrite(BUZZER_PIN, 0);

    lcd.clear();
    lcd.print("You win");
}

uint32_t pack_color(uint8_t red, uint8_t green, uint8_t blue)
{
    return ((uint32_t)red << 16) | ((uint32_t)green << 8) | ((uint32_t)blue);
}