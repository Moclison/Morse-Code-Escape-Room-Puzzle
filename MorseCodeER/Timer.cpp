#include "Timer.h"

unsigned long Timer::reset()
{
  return programStart = millis();
}

bool Timer::millisCounter(float wantedMilliseconds)
{
  return (millis() - programStart >= oneMillisecond * wantedMilliseconds);
}

bool Timer::secCounter(float wantedSeconds)
{
  return (millis() - programStart >= oneSecond * wantedSeconds);
}

bool Timer::minCounter(float wantedMinutes)
{
  return (millis() -programStart >= wantedMinutes * oneMinute);
}

bool Timer::hourCounter(float wantedHours)
{
  return (millis() - programStart >= wantedHours * oneHour);
}