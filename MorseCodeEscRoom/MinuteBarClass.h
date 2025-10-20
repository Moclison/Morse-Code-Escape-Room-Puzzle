#pragma once
#include "Arduino.h"

class MinuteBarClass
{
  private:
    static const int ledAmount = 6;
    static const int ledList[ledAmount];


  public:
    static int currentLed;
    static constexpr int ledListLength = sizeof(ledList) / sizeof(ledList[0]) - 1;

    void ledOff();
    void on(int brightness);

};
