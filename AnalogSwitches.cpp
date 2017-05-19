#include <Arduino.h>
#include "AnalogSwitches.h"

AnalogSwitches::AnalogSwitches(int pinCount) {
  MYpinCount = pinCount;
  analogPins = (analogPin*) calloc(MYpinCount+1, sizeof(analogPin));
}

void AnalogSwitches::addSwitches(int pinId, int pin, int count, int index) {
  analogPins[pinId].pin = pin;
  analogPins[pinId].count = count;
  analogPins[pinId].index = index;
  pinMode(pin, INPUT);
}

int AnalogSwitches::pressed() {
  for (int i = 1 ; i <= MYpinCount ; i++) {
    int value = analogRead(analogPins[i].pin);
    if (value < 1010) {
      for (int j = 1 ; j <= MYreadCount ; j++) 
        value = int((value + analogRead(analogPins[i].pin)) / 2);
      while (analogRead(analogPins[i].pin) < 1010) {}
      delay(10);
      currentSwitch = i;
      value = int(value / (1024 / analogPins[i].count));
      return value + 1;
    }
  }
  return 0;  
}

int AnalogSwitches::getIndex() {
	int value = pressed();
  if (value == 0) return 0;
  else            return value += analogPins[currentSwitch].index - 1;
}

