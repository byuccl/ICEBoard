#include <Adafruit_NeoPixel.h>
#define LED_COUNT 1
#define LED_PIN 3
#define BUZZER_PIN 9

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(1, INPUT);
  strip.begin();
  strip.show();
}

void loop()

{
  int S1 = digitalRead(4);
  int S2 = digitalRead(5);
  int S3 = digitalRead(6);
  int S4 = digitalRead(7);
  int BUp = digitalRead(11);
  int BLeft = digitalRead(1);
  int BCenter = digitalRead(10);
  int BRight = digitalRead(13);
  int BDown = digitalRead(12);
  String switches = "S1:";
  switches += S1;
  switches += " S2:";
  switches += S2;
  switches += " S3:";
  switches += S3;
  switches += " S4:";
  switches += S4;
  switches += " BUp:";
  switches += BUp;
  switches += " BLeft:";
  switches += BLeft;
  switches += " BCenter:";
  switches += BCenter;
  switches += " BRight:";
  switches += BRight;
  switches += " BDown:";
  switches += BDown;
  //  + " S3:" + S3 + " S4:" + S4;
  Serial.println(switches);
  delay(500);

  strip.setPixelColor(0, 100, 0, 0);
}
