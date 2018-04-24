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
	char	str1[100], essid[100];	// ESSID
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
	for(i=0; i<MAX && input!=EOF; i++)
	{
		color=i%6+31;	// Set color value for networks
	/*
		Data format:
		----------------------------------
		Channel:1
		Frequency:2.412 Ghz (Channel 1)
		Quality=70/70 Signal level=-38 dBm
		ESSID:"Gia Dinh Vui Ve"
		----------------------------------
	*/
		input = fscanf(fp, "%*[^0123456789]%d", &channel);
		fscanf(fp, "%*[^0123456789]%lf", &frequency);
		fscanf(fp, "%*s%*s%*s%*[^0123456789]%d", &quality);
		fscanf(fp, "%*[^-]%d", &level);
		fscanf(fp, "%[^\"]\"%[^\"]", str1, essid);
#ifdef DEBUG
		// Print out information in text form
		if(input!=EOF)
		{
			printSignal(channel, frequency, quality, level, essid, color);
		}
	}
#else
		if(level>-80 && input!=EOF)		// Filter weak signal with level below -80 dBm
		{
		// Draw graph according to information
		drawSignal(channel, level, essid, color);
		}
	}
	draw();		// Draw the plot
#endif
	fclose(fp);
}
