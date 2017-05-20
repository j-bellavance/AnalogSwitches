//AnalogSwitches Library
//Can handle multiple banks of voltage divider sets of switches
//Each switch will return a different ID, based on it's number in the bank and the bank's index
//
//Jacques Bellavance
//19/05/2017
//GNU GENERAL PUBLIC LICENSE
//Version 3, 29 June 2007

#include <Arduino.h>
#include "AnalogSwitches.h"

//AnalogSwitches=========================================================
//CONSTRUCTOR
//pinCount: the number of banks in the setup
//Allocate memory for each bank's information
//-----------------------------------------------------------------------
AnalogSwitches::AnalogSwitches(int pinCount) {
  MYpinCount = pinCount;
  analogPins = (analogPin*) calloc(MYpinCount+1, sizeof(analogPin));
}//AnalogSwitches--------------------------------------------------------

//addSwitches=================================================================
//pinID: a sequential number to store the bank's information in the array
//pin: The Arduino's analog pin to which the bank is tied
//count: the number of switches tied to the bank
//index: an integer to add to the switch's number for each bank
//----------------------------------------------------------------------------
void AnalogSwitches::addSwitches(int pinId, int pin, int count, int index) {
  analogPins[pinId].pin = pin;
  analogPins[pinId].count = count;
  analogPins[pinId].index = index;
  pinMode(pin, INPUT);
}//addSwitches----------------------------------------------------------------

//pressed======================================================================================================================
//returns the number (1..n) of the switch within the bank
//Changes the attribute currentBank when a switch is pressed
//-----------------------------------------------------------------------------------------------------------------------------
int AnalogSwitches::pressed() {
  for (int i = 1 ; i <= MYpinCount ; i++) {                        //For all banks
    int value = analogRead(analogPins[i].pin);                     //Read the bank's pin
    if (value < 1010) {                                            //If a switch is pressed
      for (int j = 1 ; j <= MYreadCount ; j++)                       //For MYreadCount times..
        value = int((value + analogRead(analogPins[i].pin)) / 2);      //Read the bank's pin and average with previous reads
      while (analogRead(analogPins[i].pin) < 1010) {}                //Wait for the switch to be released
      delay(10);                                                     //Wait to be sure that bouncing is finished
      currentBank = i;                                               //Update the bank number
      return int(value / (1024 / analogPins[i].count)) + 1;        //Calculate and return it's value (1..n)
    }
  }
  return 0;                                                        //If not, return 0
}//pressed----------------------------------------------------------------------------------------------------------------------

//getIndex========================================================================
//Read the value (1..n)
//If no switch pressed, return 0
//Else, Add the value of the switch to the bank's index (minus 1) an return
//--------------------------------------------------------------------------------
int AnalogSwitches::getIndex() {
	int value = pressed();
  if (value == 0) return 0;
  else            return value += analogPins[currentBank].index - 1;
}//getIndex-----------------------------------------------------------------------

