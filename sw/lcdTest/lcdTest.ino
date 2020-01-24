#include <LiquidCrystal.h>

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

void setup()
{
    lcd.print("hello, world!");
}

void loop() {}