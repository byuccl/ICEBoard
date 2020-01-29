#define BRIGHTNESS 10

uint32_t pack_color(uint8_t red, uint8_t green, uint8_t blue)
{
    return ((uint32_t)red << 16) | ((uint32_t)green << 8) | ((uint32_t)blue);
}

void puzzle1()
{
    lcd.clear();
    lcd.print("Puzzle 1");

    uint32_t led[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int i;
    for (i = 0; i < LED_COUNT; i++)
        leds.setPixelColor(i, led[i]);

    const uint32_t BLUE = pack_color(0, 0, BRIGHTNESS);
    const uint32_t GREEN = pack_color(0, BRIGHTNESS, 0);
    const uint32_t YELLOW = pack_color(BRIGHTNESS, BRIGHTNESS, 0);
    const uint32_t PURPLE = pack_color(BRIGHTNESS, 0, BRIGHTNESS);

    while (!(led[0] == BLUE && led[1] == YELLOW && led[2] == GREEN && led[3] == PURPLE))
    {
        while (!digitalRead(BC_PIN))
        {
            bool S1 = digitalRead(S1_PIN);
            bool S2 = digitalRead(S2_PIN);
            bool S3 = digitalRead(S3_PIN);

            uint8_t red = BRIGHTNESS * S1;
            uint8_t green = BRIGHTNESS * S2;
            uint8_t blue = BRIGHTNESS * S3;

            led[7] = pack_color(red, green, blue);

            // Serial.println(led0);
            leds.setPixelColor(7, led[7]);
            leds.show();
        }

        led[3] = led[1];
        led[1] = led[2];
        led[2] = led[0];
        led[0] = led[7];

        for (i = 0; i < LED_COUNT; i++)
            leds.setPixelColor(i, led[i]);
        leds.show();

        while (digitalRead(BC_PIN))
            ;
        delay(100);
    }

    // Play noise
    analogWrite(BUZZER_PIN, 128);
    delay(500);
    analogWrite(BUZZER_PIN, 0);

    lcd.clear();
    lcd.print("You win");
}