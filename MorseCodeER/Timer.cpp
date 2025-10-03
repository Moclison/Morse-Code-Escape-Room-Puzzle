#include "Timer.h"


unsigned long Timer::reset()
{
  return programStart = millis();
}

unsigned long Timer::secCounter(int wantedSeconds)
{
  return (wantedSeconds * oneSecond);
}

unsigned long Timer::minCounter(int wantedMinutes)
{
  return (wantedMinutes * oneMinute);
}

unsigned long Timer::hourCounter(int wantedHours)
{
  return (wantedHours * oneHour);
}