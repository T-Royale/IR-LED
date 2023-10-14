// Check the connections file before starting//
// The IRremote library has to be added to the IDE//
// Not necessary if you use the web editor//

#include <IRremote.h>

bool message = false;
#define ReceptorPin A3
#define LedPin A1
IRrecv receiver(ReceptorPin);
#define Button1 0x //REPLACE WITH A BUTTON ID (ON)//
#define Button2 0x //REPLACE WITH A BUTTON ID (OFF)//
void setup() {
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT);
    receiver.enableIRIn();
}

void loop() {
  if (receiver.decode()) {
    unsigned long decodedValue = receiver.decodedIRData.decodedRawData;
    Serial.println(decodedValue, HEX);
    switch (decodedValue) {
      case Button1:
        message = true;
        break;
      case Button2: 
         message = false;
        break;
      default:
        Serial.println("Button not recognised");
        break;
        }
        receiver.resume();
        Serial.println("--------------------------------");
      }

    if (message == true) {
        analogWrite(LedPin, 255);
    } else if (message == false) {
        analogWrite(LedPin, 0);
    }
}
