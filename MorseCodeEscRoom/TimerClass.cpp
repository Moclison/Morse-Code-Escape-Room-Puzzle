#include "TimerClass.h"

unsigned long TimerClass::reset()
{
  return programStart = millis();
}

bool TimerClass::millisCounter(float wantedMilliseconds)
{
  return (millis() - programStart >= oneMillisecond * wantedMilliseconds);
}

bool TimerClass::secCounter(float wantedSeconds)
{
  return (millis() - programStart >= oneSecond * wantedSeconds);
}

bool TimerClass::minCounter(float wantedMinutes)
{
  return (millis() - programStart >= wantedMinutes * oneMinute);
}

bool TimerClass::hourCounter(float wantedHours)
{
  return (millis() - programStart >= wantedHours * oneHour);
}