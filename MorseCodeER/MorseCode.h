#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "Arduino.h"

class MorseCode
{
  private:
    const int morseCodeLed = 13;

    String morseCodeStrings(int stringNumber);

    void dot();
    void dash();
    
  public:
    int randomNumber(int min, int max);

    void morseCodeReader(String morseCode);
    void on();
    void off();
};
#endif