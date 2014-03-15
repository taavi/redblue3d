#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include "math3d.h"
void press_any_key()
{
	char *pstr="Press space to continue . . .";
	setcolor(EGA_WHITE);
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy((getmaxx()-textwidth(pstr))/2,2,pstr);
	while(getch()!=32);
	set_menu_port(CLRPORT);
	set_draw_port(NO_CLRPORT);
}
/* (c) Taavi Burns 1996 */
/*eof*/