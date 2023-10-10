// You need to install the IRremote library before starting //
#include <IRremote.h>
// The signal pin on the receiver must be connected to the A3 pin //
#define SIGNAL_PIN A3 
IRrecv receiver(SIGNAL_PIN);

void setup() {
  Serial.begin(9600);
//enables ir data capture//
  receiver.enableIRIn();
}
//When the receiver detects a signal, it will be shown on the serial monitor in the IDE//
void loop() {
  if (receiver.decode()) {
    Serial.println(receiver.decodedIRData.decodedRawData, HEX);
    delay(1000);
  //Restart the receiver. This is very important to capture the next signal
    receiver.resume();
  }
}
