#ifndef MINUTE_BAR_H
#define MINUTE_BAR_H

#include "Arduino.h"


class MinuteBar 
{
  private:
    

    struct LedMinSet
    {
      static const int One = 8;
      static const int Two = 9;
      static const int Three = 10;
      static const int Four = 11;
      static const int Five = 12;
      static const int Six = 13;
    };
  
    static LedMinSet LedMin;

    static const int maximumMin;

    static const int ledMins[6];
    
  public:
    static int currentMinute;

    void startTimer();
    void on();
    void off();
};



#endif 