#include "SevSeg.h"
SevSeg sevseg; 

void setup() 
{
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {8, 9, 10, 11, 12, 13, 14, 15};
  sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
  sevseg.setBrightness(90);
}

void loop()
 {
  static unsigned long timer = millis();
  static int minute = 59;
  static int hour = 23;
  if(millic()>=timer)
  {
    timer += 10;

    if(++minute >= 60)
    {
      minute=0;
      if(++minute >=24)
      hour = 0;
    }
    sevseg.setNumber(hour*100+minute,3);
  }
  sevseg.refreshDisplay();
}


