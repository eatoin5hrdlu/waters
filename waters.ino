#include "params.h"
extern volatile unsigned long timer0_millis;
boolean streaming = false;

void setMillis(unsigned long new_millis)
{
  uint8_t oldSREG = SREG;
  cli();
  timer0_millis = new_millis;
  SREG = oldSREG;
}

void setup()
{
	Serial.begin(9600);
	pinMode(START,OUTPUT);
	delay(1000);
	analogReference(INTERNAL);
	delay(100);
}

void show(int ex, int em)
{
	Serial.print(millis());
	Serial.print("\t");
	Serial.print(ex);
	Serial.print("\t");
	Serial.println(em);
	delay(30);
}
/*
 * 1) Print HEADING
 * 2) Send Program Start
 * 3) Stream data for programmed interval
 */

void startStream(void)
{
	Serial.println("\n\nTIME\tEXCITE\tEMISSION\n");
	digitalWrite(START,1);
	delay(300);
	digitalWrite(START,0);
	setMillis(0L);
	streaming = true;
}

void loop()
{
    if (streaming)
       show(analogRead(EXCITE), analogRead(FLUOR));
    else
	startStream();

    if (millis() > 180000L) streaming = false;
}