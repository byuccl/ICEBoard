/*
   IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
   An IR detector/demodulator must be connected to the input RECV_PIN.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  
  pinMode(7, OUTPUT); // sets the digital pin 7 on
  pinMode(5, OUTPUT); // sets the digital pin 7 on
  pinMode(13, OUTPUT); // sets the digital pin 7 on
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value != 0xFFFFFFFF)
    {
      Serial.print(results.value, HEX);
      Serial.print("\t");
    }
    switch (results.value) {
      case 0xFD00FF:
        Serial.println("Vol-");
        digitalWrite(7, HIGH); // sets the digital pin 13 on
        delay(500);            // waits for a second
        digitalWrite(7, LOW);  // sets the digital pin 13 off
        break;
      case 0xFD807F:
        Serial.println(">||");
        digitalWrite(5, HIGH); // sets the digital pin 13 on
        delay(500);            // waits for a second
        digitalWrite(5, LOW);  // sets the digital pin 13 off
        break;
      case 0xFD40BF:
        Serial.println("Vol+");
        digitalWrite(13, HIGH); // sets the digital pin 13 on
        delay(500);            // waits for a second
        digitalWrite(13, LOW);  // sets the digital pin 13 off
        break;
      case 0xFD20DF:
        Serial.println("Setup");
        break;
      case 0xFDA05F:
        Serial.println("^");
        break;
      case 0xFD609F:
        Serial.println("Stop/Mode");
        break;
      case 0xFD10EF:
        Serial.println("<");
        break;
      case 0xFD906F:
        Serial.println("Enter/save");
        break;
      case 0xFD50AF:
        Serial.println(">");
        break;
      case 0xFD30CF:
        Serial.println("0/10+");
        break;
      case 0xFDB04F:
        Serial.println("V");
        break;
      case 0xFD708F:
        Serial.println("<-");
        break;
      case 0xFD08F7:
        Serial.println("1");
        break;
      case 0xFD8877:
        Serial.println("2");
        break;
      case 0xFD48B7:
        Serial.println("3");
        break;
      case 0xFD28D7:
        Serial.println("4");
        break;
      case 0xFDA857:
        Serial.println("5");
        break;
      case 0xFD6897:
        Serial.println("6");
        break;
      case 0xFD18E7:
        Serial.println("7");
        break;
      case 0xFD9867:
        Serial.println("8");
        break;
      case 0xFD58A7:
        Serial.println("9");
        break;

    }
    irrecv.resume(); // Receive the next value
  }
}
