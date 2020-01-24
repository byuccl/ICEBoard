#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

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

#define BUZZER_PIN 9

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);
Adafruit_NeoPixel strip(LED_COUNT, NEOPIXEL_PIN, NEO_GRBW + NEO_KHZ800);

void setup()
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
    lcd.begin(16, 2);
    strip.begin();
}

void loop()
{
    int S1 = digitalRead(S1_PIN);
    int S2 = digitalRead(S2_PIN);
    int S3 = digitalRead(S3_PIN);
    int S4 = digitalRead(S4_PIN);
    int BUp = digitalRead(BU_PIN);
    int BLeft = digitalRead(BL_PIN);
    int BCenter = digitalRead(BC_PIN);
    int BRight = digitalRead(BR_PIN);
    int BDown = digitalRead(BD_PIN);
    String switches = "Switches: ";
    switches += S1;
    switches += S2;
    switches += S3;
    switches += S4;

    String buttons = "Buttons: ";
    buttons += BUp;
    buttons += BLeft;
    buttons += BCenter;
    buttons += BRight;
    buttons += BDown;

    // Serial.println(switches);
    // Serial.println(buttons);

    lcd.clear();
    lcd.print(switches);
    lcd.setCursor(0, 1);
    lcd.print(buttons);

    // Buzzer
    if (digitalRead(10))
    {
        analogWrite(BUZZER_PIN, 128);
    }
    else
    {
        analogWrite(BUZZER_PIN, 0);
    }

    // Neopixels
    int brightness = digitalRead(BL_PIN) + digitalRead(BC_PIN) + digitalRead(BU_PIN) + digitalRead(BR_PIN) + digitalRead(BD_PIN);

    // scale brightness to 0-255 range
    brightness *= 51;

    int red = brightness * digitalRead(S1_PIN);
    int green = brightness * digitalRead(S2_PIN);
    int blue = brightness * digitalRead(S3_PIN);
    int white = brightness * digitalRead(S4_PIN);

    int i;
    for (i = 0; i < LED_COUNT; i++)
    {
        strip.setPixelColor(i, red, green, blue, white);
    }
    strip.show();

    delay(100);
}