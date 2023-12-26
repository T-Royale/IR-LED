//This is an extra file you can use if you want to make your own ir sender remote, for this you'll need a few buttons, an KY-005 IR sender and, of course an arduino (i'd recomend using a NANO board)//
//(take a look at  the IRsender schematic file to make sure you connect everything propperly)//
#include <IRremote.hpp>

#define SenderPin 3
#define Button1 4
#define Button2 5
#define B1Signal 0xFC564A43
#define B2Signal 0x42AC9B26

IRsend sender;

void setup() {
  sender.begin(SenderPin);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
}

void loop() {
  if (digitalRead(Button1) == HIGH) {
    sender.sendNEC(B1Signal, 32); 
    delay(500);
  }
  else if (digitalRead(Button2) == HIGH) {
    sender.sendNEC(B2Signal, 32);
    delay(500);
  }
}
