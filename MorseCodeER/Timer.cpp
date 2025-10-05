#include "Timer.h"

unsigned long Timer::reset()
{
  return programStart = millis();
}
bool Timer::millisCounter(int wantedMilliseconds)
{
  return (millis() - programStart >= oneMillisecond * wantedMilliseconds);
}
bool Timer::secCounter(int wantedSeconds)
{
  return (millis() - programStart >= oneSecond * wantedSeconds);
}

bool Timer::minCounter(int wantedMinutes)
{
  return (millis() -programStart >= wantedMinutes * oneMinute);
}

bool Timer::hourCounter(int wantedHours)
{
  return (millis() - programStart >= wantedHours * oneHour);
}