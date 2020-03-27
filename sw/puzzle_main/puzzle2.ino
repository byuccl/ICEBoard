#include "puzzle_main.h"
#include "iceBoard.h"

void puzzle2()
{
  lcd.clear();
  lcd.print("Puzzle 2");
  delay(2000);

  uint8_t A = 0;
  uint8_t B = 0;

  // const uint32_t BLUE = pack_color(0, 0, BRIGHTNESS);
  // const uint32_t GREEN = pack_color(0, BRIGHTNESS, 0);

  lcd.clear();
  lcd.print(A);
  lcd.print("+");
  lcd.print(B);
  lcd.print("=");
  lcd.print(A + B);

  while (((A + B) != 10) || (A < 2) || (B < 3))
  {
    if (digitalRead(BU_PIN) && digitalRead(BR_PIN))
    {
      A++;
      leds.setPixelColor(0, BLUE);
      leds.show();
      lcd.clear();
      delay(1000);
      leds.setPixelColor(0, 0);
      leds.show();
      lcd.print(A);
      lcd.print("+");
      lcd.print(B);
      lcd.print("=");
      lcd.print(A + B);
    }
    else if (digitalRead(BC_PIN) && digitalRead(BD_PIN))
    {
      B++;
      leds.setPixelColor(7, GREEN);
      leds.show();
      lcd.clear();
      delay(1000);
      leds.setPixelColor(7, 0);
      leds.show();
      lcd.print(A);
      lcd.print("+");
      lcd.print(B);
      lcd.print("=");
      lcd.print(A + B);
    }
  }

  delay(2000);
  puzzle_done();
}
