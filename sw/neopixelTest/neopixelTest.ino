
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

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif

    strip.begin();
}

void loop()
{

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
}