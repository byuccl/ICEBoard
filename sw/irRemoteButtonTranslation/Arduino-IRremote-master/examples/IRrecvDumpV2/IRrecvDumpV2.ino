//------------------------------------------------------------------------------
// Include the IRremote library header
//
#include <IRremote.h>
#include <RemoteInput.h>
//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 11;
IRrecv irrecv(recvPin);
RemoteInput remote;
//+=============================================================================
// Configure the Arduino
//
void  setup ( )
{
  Serial.begin(9600);   // Status message will be sent to PC at 9600 baud
  //irrecv.enableIRIn();  // Start the receiver
}


//+=============================================================================
// The repeating section of the code
//
void  loop ( )
{
  remote.getRemoteInput();
}
