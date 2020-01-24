#define S1_PIN 4
#define S2_PIN 5
#define S3_PIN 6
#define S4_PIN 7

#define BU_PIN 11
#define BL_PIN 1
#define BC_PIN 10
#define BD_PIN 12
#define BR_PIN 13

#include <LiquidCrystal.h>

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

void setup()
{
  // Serial.begin(9600);
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
  delay(100);
}
