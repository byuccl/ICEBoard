#ifndef __PUZZLE_MAIN_H__
#define __PUZZLE_MAIN_H__

#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

extern Adafruit_NeoPixel leds;
extern LiquidCrystal lcd;

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

#define OFF (0)
#define BLUE (BRIGHTNESS)
#define GREEN (BRIGHTNESS << 8)
#define RED (((uint32_t)BRIGHTNESS) << 16)
#define YELLOW (RED | GREEN)
#define PURPLE (RED | BLUE)
#define AQUA (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

void puzzle_done();
uint32_t pack_color(uint8_t red, uint8_t green, uint8_t blue);

#endif