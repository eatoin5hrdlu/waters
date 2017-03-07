#include "params.h"

void setup()
{
	Serial.begin(9600);
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
	delay(10);
}

void loop()
{
static boolean once = false;

    if (once) {
        Serial.println("TIME\tEXCITE\tFlUOR");
	once = false;
    }
    show(analogRead(EXCITE), analogRead(FLUOR));
}