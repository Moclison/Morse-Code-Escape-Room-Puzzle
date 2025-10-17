#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "Arduino.h"

class MorseCode
{
  private:
    struct MorseCodeSet
    {
      String crow = "-.-. .-. --- .--";
      String oneeqb = ".---- . --.- -...";
      String b2rt = "-... ..--- .-. -";
      String nineghj = "----. --. .... .---";
      String lms7 =  ".-.. -- ... --...";
    };

    MorseCodeSet MorseCodeString;

    static constexpr long oneUnit = 500; //milliseconds
    static constexpr long threeUnits = oneUnit * 3;
    static constexpr long sevenUnits = oneUnit * 7;

    unsigned long previousTime;
    bool isProcessing = false;
    long currentDuration;
    int currentChar = 0;

    void dot(int morseCodeLed, long oneUnit);
    void shortSpace(int morseCodeLed, long oneUnit);
    void dash(int morseCodeLed, long threeUnits);
    void mediumSpace(int morseCodeLed, long threeUnits);
    void wordSpace(int morseCodeLed, long sevenUnits);

  public:
    int static randomNumber(int min, int max);
    String morseCodeStrings(int randomNum);

    const int morseCodeLed = 13;


    void morseCodeReader(String randomStr);
    void off(int morseCodeLed);
};
#endif