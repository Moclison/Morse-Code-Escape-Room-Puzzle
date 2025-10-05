
/* 
AUTHOR: LOUIS MEEVERS-SCHOLTE
DATE: TBD
RESOURCES: https://copilot.microsoft.com/, https://docs.arduino.cc/programming/
COMMENTS: Need to make class that plays morse code.
*/
#include "Timer.h"
#include "MinuteBar.h"

Timer timer;
MinuteBar minutebar;

int const ledComplete = 3;


void setup() 
{
  Serial.begin(9600);
  
  //This is temp turns on led and sets its mode for the morse code led and the complete led.
  pinMode(ledComplete, OUTPUT);
  digitalWrite(ledComplete, LOW);

  //this turns on all timer leds
  minutebar.on();
}

void loop() 
{
  if (timer.secCounter(3)){ //if one minute goes by call timerleds and reset timer
    minutebar.startTimer();
    timer.reset();
  }
  
}
