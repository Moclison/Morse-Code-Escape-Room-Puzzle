#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"



class Timer 
{
  private:
    unsigned long programStart;


  public:
    static constexpr int oneMillisecond = 1;
    static constexpr unsigned long oneSecond = oneMillisecond * 1000;
    static constexpr unsigned long oneMinute = oneSecond * 60;
    static constexpr unsigned long oneHour = oneMinute * 60;
    
    unsigned long reset();

    bool millisCounter(float wantedMilliseconds);
    bool secCounter(float wantedSeconds);
    bool minCounter(float wantedMinutes);
    bool hourCounter(float wantedHours);

};


#endif 