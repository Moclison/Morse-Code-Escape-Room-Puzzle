#include "MinuteBarClass.h"
long currentDuration;

const int MinuteBarClass::ledList[6] = {Led.One, Led.Two, Led.Three, Led.Four, Led.Five, Led.Six};
int MinuteBarClass::currentLed = 0;

void MinuteBarClass::ledOff() 
{

  if (currentLed <= ledListLength)
  {
    digitalWrite(ledList[currentLed], LOW); //turns off the led that var currentLed corresponds to as an index.
    currentLed++; //then it adds 1 to its value
  }
}

void MinuteBarClass::on() //turns on every led in list, each led in the list is equal to a pin.
{
  for (int led : ledList)
  {
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
  }
}
