#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setting.h"
#include "graph.h"
#include "screen.h"

/*
	Function definition of draw()
	This function prints out vertical signal level axis and horizontal channel
	axis.
	Input arguments: none
	Return arguments: none
*/
void draw(void)
{
	int i;
	setColor(WHITE);
	// Print out vertical signal level axis (dBm)
	for(i=0; i<6*RES-RES+1; i++)
	{
		gotoxy(21*RES-i*4, 1);
		printf("%2d dBm", -80+i*16/RES);
	}
	// Print out vertical lines to separate sections
#ifndef UNICODE
	for(i=0; i<23*RES-RES+1; i++)
	{
		gotoxy(23*RES-i, 8+RES);
		printf("|");
		gotoxy(23*RES-i, 8+71*RES);
		printf("|");
	}
#else
	for(i=0; i<23*RES-RES+1; i++)
	{
		gotoxy(23*RES-i, 8+RES);
		printf(FB);
		gotoxy(23*RES-i, 8+71*RES);
		printf(FB);
	}
#endif
	// Print out the horizontal channel axis
	gotoxy(23*RES, 1);
	printf("Channel");
	for(i=0; i<13; i++)
	{
		gotoxy(23*RES, 9+(11+i*4)*RES);
		printf("%-2d", i+1);	// print out channel from 1 to 13
		printf("\n");
	}
}
/*
	Function definition of drawSignal()
	This function draw a triangle shaped graph of each scanned network.
	Input arguments:
		int channel:	channel of the network
		int level:		signal level
		char essid[]:	ESSID or name of the WLAN
		int color:		display color
	Output arguments: none
*/
void drawSignal(int channel, int level, char essid[], int color)
{
	int i, j;	// count variables
	int len = strlen(essid);	// take the length of ESSID
	setColor(color);
	// Draw two vertical lines
#ifndef UNICODE
	for(i=0; i<(level+88)/4*RES; i++)
	{
		gotoxy(23*RES-1-i, 9+(2+(channel-1)*4)*RES);
		printf("*");
		gotoxy(23*RES-1-i, 9+(20+(channel-1)*4)*RES);
		printf("*");
	}
	gotoxy(23*RES-i, 10+(2+(channel-1)*4)*RES);
	// Draw the horizontal line
	for(j=0; j<18*RES; j++)
	{
		printf("*");
	}
#else
	for(i=0; i<(level+88)/4*RES; i++)
	{
		gotoxy(23*RES-1-i, 9+(2+(channel-1)*4)*RES);
		printf(FB);
		gotoxy(23*RES-1-i, 9+(20+(channel-1)*4)*RES);
		printf(FB);
	}
	gotoxy(23*RES-i, 10+(2+(channel-1)*4)*RES);
	// Draw the horizontal line
	for(j=0; j<18*RES-1; j++)
	{
		printf(UHB);
	}
#endif
	// Display ESSID with center align
	gotoxy(23*RES-1-i, 9+(2+(channel-1)*4)*RES+(19*RES-RES+1-len)/2);
	printf("%s", essid);
}
