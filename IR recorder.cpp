#include <IRremote.h>
#define SIGNAL_PIN A3

int ButtonCount = 1;
String SignalID;
IRrecv receiver(SIGNAL_PIN);
String Message;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  if (receiver.decode()) {
    SignalID = receiver.decodedIRData.decodedRawData, HEX;
    Message = "Button" + String(ButtonCount) + "= " + String(SignalID);
    Serial.println (Message);
    ButtonCount ++;
    delay(500);
    receiver.resume();
  }
}
