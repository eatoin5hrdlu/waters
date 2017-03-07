#include "params.h"

void setup()
{
	Serial.begin(9600);
	delay(1000);
	Serial.println("EXCITE\tFlUOR");
	analogReference(INTERNAL);
}

void loop()
{
	Serial.print(analogRead(EXCITE));
	Serial.print("\t");
	Serial.println(analogRead(FLUOR));
	delay(100);
}