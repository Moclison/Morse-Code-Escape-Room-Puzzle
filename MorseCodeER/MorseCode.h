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

    static constexpr long oneUnit = 500; //milliseconds
    static constexpr long threeUnits = oneUnit * 3;
    static constexpr long sevenUnits = oneUnit * 7;

    void dot(int morseCodeLed, long oneUnit);
    void shortSpace(int morseCodeLed, long oneUnit);
    void dash(int morseCodeLed, long threeUnits);
    void mediumSpace(int morseCodeLed, long threeUnits);
    void wordSpace(int morseCodeLed, long sevenUnits);

  public:
    int static randomNumber(int min, int max);
    String static morseCodeStrings(int randomNum);
    

    const int morseCodeLed = 3;


    void morseCodeReader(String randomStr);
    void off(int morseCodeLed);
};
#endif