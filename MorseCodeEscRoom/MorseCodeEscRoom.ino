
/* 
AUTHOR: LOUIS MEEVERS-SCHOLTE
DATE: Oct. 19 2025 12:30AM
RESOURCES: https://copilot.microsoft.com/, https://docs.arduino.cc/programming/
COMMENTS: 
          Then see if you can make red siren lights.
          Then make it so the user can enter an answer and the light can turn green if correct.
          ::FINISH LINE::
*/
#include "TimerClass.h"
#include "MinuteBarClass.h"
#include "MorseCodeClass.h"

TimerClass Timer;
MinuteBarClass Minutebar;
MorseCodeClass Morsecode;

String randomStr; //this lets the string stay random, since analog is not random unless in setup or loop functions.

void setup() 
{
  // these numbers represesnt the amount of morsecode translation there are
  int const static min = 1; 
  int const static max = 6; //there are not six strings, the bound number is not inclusive. so there are 5.

  Serial.begin(9600);
  
  int randomNumber = Morsecode.randomNumber(min, max); //max is inclonclusive

  randomStr = Morsecode.morseCodeStrings(randomNumber); //go to MorseCode.cpp to see how this works
  
  Minutebar.on(); //go to MinuteBathis turns on all timer leds r.cpp to see how this works.
}

void loop() 
{

  if (Timer.minCounter(1)){ //if one minute goes by call timerleds and reset timer
    Minutebar.ledOff(); //this turns off the current led.
    Timer.reset(); //this changes the start of the program to when ever this statement is called.
  }


  if (Minutebar.currentLed <= Minutebar.ledListLength) 
  {
    Morsecode.morseCodeReader(randomStr); //go to MorseCode.cpp to see how MorseCode.morseCodeReader works.
  }

  /**
   loop summary:
   currentLed = 0 and ledListLength = 5 (the length is technically six but we subtract one)
   currentLed adds 1 to its value in MinuteBar.ledOff.
   currentLed also represents in index in a set length of 6 (minus one) with indexes 0 - 5.

   lets say currentLed is Led.Five which is index four, currentLed will equal four.
   one minute when buy so Led.Five at index four is turned off.
   currentLed is now 5 and index 5 is Led.Six
   one minute goes buy and Led.Six at index 5 is turned off.
   currentLed is now six, and leds will stop turning off because it checks if current led is <= to 5.
   which also prevents an indec error.

   */

  
}
