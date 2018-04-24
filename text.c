#include <stdio.h>
#include "text.h"
#include "screen.h"

/*
	Function definition of printSignal
	This function prints out information of WLAN in text form.
	Input argument:
		int channel:		channel of the WLAN
		double frequency:	frquency
		int quality:		quality
		int level:			signal level
		char essid:			ESSID or name of the WLAN
		int color:			display color
	Return argument: none
*/
void printSignal(int channel, double frequency, int quality, int level, char essid[], int color)
{
	setColor(color);
	printf("Channel: %d\n", channel);
	printf("Frequency: %.3f GHz\n", frequency);
	printf("Quality: %d/70\n", quality);
	printf("Level: %d dBm\n", level);
	printf("ESSID: %s\n\n", essid);
}
