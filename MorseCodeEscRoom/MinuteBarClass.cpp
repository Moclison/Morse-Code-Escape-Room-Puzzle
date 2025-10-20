#include "MinuteBarClass.h"
long currentDuration;

const int MinuteBarClass::ledList[6] = {8, 9, 10, 11, 12, 13};
int MinuteBarClass::currentLed = 0;

void MinuteBarClass::ledOff() 
{
  if (currentLed <= ledListLength)
  {
    digitalWrite(ledList[currentLed], LOW); //turns off the led that var currentLed corresponds to as an index.
    currentLed++; //then it adds 1 to its value
  }
}

void MinuteBarClass::on(int brightness) //turns on every led in list, each led in the list is equal to a pin.
{
  for (int led : ledList)
  {
    pinMode(led, OUTPUT);
    analogWrite(led, brightness);
  }
}
