#include "MorseCode.h"
#include "Timer.h"

    struct MorseCodeSet
    {
      String crow = "-.-. .-. --- .--";
      String oneeqb = ".---- . --.- -...";
      String b2rt = "-... ..--- .-. -";
      String nineghj = "----. --. .... .---";
      String lms7 =  ".-.. -- ... --...";
    };

MorseCodeSet MorseCodes;

int MorseCode::randomNumber(int min, int max)
{
  randomSeed(analogRead(0));
  int stringNumber = random(min, max);

  return stringNumber;
}


String MorseCode::morseCodeStrings(int stringNumber)
{
  switch(stringNumber){
    case 1:
      return MorseCodes.crow;
      break;
    case 2:
      return MorseCodes.oneeqb;
      break;
    case 3:
      return MorseCodes.b2rt;
      break;
    case 4:
      return MorseCodes.nineghj;
      break;
    case 5:
      return MorseCodes.lms7;
      break;
  }
}

void MorseCode::dot()
{

}

void MorseCode::dash()
{

}

void MorseCode::morseCodeReader(String morseCode)
{

}

void MorseCode::on()
{

}

void MorseCode::off()
{

}