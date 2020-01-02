# ICEBoard Datasheets

## Components

### Arduino Nano

- Purpose: This is the ICEBoard processor.  All of the other components on the board are powered and software-controlled by the Arduino Nano.
- Description: 
- [Website](https://store.arduino.cc/usa/arduino-nano)
- [Datasheet](./nano-user-manual)
- Notes:

### LCD

- Purpose: 
- Description: Adafruit standard LCD 16x2 + extras - white on blue, through hole
- [Website](https://www.adafruit.com/product/181)
- [Datasheet](./TC1602A-09T)
- Notes: We are using the TC1602A-09T because it pulls significantly less current than the TC1602A-01T.  The [TC1602A-01T datasheet](./TC1602A-01T) is included in this folder for reference because it includes page 4 (the part drawing), which the TC1602A-09T datasheet is missing.

### NeoPixel

- Purpose: 
- Description: NeoPixel 5050 RGB LED with Integrated Driver Chip, surface mount
- [Website](https://www.adafruit.com/product/1655)
- [Datasheet](./SK6812_LED_datasheet)
- Notes: NeoPixels require only one digital pin for an entire chain.  Each NeoPixel requires up to 60mA of current.

### Slide Switch

- Purpose: 
- Description: Switch Slide DPDT 300mA 6V, surface mount
- [Website](https://www.digikey.com/products/en?keywords=401-2002-1-ND)
- [Datasheet](./JS202011SCQN_datasheet)
- Notes: The DPDT switch was cheaper than all of the single pull slide switches I could find on Digi-Key.

### Tactile Switch

- Purpose: 
- Description: Switch Tactile SPST-NO 0.05A 12V, surface mount
- [Website](https://www.digikey.com/products/en?keywords=CKN10889CT-ND)
- [Datasheet](./PTS645_datasheet)
- Notes: The footprint will work for a few different colors of push buttons.

### IR Receiver

- Purpose: 
- Description: Sensor Remote Rec 40.0kHz 45M, through hole
- [Website](https://www.digikey.com/products/en?keywords=TSOP38240-ND)
- [Datasheet](./tsop382_datasheet)
- Notes: This part comes in different frequencies.

### Battery Holder

- Purpose: 
- Description: Battery Holder 9V PC Pin, through hole
- [Website](https://www.digikey.com/products/en?keywords=BH9V-PC-ND)
- [Datasheet](./BH9VPC-datasheet)
- Notes: 

### Buzzer

- Purpose: 
- Description: Piezo Transducer 5V 5mA 4kHz 75dB@5V, through hole
- [Website](https://www.digikey.com/products/en?keywords=2104-TP124005-2CT-ND)
- [Datasheet](./TP124005-2_drawing)
- Notes: 

### Potentiometer

- Purpose:
- Description: Trimmer 10k Ohm 0.1W J Lead Top, surface mount
- [Website](https://www.digikey.com/product-detail/en/bourns-inc/TC33X-2-103E/TC33X-103ECT-ND/612911)
- [Datasheet](./tc33_datasheet)
- Notes: The -2 part has a rotational stop and the -1 part has continous rotation.  The footprints are identical.
