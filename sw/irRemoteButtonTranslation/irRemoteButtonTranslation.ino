/**
 * DecodeIR.ino
 * 
 * Uses IRremote library to take in NEC codes and translates them to button values 
 * 
 * Does not currently debounce buttons which causes issue with printing consistantly to the screen
 * 
 * Current issue with other ir interference, prints "Not a button detected" when detected
 * This interference can be caused by phone cameras that use IR sensors, the receiver picks
 * the hex codes up and tries to translate them.
 * 
 */

#include <IRremote.h>
#include <LiquidCrystal.h>

#define VOLUME_MINUS_TEXT "Vol-"
#define PLAY_PAUSE_TEXT ">||"
#define VOLUME_PLUS_TEXT "Vol+"
#define SETUP_TEXT "Setup"
#define UP_TEXT "^"
#define STOP_MODE_TEXT "Stop/Mode"
#define LEFT_TEXT "<"
#define ENTER_SAVE_TEXT "Enter/Save"
#define RIGHT_TEXT ">"
#define ZERO_TEXT "0"
#define DOWN_TEXT "V"
#define BACK_ARROW_TEXT "<--"
#define ONE_TEXT "1"
#define TWO_TEXT "2"
#define THREE_TEXT "3"
#define FOUR_TEXT "4"
#define FIVE_TEXT "5"
#define SIX_TEXT "6"
#define SEVEN_TEXT "7"
#define EIGHT_TEXT "8"
#define NINE_TEXT "9"

#define VOLUME_MINUS_HEX 0x00FF
#define PLAY_PAUSE_HEX 0x807F
#define VOLUME_PLUS_HEX 0x40BF
#define SETUP_HEX 0x20DF
#define UP_HEX 0xA05F
#define STOP_MODE_HEX 0x609F
#define LEFT_HEX 0x10EF
#define ENTER_SAVE_HEX 0x906F
#define RIGHT_HEX 0x50AF
#define ZERO_HEX 0x30CF
#define DOWN_HEX 0xB04F
#define BACK_ARROW_HEX 0x708F
#define ONE_HEX 0x08F7
#define TWO_HEX 0x8877
#define THREE_HEX 0x48B7
#define FOUR_HEX 0x28D7
#define FIVE_HEX 0xA857
#define SIX_HEX 0x6897
#define SEVEN_HEX 0x18E7
#define EIGHT_HEX 0x9867
#define NINE_HEX 0x58A7

// Pin on board with IR sensor
int IR_INPUT_PIN = 2;

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);
IRrecv receivedInput(IR_INPUT_PIN);
decode_results raw_remote_codes;


uint16_t currentCode = 0;
uint16_t previousCode = 0;

//Decodes the received hex as a numerical value. Non-numeric values return as 10
int8_t decodeNumber(uint16_t code);

//Decodes the received hex and tells which button was pressed in a string
String getButtonText(uint16_t code);

void setup() {
  receivedInput.enableIRIn(); // Start the receiver
}

void loop() {
  if (receivedInput.decode(&raw_remote_codes)) {
    previousCode = currentCode;
    currentCode = raw_remote_codes.value;
    lcd.clear();
    lcd.print(getButtonText(currentCode));
    if (decodeNumber(currentCode) != -1)
    {
      //Do something if button has been pressed and is valid
    }
    else
    { 
      // If button has been pressed and is not valid
      
      // Shows if non-remote value has been misidentified
      lcd.clear();
      lcd.print("Not a button detected");
    }
    receivedInput.resume(); // Receive the next value
  }
}

//Returns the text of the button the remote is sending
String getButtonText(uint16_t code)
{
    String str;
// Prints raw hex code of the button press
//  if (code != 0xFFFF)
//  {
//    Serial.print(code, HEX);
//    Serial.print("\t");
//  }
  switch (code) {
    case VOLUME_MINUS_HEX: 
      str = VOLUME_MINUS_TEXT;
      break;
    case PLAY_PAUSE_HEX:
      str = PLAY_PAUSE_TEXT;
      break;
    case VOLUME_PLUS_HEX:
      str = VOLUME_PLUS_TEXT;
      break;
    case SETUP_HEX:
      str = SETUP_TEXT;
      break;
    case UP_HEX:
      str = UP_TEXT;
      break;
    case STOP_MODE_HEX:
      str = STOP_MODE_TEXT;
      break;
    case LEFT_HEX:
      str = LEFT_TEXT;
      break;
    case ENTER_SAVE_HEX:
      str = ENTER_SAVE_TEXT;
      break;
    case RIGHT_HEX:
      str = RIGHT_TEXT;
      break;
    case ZERO_HEX:
      str = ZERO_TEXT;
      break;
    case DOWN_HEX:
      str = DOWN_TEXT;
      break;
    case BACK_ARROW_HEX:
      str = BACK_ARROW_TEXT;
      break;
    case ONE_HEX:
      str = ONE_TEXT;
      break;
    case TWO_HEX:
      str = TWO_TEXT;
      break;
    case THREE_HEX:
      str = THREE_TEXT;
      break;
    case FOUR_HEX:
      str = FOUR_TEXT;
      break;
    case FIVE_HEX:
      str = FIVE_TEXT;
      break;
    case SIX_HEX:
      str = SIX_TEXT;
      break;
    case SEVEN_HEX:
      str = SEVEN_TEXT;
      break;
    case EIGHT_HEX:
      str = EIGHT_TEXT;
      break;
    case NINE_HEX:
      str = NINE_TEXT;
      break;
    default:
      break;
  }
  return str;
}

//Returns int translation of what the remote is sending
int8_t decodeNumber(uint16_t code)
{
  if (code != 0xFFFF)
  {
    switch (code) {
      case VOLUME_MINUS_HEX:
      case PLAY_PAUSE_HEX:
      case VOLUME_PLUS_HEX:
      case SETUP_HEX:
      case UP_HEX:
      case STOP_MODE_HEX:
      case LEFT_HEX:
      case ENTER_SAVE_HEX:
      case RIGHT_HEX:
      case DOWN_HEX:
      case BACK_ARROW_HEX:
        return 10;
      case ZERO_HEX:
        return 0;
      case ONE_HEX:
        return 1;
      case TWO_HEX:
        return 2;
      case THREE_HEX:
        return 3;
      case FOUR_HEX:
        return 4;
      case FIVE_HEX:
        return 5;
      case SIX_HEX:
        return 6;
      case SEVEN_HEX:
        return 7;
      case EIGHT_HEX:
        return 8;
      case NINE_HEX:
        return 9;
      default:
        return -1;
    }
  }
}
