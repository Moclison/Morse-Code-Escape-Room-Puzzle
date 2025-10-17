#include "MorseCode.h"
#include "Timer.h"

Timer MorseTimer;

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


void MorseCode::dot(int morseCodeLed, long oneUnit)
{ 
    digitalWrite(morseCodeLed, HIGH);
    currentDuration = oneUnit; // dot = 1 unit
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
  digitalWrite(morseCodeLed, HIGH);
  currentDuration = threeUnits;
  
}

void MorseCode::mediumSpace(int morseCodeLed, long threeUnits)
{
  digitalWrite(morseCodeLed, LOW);
  currentDuration = threeUnits;

}

void MorseCode::wordSpace(int morseCodeLed, long sevenUnits)
{
  digitalWrite(morseCodeLed, LOW);
  currentDuration = sevenUnits;
}

void MorseCode::morseCodeReader(String morseString)
{
  if (currentChar < morseString.length()) 
  {
    char symbol = morseString[currentChar];

    if (!isProcessing) 
    {
      if (symbol == '.') 
      {
        MorseCode::dot(morseCodeLed, oneUnit);

      } else if (symbol == '-') 
      {
        MorseCode::dash(morseCodeLed, threeUnits);// dash = 3 units

      } else if (symbol == ' ') 
      {
        MorseCode::mediumSpace(morseCodeLed, threeUnits);

      } else if (currentChar.equals()) {
        digitalWrite(morseCodeLed, LOW);
        currentDuration = sevenUnits; // space between words
      }

      previousTime = millis();
      isProcessing = true;
    } else {
      if (millis() - previousTime >= currentDuration) {
        Serial.print("Processing: ");
        Serial.println(symbol);
        digitalWrite(morseCodeLed, LOW); // turn off after duration
        isProcessing = false;
        currentChar++; // move to next character
        previousTime = millis(); // optional pause between characters
      }
    }
  }
  
}

void MorseCode::off(int morseCodeLed)
{

}