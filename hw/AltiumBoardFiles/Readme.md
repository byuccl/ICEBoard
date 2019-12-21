#Board Design notes on answered questions:
- There is a software way to turn the NeoPixels on part way so we do not need resistors to dim them.
- All of the traces are routed on the top of the board so the bottom layer can be a ground plane.
- The Arduino cannot supply enough current to have all the LEDs on at full power at the same time.  Make sure software accounts for that.
- The datasheet says that the LCD screen takes 40mA for logic and 30mA for the backlight.  Stephanie measured the currents to be 19mA and 0.6mA.
- [This](https://www.ftdichip.com/Support/Documents/DataSheets/ICs/DS_FT232R.pdf) is the datasheet for the chip on the Arduino Nano that supplies 3.3V.  It looks like the 3.3V pin can supply 50mA.
- It doesn't matter if traces are routed under parts for this board.
- We should not need to specify board thickness in the project's Layer Stack Manager.  It sounds like board thickness is specified separately when ordering the board.
- A 9V battery typically gets up to 500 mAh, which means it wouldn't last very long if we're drawing 500mA at once.  However, if we aren't using all the LEDs at the same time or at maximum brightness it would probably last longer.  Most of what I read suggested drawing less than 100mA, but it sounded like this is just a suggestion to get a longer battery life.  [Here](http://www.techlib.com/reference/batteries.html) is a table I found.
- Usually the buttons will take current when they are pressed if they use a pull up architecture.  Other than a brief transient when the switch is changed, the switches usually don't take any current that is worth keeping track of.

#Board Design questions:
- The LCD instructions say not to connect 5V directly to the backlight terminal.  The part we have probably has a series resistor to account for that, but I read that the backlight needs 3.2V so I wonder if there is a way to power it with the 3.3V pin?  Just a thought if that could help us move some of the current off of the 5V pin.  Stephanie measured the LCD currents and sent me this response: "Measuring the backlight, it was about 19 mA and .6 mA (but that one is with the 1k resistor so...). In any case, I don't know why it is so low, but that is what the multimeter says."  If it really is that low that will help with power consumption as well.
- Is there a better option for RGB LEDs that uses less current?
