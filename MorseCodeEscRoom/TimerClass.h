#pragma once
#include "Arduino.h"

class TimerClass
{
  private:
    unsigned long programStart;

    static constexpr int oneMillisecond = 1;
    static constexpr unsigned long oneSecond = oneMillisecond * 1000;
    static constexpr unsigned long oneMinute = oneSecond * 60;
    static constexpr unsigned long oneHour = oneMinute * 60;

  public:

    unsigned long reset();

    bool millisCounter(float wantedMilliseconds);
    bool secCounter(float wantedSeconds);
    bool minCounter(float wantedMinutes);
    bool hourCounter(float wantedHours);

};
