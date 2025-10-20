#include "MorseCodeClass.h"
#include "MinuteBarClass.h"

int MorseCodeClass::randomNumber(int min, int max)
{
  randomSeed(analogRead(0));
  return random(min, max);
}

String MorseCodeClass::morseCodeStrings(int randomNum)
{
  switch(randomNum){
    case 1:
      return MorseCodeString.crow;
      break;
    case 2:
      return MorseCodeString.oneeqb;
      break;
    case 3:
      return MorseCodeString.b2rt;
      break;
    case 4:
      return MorseCodeString.nineghj;
      break;
    case 5:
      return MorseCodeString.lms7;
      break;
  }
}


void MorseCodeClass::dot(int morseCodeLed, long oneUnit)
{ 
  analogWrite(morseCodeLed, 130);
  brightness = 130;
  currentDuration = oneUnit; // dot = 1 unit
}

void MorseCodeClass::shortSpace(int morseCodeLed, long oneUnit)
{
  digitalWrite(morseCodeLed, LOW);
  currentDuration = oneUnit;
}

void MorseCodeClass::dash(int morseCodeLed, long threeUnits)
{
  analogWrite(morseCodeLed, brightness);
  currentDuration = threeUnits;
}

void MorseCodeClass::mediumSpace(int morseCodeLed, long threeUnits)
{
  digitalWrite(morseCodeLed, LOW);
  currentDuration = threeUnits;
}

void MorseCodeClass::wordSpace(int morseCodeLed, long sevenUnits)
{
  digitalWrite(morseCodeLed, LOW);
  currentDuration = sevenUnits;
}

void MorseCodeClass::morseCodeReader(String morseString)
{
  int static currentChar = 0;

  int stringLength = morseString.length();

  if (currentChar < stringLength) 
  {
   
    char symbol = morseString[currentChar];
    char nextSymbol = morseString[currentChar + 1];

    if (!isProcessing) 
    {
      if (symbol == '.') 
      {
        dot(morseCodeLed, oneUnit);

      } else if (symbol == '-') 
      {
        dash(morseCodeLed, threeUnits);// dash = 3 units

      } else if (symbol == ' ') 
      {
        mediumSpace(morseCodeLed, threeUnits);

      } else if (symbol == '/') 
      {
        wordSpace(morseCodeLed, sevenUnits);
        currentChar = 0;

      } else if (symbol = '|')
      {
        shortSpace(morseCodeLed, oneUnit);

      }
      
      previousTime = millis();
      isProcessing = true;
    } else {
      if (millis() - previousTime >= currentDuration) {
        currentChar++; // move to next character
        previousTime = millis(); // optional pause between characters
        isProcessing = false;

      }
    }
  }
}
