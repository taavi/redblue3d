//  Shape structures and shape definitions
//  All co-ordinates are relative to upper left of whole object (may be placed
//  anywhere on any screen)

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "math3d.h"
#define SIZEOBJ sizeof(object)
//math3d.h defines NUM_SHAPES, POINT, LINE, ELIPSE, ARC, COLOUR1, and COLOUR2



struct object eq_triangle[] = { 		//Instructions for making an equilateral triangle
	{LINE, 0, 90, 50, 0},
	{LINE, 50, 0, 100, 90},
	{LINE, 100, 90, 0, 90}
} ;

struct object iso_triangle[] = {		//Instructoins for making an isoceles triangle
	{LINE, 0, 100, 50, 0},
	{LINE, 50, 0, 100, 100},
	{LINE, 100, 100, 0, 100}
} ;

struct object right_triangle[] = {
	{LINE, 0, 0, 0, 100},
	{LINE, 0, 100, 100, 100},
	{LINE, 100, 100, 0, 0}
} ;

struct object square[] = {				//Instructions for making a square
	{LINE, 0, 0, 0, 100},
	{LINE, 0, 100, 100, 100},
	{LINE, 100, 100, 100, 0},
	{LINE, 100, 0, 0, 0}
} ;

struct object goldrectangle[] = {	//Instructions for making a golden rectangle
	{LINE, 0, 0, 151, 0},
	{LINE, 151, 0, 151, 90},
	{LINE, 151, 90, 0, 90},
	{LINE, 0, 90, 0, 0}
} ;

struct object face[] = {
	{ELIPSE, 50, 50, 50, 50},
	{ARC, 50, 50, 210, 330, 40},
	{POINT, 33, 25},
	{POINT, 66, 25}
} ;

struct {
	char *name;
	struct object *ptr_2_shape;
	int no_parts;
} objectlist[NUM_SHAPES] = {
	{"Equilateral Triangle", eq_triangle, (sizeof(eq_triangle)/SIZEOBJ)},
	{"Isoceles Triangle", iso_triangle, (sizeof(iso_triangle)/SIZEOBJ)},
	{"Right Isoceles Triangle", right_triangle, (sizeof(right_triangle)/SIZEOBJ)},
	{"Square", square, (sizeof(square)/SIZEOBJ)},
	{"Golden Rectangle", goldrectangle, (sizeof(goldrectangle)/SIZEOBJ)},
	{"Happy Face", face, (sizeof(face)/SIZEOBJ)}
} ;

int drawshape(int shapnum, int xloc, int yloc, signed int three_dee)
{
	int x;										//Junk variable
	struct object *objptr;

	if (three_dee<LINEWIDTH && three_dee>(-LINEWIDTH))
		three_dee=LINEWIDTH;			 //If three_dee equals zero, the image will be monocolour!
	set_draw_port(NO_CLRPORT);
	objptr=objectlist[shapnum].ptr_2_shape;
	x=0;
	while ( x<objectlist[shapnum].no_parts )
	{
		switch ( objptr -> shap )
		{
/*
	Place the first pixel at the relative location (all that pointer stuff) plus
		xloc by relative location plus yloc.  Place the second pixel at relative
		location plus xloc three_dee (defines how far apart the colours are, the
		larger the number, the farther in or out the image will appear) by
		relative location plus yloc plus one (to make it easier to display--one
		colour will not write over the other in most cases, making coding MUCH
		easier).
*/
			case POINT:
				putpixel(
					(objptr -> x1) + xloc,
					(objptr -> y1) + yloc, COLOUR1);
				putpixel(
					(objptr -> x1) + three_dee + xloc,
					(objptr -> y1) + yloc + LINEWIDTH, COLOUR2);
				break;

			case LINE:
				setcolor(COLOUR1);
				line(
					(objptr -> x1) + xloc,
					(objptr -> y1) + yloc,
					(objptr -> x2) + xloc,
					(objptr -> y2) + yloc);
				setcolor(COLOUR2);
				line(
					(objptr -> x1) + xloc + three_dee,
					(objptr -> y1) + yloc + LINEWIDTH,
					(objptr -> x2) + xloc + three_dee,
					(objptr -> y2) + yloc + LINEWIDTH);
				break;

			case ELIPSE:
				setcolor(COLOUR1);
				ellipse(
					objptr -> x1 + xloc,
					objptr -> y1 + yloc,
					0,
					360,
					objptr -> x2,
					objptr -> y2);
				setcolor(COLOUR2);
				ellipse(
					objptr -> x1 + xloc + three_dee,
					objptr -> y1 + yloc + LINEWIDTH,
					0,
					360,
					objptr -> x2,
					objptr -> y2);
				break;
			case ARC:
				setcolor(COLOUR1);
				arc(
					objptr -> x1 + xloc,
					objptr -> y1 + yloc,
					objptr -> x2,
					objptr -> y2,
					objptr -> radius);
				setcolor(COLOUR2);
				arc(
					objptr -> x1 + xloc + three_dee,
					objptr -> y1 + yloc + LINEWIDTH,
					objptr -> x2,
					objptr -> y2,
					objptr -> radius);
				break;
			default:
				return 1;
				break;
		}
		objptr++;
		x++;
	}
	return 0;
}

int scrollshapes(void)
{
	char *select="Select your shape by pressing the up and down arrow keys.";
	int shap=0;
	set_menu_port(CLRPORT);
	line(0, 0, MENU_RIGHT, 0);
	outtextxy((getmaxx()-textwidth(select))/2,2,select);
	setviewport(MENU_LEFT,MENU_TOP+10,MENU_RIGHT,MENU_BOTTOM,0);
	outtextxy(0,0,objectlist[shap].name);
	while (TRUE)
	switch (getch())
	{
		case 0:
			switch (getch())
			{
				case _KB_UP:
					if (shap==0)
						shap=NUM_SHAPES;
					shap--;
					break;
				case _KB_DOWN:
					if (shap==(NUM_SHAPES-1))
						shap=-1;
					shap++;
					break;
				default:
					break;
			}
			clearviewport();
			outtextxy(0,0,objectlist[shap].name);
			break;
		case 13:
			return shap;
			break;
		default:
			break;
	}
}

//Below is a set of declarations I _tried_ to use... :(

/*
	PT, LN, EL, AR -- Structures for x and y co-ordinates of common
		drawing components.
*/
/*struct pt {									//Structure for single point (x,y)
	int x;
	int y;
} ;

struct ln {									//Structure for line ((x1,y1)-(x2,y2))
	int x1;
	int y1;
	int x2;
	int y2;
} ;

struct el { 		                 	//Structure for elipse
	int x;									//x of centre
	int y;                           //y of centre
	int xaspect;                     //x radius from centre (aspect)
	int yaspect;                     //y radius from centre (aspect)
} ;

struct ar {									//Structure for a circular arc
	int x;									//x of centre
	int y;                           //y of centre
	int startang;                    //start angle in degrees (right is 0, go cc)
	int endang;								//end angle in degrees (right is 0, go cc)
	int radius;								//radius of arc from centre (always)
} ;
*/
/*struct object {
	int type		:2;						//point is 0, line is 1, elipse is 2, arc is 3
	union {
		struct pt point;
		struct ln line;
		struct el elipse;
		struct ar arch;
	} coords ;
} ;
*/
/*struct object {
	int type:2;								//Bit field for point (0), line (1), or elipse (2)
	struct point coordinate;
} ;
*/

/* (c) Taavi Burns 1996 */
/*eof*/