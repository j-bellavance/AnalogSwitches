#ifndef AnalogSwitches_h
#define AnalogSitches_h

#include "Arduino.h"

class AnalogSwitches {
  public:
    AnalogSwitches(int pinCount);
    void addSwitches(int pinId, int pin, int count, int index);
    int pressed();
    int getIndex();
      
  private:
    int MYpinCount;
    int MYreadCount = 5;
    int currentSwitch = 0;
    struct analogPin {
      int pin;
      int count;
      int index;
    };
    analogPin *analogPins;
};

#endif;
