#include "MinuteBar.h"

constexpr int MinuteBar::maximumMin = sizeof(ledMins) / sizeof(ledMins[0]) - 1;
const int MinuteBar::ledMins[6] = {LedMin.One, LedMin.Two, LedMin.Three, LedMin.Four, LedMin.Five, LedMin.Six};
int MinuteBar::currentMinute = 0;



void MinuteBar::startTimer() 
{
  if (currentMinute <= maximumMin)
  {
    digitalWrite(ledMins[currentMinute], LOW);
    currentMinute++;
  }
}

void MinuteBar::on()
{
  for (int led : ledMins)
  {
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
  }
}
