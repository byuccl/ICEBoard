#define BUZZER_PIN 9

#define NEOPIXEL_PIN 3
#define LED_COUNT 8

#define S1_PIN 4
#define S2_PIN 5
#define S3_PIN 6
#define S4_PIN 7

#define BU_PIN 11
#define BL_PIN 1
#define BC_PIN 10
#define BD_PIN 12
#define BR_PIN 13

#define BRIGHTNESS 10

#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

Adafruit_NeoPixel leds(LED_COUNT, NEOPIXEL_PIN, NEO_GRBW + NEO_KHZ800);
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

void setup_io()
{
  pinMode(S1_PIN, INPUT);
  pinMode(S2_PIN, INPUT);
  pinMode(S3_PIN, INPUT);
  pinMode(S4_PIN, INPUT);

  pinMode(BU_PIN, INPUT);
  pinMode(BL_PIN, INPUT);
  pinMode(BC_PIN, INPUT);
  pinMode(BD_PIN, INPUT);
  pinMode(BR_PIN, INPUT);

  Serial.begin(9600);
}

void setup()
{
  setup_io();
  lcd.begin(16, 2);
  leds.begin();
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