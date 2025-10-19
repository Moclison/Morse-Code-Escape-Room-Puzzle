#pragma once
#include "Arduino.h"

class MinuteBarClass
{
  private:
    struct LedSet
    {
      static const int One = 8;
      static const int Two = 9;
      static const int Three = 10;
      static const int Four = 11;
      static const int Five = 12;
      static const int Six = 13;
    };
    static LedSet Led;
    
  public:
    static int currentLed;

    static const int ledAmount = 6;
    static const int ledList[ledAmount];
    static constexpr int ledListLength = sizeof(ledList) / sizeof(ledList[0]) - 1;

    void ledOff();
    void on();

};
