//This sketch is to demonstrate how to use the AnalogSwitches Library
//Please refer to the Tutorial to see how to wire the switches
//Jacques Bellavance
//19/05/2017

#include <AnalogSwitches.h>

AnalogSwitches banks(3);

void setup() {
  banks.addSwitches(1, A0, 5, 100);
  banks.addSwitches(2, A1, 5, 200);
  banks.addSwitches(3, A2, 8, 300);
}

void action(int switchId) {
  switch (switchId) {
    case 100: { digitalWrite(3, HIGH); break; }
    case 101: { digitalWrite(4, HIGH); break; }
    case 102: { digitalWrite(5, HIGH); break; }
    case 103: { digitalWrite(6, HIGH); break; }
    case 104: { digitalWrite(7, HIGH); break; }
    case 200: { digitalWrite(3,  LOW); break; }
    case 201: { digitalWrite(4,  LOW); break; }
    case 202: { digitalWrite(5,  LOW); break; }
    case 203: { digitalWrite(6,  LOW); break; }
    case 204: { digitalWrite(7,  LOW); break; }
    case 300: { analogWrite(9,  128); break; }
    case 301: { analogWrite(9,  256); break; }
    case 302: { analogWrite(9,  384); break; }
    case 303: { analogWrite(9,  512); break; }
    case 304: { analogWrite(9,  640); break; }
    case 305: { analogWrite(9,  768); break; }
    case 306: { analogWrite(9,  896); break; }
    case 307: { analogWrite(9, 1023); break; }
  }
}

void loop() {
  int switchId = banks.getIndex();
  if (switchId > 0) action(switchId);
}
