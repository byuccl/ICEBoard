
#include "iceBoard.h"
#include "puzzles.h"

void setup()
{
    iceboard_setup_io();
    turn_off_leds();
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Pick w/ switches");
    lcd.setCursor(0, 1);

    int puzzle_idx = digitalRead(S1_PIN) * 8 + digitalRead(S2_PIN) * 4 + digitalRead(S3_PIN) * 2 + digitalRead(S4_PIN);

    lcd.print("BCen. starts #  ");
    lcd.setCursor(14, 1);
    lcd.print(puzzle_idx);

    if (digitalRead(BC_PIN))
    {
        lcd.clear();
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
        case 4:
            lcd.print("Program #");
            lcd.print(puzzle_idx);
            lcd.setCursor(0, 1);
            lcd.print("Learning Loops 1");
            loops1();
            break;
        case 5:
            lcd.print("Program #");
            lcd.print(puzzle_idx);
            lcd.setCursor(0, 1);
            lcd.print("Learning Ifs 1");
            ifStatement1();
            break;
        case 6:
            lcd.print("Program #");
            lcd.print(puzzle_idx);
            lcd.setCursor(0, 1);
            lcd.print("Puzzle 4");
            puzzle4();
            break;
        }
    }
}

void puzzle_done()
{

    // Play noise
    analogWrite(BUZZER_PIN, 128);
    delay(500);
    analogWrite(BUZZER_PIN, 0);

    lcd.clear();
    lcd.print("You win");
    lcd.setCursor(0, 1);
    lcd.print("Press BCenter");
    while (!digitalRead(BC_PIN))
        ;
    while (digitalRead(BC_PIN))
        ;
    turn_off_leds();
}

uint32_t pack_color(uint8_t red, uint8_t green, uint8_t blue)
{
    return ((uint32_t)red << 16) | ((uint32_t)green << 8) | ((uint32_t)blue);
}

void turn_off_leds()
{
    for (int i = 0; i < 7; i++)
        leds.setPixelColor(i, OFF);
    leds.show();
}