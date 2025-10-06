#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "Arduino.h"

class MorseCode
{
  private:
    static constexpr long oneUnit = 500; //milliseconds
    static constexpr long threeUnits = oneUnit * 3;
    static constexpr long sevenUnits = oneUnit * 7;

    String morseCodeStrings(int stringNumber);

    void dot(int morseCodeLed, long oneUnit);
    void shortSpace(int morseCodeLed, long oneUnit);
    void dash(int morseCodeLed, long threeUnits);
    void mediumSpace(int morseCodeLed, long threeUnits);
    void wordSpace(int morseCodeLed, long sevenUnits);

  public:
    const int morseCodeLed = 3;

    int randomNumber(int min, int max);

    void morseCodeReader(String morseCode);
    void off(int morseCodeLed);
};
#endif