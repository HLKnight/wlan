/*
	Contains screen manipulation functions, such as clearScreen(), gotoxy(),
	setColor(), etc
*/

#include "screen.h"
#include <stdio.h>

/*
	Function definition of setColor()
	This function uses VT100 escape squence "\ESC[1;colorm" to change
	display foreground color.
	Input argument:
		int color:	color (BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN,
					WHITE)
	Return argument: none
*/
void setColor(int color)
{
	printf("%c[1;%dm", ESC, color);
	fflush(stdout);
}

/*
	Function definition of clearScreen()
	This function uses VT100 escape sequence "\ESC2J" to erase the total
	terminal screen.
	Input argument: none
	Return argument: none
*/
void clearScreen(void)
{
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*
	Function definition of gotoxy()
	This function uses VT100 escape squence "\ESC[row;colH" to set the cursor
	to the specific location of the terminal screen.
	Input argument:
		int row: row number (1 is top)
		int col: column number (1 is left)
	Return argument: none
*/
void gotoxy(int row, int col)
{
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/*
	Function defition of bar()
	This function displays a bar which has length depending on dB value at a
	specific column. Resolution (RES) of the bar can be changed in "screen.h"
	(the smaller RES is, the longer the bars are, prefertably RES = 4 or 5).
	Input argument:
		double dB: dB value calculated
		int col: column nubmer (1 is left)
	Return argument: none
*/
