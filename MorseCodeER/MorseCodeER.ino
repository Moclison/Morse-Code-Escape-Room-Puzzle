
/* 
AUTHOR: LOUIS MEEVERS-SCHOLTE
DATE: TBD
RESOURCES: https://copilot.microsoft.com/, https://docs.arduino.cc/programming/
COMMENTS: GREAT NEWS you have proven that you can make a timer and a morsecode blinker with one Arduino.
          That means you made a non-blocking for loop that only iterates when a function is completed.
          What you should do tommorrow, finish every function and debug, then change the led to 13, 
          then make the off fuction.
          Then see if you can make red siren lights.
          Then make it so the user can enter an answer and the light can turn green if correct.
          ::FINISH LINE::
*/
#include "Timer.h"
#include "MinuteBar.h"
#include "MorseCode.h"

Timer timer;
MinuteBar minutebar;
MorseCode morsecode;

int const min = 1;
int const max = 6;


void setup() 
{
  Serial.begin(9600);
  
  //This is temp turns on led and sets its mode for the morse code led and the complete led.
  pinMode(morsecode.morseCodeLed, OUTPUT);
  digitalWrite(morsecode.morseCodeLed, LOW);

  Serial.print(morsecode.morseCodeStrings(morsecode.randomNumber(min, max)));

  //this turns on all timer leds
  minutebar.on();
}

void loop() 
{
  if (timer.minCounter(1)){ //if one minute goes by call timerleds and reset timer
    minutebar.startTimer();
    timer.reset();
  }

  morsecode.morseCodeReader(morsecode.morseCodeStrings(morsecode.randomNumber(min, max)));

  

 
  
}
