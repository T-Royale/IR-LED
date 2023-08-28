// Check the connections file before starting//
// The IRremote library has to be added to the IDE//
// Not necessary if you use the web editor//

#include <IRremote.hpp>

bool mensaje = false;
const int receptorPin = A3;
IRrecv receptor(receptorPin);
decode_results señal;
int boton1 = //replace with the signal of a button of your controller//
int boton2 = //replace with another button's signal//

void setup() {
    Serial.begin(9600);
    pinMode(A1, OUTPUT);
    receptor.enableIRIn();
}

void loop() {

  if (receptor.decode(&señal)) {
    if (señal == boton1) {
      mensaje = true;
    }
    else if (señal == boton2) {
     mensaje = false;
    }
  }

   if (mensaje == true){
    analogWrite(A1, 126);
  }
  else if(mensaje == false) {
    analogWrite(A1, 0);
  }
  receptor.resume();
}
