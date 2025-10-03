#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer {
  unsigned long programStart;

  unsigned long const oneSecond = 1000;
  unsigned long const oneMinute = oneSecond * 60;
  unsigned long const oneHour = oneMinute * 60;

  public:
    unsigned long reset();

    unsigned long secCounter(int wantedSeconds);
    unsigned long minCounter(int wantedMinutes);
    unsigned long hourCounter(int wantedHours);

};
#endif 