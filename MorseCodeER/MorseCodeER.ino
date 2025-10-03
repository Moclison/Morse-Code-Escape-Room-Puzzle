
/* 
AUTHOR: LOUIS MEEVERS-SCHOLTE
DATE: TBD
RESOURCES: https://copilot.microsoft.com/, https://docs.arduino.cc/programming/
COMMENTS: Need to make class that plays morse code, 
          and give the timer led functions their own class as well.
          Set up method is outdated. declare each light as OUTPUT and high
          with for loop, change what led is what.
*/






#include "Timer.h"

Timer timer;

int const ledDash = 4;
int const ledDot = 5;
int const ledComplete = 3;
int const ledMin1 = 8;
int const ledMin2 = 9;
int const ledMin3 = 10;
int const ledMin4 = 11;
int const ledMin5 = 12;
int const ledMin6 = 13;

int minute = 0;

unsigned long startProgram = timer.reset();

void timerLeds() 
{
  int ledMins[] = {ledMin1, ledMin2, ledMin3, ledMin4, ledMin5, ledMin6,};
  int maximumMin = 5;
  if (minute <= maximumMin){
    digitalWrite(ledMins[minute], LOW);
    minute++;
  }
}

String morseCodeStrings()
{
  int stringNumber = random(1, 7);
  

  switch(stringNumber){
    case 1:
      return "-.-. .-. --- .--";
      break;
    case 2:
      return ".---- . --.- -...";
      break;
    case 3:
      return "-... ..--- .-. -";
      break;
    case 4:
      return "----. --. .... .---";
      break;
    case 5:
      return "-- -.-. ----- .--.";
      break;
    case 6:
      return ".-.. -- ... --...";
      break;
  }
}


void setup() 
{
  
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  
  //This is temp turns on led and sets its mode for the morse code led and the complete led.
  pinMode(ledComplete, OUTPUT);
  digitalWrite(ledComplete, LOW);
  pinMode(ledDash, OUTPUT);
  pinMode(ledDot, OUTPUT);

  //this turns on all timer leds
  pinMode(ledMin1, OUTPUT);
  digitalWrite(ledMin1, HIGH);
  pinMode(ledMin2, OUTPUT);
  digitalWrite(ledMin2, HIGH);
  pinMode(ledMin3, OUTPUT);
  digitalWrite(ledMin3, HIGH);
  pinMode(ledMin4, OUTPUT);
  digitalWrite(ledMin4, HIGH);
  pinMode(ledMin5, OUTPUT);
  digitalWrite(ledMin5, HIGH);
  pinMode(ledMin6, OUTPUT);
  digitalWrite(ledMin6, HIGH);



  
  
}

void loop() 
{
  if (timer.minCounter(1)){ //if one minute goes by call timerleds and reset timer
    timerLeds();
    timer.reset();
  }



}
