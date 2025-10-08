#include "MorseCode.h"
#include "Timer.h"

Timer MorseTimer;
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
  int randomNum = random(min, max);

  return randomNum;
}



String MorseCode::morseCodeStrings(int randomNum)
{
  switch(randomNum){
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


void MorseCode::dot(int morseCodeLed, long oneUnit)
{ 
  digitalWrite(morseCodeLed, HIGH);
  if (MorseTimer.millisCounter(oneUnit))
  {
    MorseTimer.reset();
  }
}

void MorseCode::shortSpace(int morseCodeLed, long oneUnit)
{
  digitalWrite(morseCodeLed, LOW);
  if (MorseTimer.millisCounter(oneUnit))
  {
    MorseTimer.reset();
  }
}

void MorseCode::dash(int morseCodeLed, long threeUnits)
{
  if (MorseTimer.millisCounter(threeUnits))
  {
    digitalWrite(morseCodeLed, HIGH);
  }
  if (MorseTimer.millisCounter(threeUnits * 2))
  {
    digitalWrite(morseCodeLed, LOW);
    MorseTimer.reset();
  }
  
}

void MorseCode::mediumSpace(int morseCodeLed, long threeUnits)
{

}

void MorseCode::wordSpace(int morseCodeLed, long sevenUnits)
{
  
}

void MorseCode::morseCodeReader(const String randomStr)
{
  for (int static character = 0; character <= randomStr.length();) 
  {
    if (!isSpace(randomStr[character]))
    {
      dash(morseCodeLed, threeUnits);
      
      break;
    }
    if (isSpace(randomStr[character]))
    {
      Serial.print("space");
      shortSpace(morseCodeLed, oneUnit);
      break;
    }
  }

}

void MorseCode::off(int morseCodeLed)
{

}