#include <stdio.h>
#include "text.h"
#include "screen.h"

void printSignal(int channel, double frequency, int quality, int level, char essid[], int color)
{
	setColor(color);
	printf("Channel: %d\n", channel);
	printf("Frequency: %.3f GHz\n", frequency);
	printf("Quality: %d/70\n", quality);
	printf("Level: %d dBm\n", level);
	printf("ESSID: %s\n\n", essid);
}
