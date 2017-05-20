//AnalogSwitches Library
//Can handle multiple banks of voltage divider sets of switches
//Each switch will return a different ID, based on it's number in the bank and the bank's index
//
//Jacques Bellavance
//19/05/2017
//GNU GENERAL PUBLIC LICENSE
//Version 3, 29 June 2007


#ifndef AnalogSwitches_h
#define AnalogSitches_h

#include "Arduino.h"

class AnalogSwitches {
  public:
    AnalogSwitches(int pinCount);                                 //Constructor
    void addSwitches(int pinId, int pin, int count, int index);   //Add a bank of switches
    int getIndex();                                               //Read all banks
      
  private:
		int pressed();             //Method to get the switch number in the bank
		int MYpinCount;            //The number of banks
    int MYreadCount = 5;       //The number of times that a pin is read for debouncing
    int currentBank = 0;       //The bank that holds the current switch 
    struct analogPin {         //Information for each bank:
      int pin;                   //Tha Arduino Anolog pin number
      int count;                 //The number of switches in that bank
      int index;                 //An index to add to the switch number
    };
    analogPin *analogPins;     //An array to store each bank's information
};

#endif;
