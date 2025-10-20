#pragma once
#include "Arduino.h"

/** 
  How morse code works:
  morse code contains two characters a dot and a dash.
  
  one dot lasts one unit, a unit can represent any length of time

  one dash is three units, three times the specified time of one unit

  a short space is one unit, a short space is used between every character, a dot and dash
  it can not be used before or after a different space

  a medium space is three units, it is used between every morse code letter

  a word space is seven units, it is used between every morse code word.

*/



class MorseCodeClass
{
  private:
    struct MorseCodeSet
    {
      String crow = "-|.|-|. .|-|. -|-|- .|-|-/"; // "-" is a dash, "." is a dot, "|" is a short space, " ", a medium space, "a word space"

      String oneeqb = ".|-|-|-|- . -|-|.|- -|.|.|./";

      String b2rt = "-|.|.|. .|.|-|-|- .|-|. -/";

      String nineghj = "-|-|-|-|. -|-|. .|.|.|. .|-|-|-/";

      String lms7 =  ".|-|.|. -|- .|.|. -|-|.|.|./";
    };
    MorseCodeSet MorseCodeString;

    static constexpr long oneUnit = 500; //milliseconds
    static constexpr long threeUnits = oneUnit * 3;
    static constexpr long sevenUnits = oneUnit * 7;
    
    bool isProcessing = false; //find out why these three varuable need to be in the header file
    unsigned long previousTime;
    long currentDuration;
    int brightness;

    const int morseCodeLed = 13;
    void dot(int morseCodeLed, long oneUnit);
    void shortSpace(int morseCodeLed, long oneUnit);
    void dash(int morseCodeLed, long threeUnits);
    void mediumSpace(int morseCodeLed, long threeUnits);
    void wordSpace(int morseCodeLed, long sevenUnits);

  public:
    int static randomNumber(int min, int max);
    String morseCodeStrings(int randomNum);


    void morseCodeReader(String morseString);
};
