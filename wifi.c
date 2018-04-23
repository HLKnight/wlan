#include <stdio.h>
#include "setting.h"
#include "wifi.h"
#include "screen.h"
#include "text.h"
#include "graph.h"

void process(char filename[])
{
	FILE	*fp;
	int		channel;	// Channel
	double	frequency;	// Frequency
	int		quality;	// Quality
	int		level;		// Signal level
	char	essid[100];	// ESSID
	int		i=0;		// Counting variable
	int		color;		// Color
	int		input;		// Input status

	fp = fopen(filename, "r");
	if(fp == NULL)		// If there is no file
	{
		printf("Failed to open %s", filename);
		return;
	}
	clearScreen();
	do
	{
		color=i%6+31;	// Set color value for networks
		i++;
	/*
		Data format:
		----------------------------------
		Channel:1
		Frequency:2.412 Ghz (Channel 1)
		Quality=70/70 Signal level=-38 dBm
		ESSID:"Gia Dinh Vui Ve"
		----------------------------------
	*/
		fscanf(fp, "%*[^0123456789]%d", &channel);
		fscanf(fp, "%*[^0123456789]%lf", &frequency);
		fscanf(fp, "%*s%*s%*s%*[^0123456789]%d", &quality);
		fscanf(fp, "%*[^-]%d", &level);
		input = fscanf(fp, "%[^\"]\"%[^\"]", essid);
#ifdef DEBUG
		// Print out information in text form
		printSignal(channel, frequency, quality, level, essid, color);
	}
	while(i<MAX && input!=EOF);
#else
		if(level>-80)		// Filter weak signal with level below -80 dBm
		{
		// Draw graph according to information
		drawSignal(channel, level, essid, color);
		}
	}
	while(i<MAX && input!=EOF);
	draw();		// Draw the plot
#endif
	fclose(fp);
}
