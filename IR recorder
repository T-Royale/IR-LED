// You need to install the IRremote library before starting //
#include <IRremote.hpp>

const int receptorPin = A3;
IRrecv receptor(receptorPin);
decode_results resultados;

void setup() {
  Serial.begin(9600);
  receptor.enableIRIn();
}

void loop() {
  if (receptor.decode(&resultados)) {
    Serial.println(resultados.value, HEX);
    receptor.resume();
  }
}
