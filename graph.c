#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setting.h"
#include "graph.h"
#include "screen.h"

void draw(void)
{
	int i;
	gotoxy(23*RES, 1);
	setColor(WHITE);
	printf("Channel");
	for(i=0; i<6*RES-RES+1; i++)
	{
		gotoxy(21*RES-i*4, 1);
		printf("%2d dBm", -80+i*16/RES);
	}
	for(i=0; i<23*RES-RES+1; i++)
	{
		gotoxy(23*RES-i, 8+RES);
		printf("|");
		gotoxy(23*RES-i, 8+71*RES);
		printf("|");
	}
	for(i=0; i<13; i++)
	{
		gotoxy(23*RES, 9+(11+i*4)*RES);
		printf("%-2d", i+1);
		printf("\n");
	}
}

void drawSignal(int channel, int level, char essid[], int color)
{
	int i, j;
	int len = strlen(essid);
	setColor(color);
	for(i=0; i<(level+88)/4*RES; i++)
	{
		gotoxy(23*RES-1-i, 9+(2+(channel-1)*4)*RES);
		printf("*");
		gotoxy(23*RES-1-i, 9+(20+(channel-1)*4)*RES);
		printf("*");
	}
	gotoxy(23*RES-i, 10+(2+(channel-1)*4)*RES);
	for(j=0; j<18*RES; j++)
	{
		printf("*");
	}
	gotoxy(23*RES-1-i, 9+(2+(channel-1)*4)*RES+(19*RES-RES+1-len)/2);
	printf("%s", essid);
}
