//Run it and open the serial monitor on the IDE to see the results//
#include <IRremote.h>
#define SIGNAL_PIN A3

int ButtonCount = 1;
unsigned long SignalID;
IRrecv receiver(SIGNAL_PIN);
String Message1;


void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  if (receiver.decode()) {
    SignalID = (receiver.decodedIRData.decodedRawData), HEX;
    Message1 = "Button" + String(ButtonCount) + " :";
    Serial.println (Message1);
    SignalID = receiver.decodedIRData.decodedRawData;
    Serial.println(SignalID, HEX);
    Serial.println("--------------------------------");
    ButtonCount ++;
    delay(500);
    receiver.resume();
  }
}
