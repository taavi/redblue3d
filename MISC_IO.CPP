#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include "math3d.h"

void title_screen(void)
{
	char *title="Taavi's Math Project in 3-D -- March 1996";
	outtextxy((getmaxx()-textwidth(title))/2, 0, title);
	line(0,9,getmaxx(),9);
	press_any_key();
}

void write_menu(void)
{
	int x;
	x=set_menu_port(CLRPORT);
	if (x==1)
		exiterror("Problem setting menu viewport.");
	else if (x==2)
		exiterror("Problem clearing menu viewport.");
	else if (x!=NULL)
		exiterror("You've got something else screwy (menu), baby!");
	setcolor(EGA_WHITE);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy(0,2,"<D>raw shape   <C>lear screen   <Q>uit program");
	x=set_draw_port(NO_CLRPORT);
	if (x==1)
		exiterror("Problem setting draw viewport.");
	else if (x==2)
		exiterror("Problem clearing draw viewport.");
	else if (x!=NULL)
		exiterror("You've got something else screwy (draw), baby!");
}

int set_menu_port(int clrport)
{
	int x;
	setviewport(MENU_LEFT, MENU_TOP, MENU_RIGHT, MENU_BOTTOM, 0);
	x=graphresult();
	if (x!=0)
		return 1;
	if (clrport==CLRPORT)
		clearviewport();
	x=graphresult();
	if (x!=0)
		return 2;
	return 0;
}

int set_draw_port(int clrport)
{
	int x;
	setviewport(DRAW_LEFT, DRAW_TOP, DRAW_RIGHT, DRAW_BOTTOM, 0);
	x=graphresult();
	if (x!=0)
		return 1;
	if (clrport==CLRPORT)
		clearviewport();
	x=graphresult();
	if (x!=0)
		return 2;
	return 0;
}

void exiterror(char *errstr)
{
	fprintf(stderr,errstr);
	fprintf(stderr,"\nTerminating program.\n");
	exit(1);
}

int getxcoord()
{
	char *getx="Use the up and down arrow keys to adjust the x co-ordinate.";
	char dispval[4];
	int xloc=0;
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy((getmaxx()-textwidth(getx))/2,2,getx);
	setviewport(MENU_LEFT,MENU_TOP+10,MENU_RIGHT,MENU_BOTTOM,0);
	sprintf(dispval,"%3d",xloc);
	outtextxy(0,0,dispval);
	while(1)
	switch (getch())
	{
		case 0:
			switch (getch())
			{
				case _KB_DOWN:
					if (xloc==0)
						xloc=640;
					xloc--;
					break;
				case _KB_UP:
					if (xloc==639)
						xloc=-1;
					xloc++;
					break;
				default:
					break;
			}
			clearviewport();
			sprintf(dispval,"%3d",xloc);
			outtextxy(0,0,dispval);
			break;
		case 13:
			return xloc;
			break;
		default:
			break;
	}
}

int getycoord()
{
	char *gety="Use the up and down arrow keys to adjust the y co-ordinate.";
	char dispval[4];
	int yloc=0;
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy((getmaxx()-textwidth(gety))/2,2,gety);
	setviewport(MENU_LEFT,MENU_TOP+10,MENU_RIGHT,MENU_BOTTOM,0);
	sprintf(dispval,"%3d",yloc);
	outtextxy(0,0,dispval);
	while(1)
	switch (getch())
	{
		case 0:
			switch (getch())
			{
				case _KB_DOWN:
					if (yloc==0)
						yloc=450;
					yloc--;
					break;
				case _KB_UP:
					if (yloc==449)
						yloc=-1;
					yloc++;
					break;
				default:
					break;
			}
			clearviewport();
			sprintf(dispval,"%3d",yloc);
			outtextxy(0,0,dispval);
			break;
		case 13:
			return yloc;
			break;
		default:
			break;
	}
}
int getdepth()
{
	char *getd="Use the up and down arrow keys to adjust the depth in pixel offset.";
	char dispval[4];
	int three_dee=0;
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy((getmaxx()-textwidth(getd))/2,2,getd);
	setviewport(MENU_LEFT,MENU_TOP+10,MENU_RIGHT,MENU_BOTTOM,0);
	sprintf(dispval,"%3d",three_dee);
	outtextxy(0,0,dispval);
	while(1)
	switch (getch())
	{
		case 0:
			switch (getch())
			{
				case _KB_DOWN:
					if (three_dee==-49)
						three_dee=50;
					three_dee--;
					break;
				case _KB_UP:
					if (three_dee==49)
						three_dee=-50;
					three_dee++;
					break;
				default:
					break;
			}
			clearviewport();
			sprintf(dispval,"%3d",three_dee);
			outtextxy(0,0,dispval);
			break;
		case 13:
			return three_dee;
			break;
		default:
			break;
	}
}

/*
int getxcoord()
{
	int total=0;
	int x,y=0;
	char *enterx="Enter x location (000-609): ";
	char junk;
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy(0,2,enterx);
	junk=getch();
	while ((total>609) && (total <0))
	{
		total=0;
		for (x=3;x>0;x--,y++)
		{
			char temp, print[2];
			temp=getch();
			if (temp>='0' && temp<='9')
			{
				sprintf(print,"%1d",temp);
				outtextxy(textwidth(enterx)+y*textwidth(print),2,print);
				total+=(exp((double)x)*(temp-48));
			}
		}
	}
	return total;
}

int getycoord()
{
	int total=0;
	int x,y=0;
	char *entery="Enter y location (000-609): ";
	char junk;
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy(0,2,entery);
	junk=getch();
	while ((total>609) && (total <0))
	{
		total=0;
		for (x=3;x>0;x--,y++)
		{
			char temp, print[2];
			temp=getch();
			if (temp>='0' && temp<='9')
			{
				sprintf(print,"%1d",temp);
				outtextxy(textwidth(entery)+y*textwidth(print),2,print);
				total+=(exp((double)x)*(temp-48));
			}
		}
	}
	return total;
}

int getdepth()
{
	int total=0;
	int x,y=0;
	char junk;
	char *enterd="Enter a depth (horizontal pixel displacement, 000-200): ";
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy(0,2,enterd);
	junk=getch();
	while ((total>199) && (total <0))
	{
		total=0;
		for (x=3;x>0;x--,y++)
		{
			char temp, print[2];
			temp=getch();
			if (temp>='0' && temp<='9')
			{
				sprintf(print,"%1d",temp);
				outtextxy(textwidth(enterd)+y*textwidth(print),2,print);
				total+=(exp((double)x)*(temp-48));
			}
		}
	}
	return total;
}
*/
/* (c) Taavi Burns 1996 */
/*eof*/
