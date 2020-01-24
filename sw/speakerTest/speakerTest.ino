#define BUZZER_PIN 9

void setup()
{
    // TCCR1B = (TCCR1B & B11111000) | B00000010;
    // analogWrite(BUZZER_PIN, 128);
}

void loop()
{
    if (digitalRead(10))
    {
        analogWrite(BUZZER_PIN, 128);
    }
    else
    {
        analogWrite(BUZZER_PIN, 0);
    }
}