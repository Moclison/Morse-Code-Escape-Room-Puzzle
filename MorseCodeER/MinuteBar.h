#ifndef MINUTE_BAR_H
#define MINUTE_BAR_H

#include "Arduino.h"


class MinuteBar 
{
  private:
    static const int maximumMin;

    static const int ledMins[6];
    static const int ledMinOne = 8;
    static const int ledMinTwo = 9;
    static const int ledMinThree = 10;
    static const int ledMinFour = 11;
    static const int ledMinFive = 12;
    static const int ledMinSix = 13;
    
  public:
    static int currentMinute;

    void startTimer();
    void on();
    void off();
};



#endif 