#include <graphics.h> //For thick and thin line def-ns
/*Here are the headers and defines for Taavi's Math 3-D project */

#define NUM_SHAPES 6
#define POINT 0
#define LINE 1
#define ELIPSE 2
#define ARC 3

#define COLOUR1 EGA_BLUE			//For red lens in left eye and red lens
#define COLOUR2 EGA_RED				//	in right eye.

/*
#define COLOUR1 EGA_WHITE			//For non-colour viewing (white only)
#define COLOUR2 EGA_WHITE
*/
#define EQ_TRIANGLE 0            //Define the values for each object
#define ISO_TRIANGLE 1
#define RIGHT_TRIANGLE 2
#define SQUARE 3
#define GOLDRECTANGLE 4
#define FACE 5
#define MENU_LEFT 0					//Define the co-ordinates for the menu port
#define MENU_TOP 460
#define MENU_RIGHT 639
#define MENU_BOTTOM 479
#define DRAW_LEFT 0					//Define the co-ordinates for the drawing port
#define DRAW_TOP 10
#define DRAW_RIGHT 639
#define DRAW_BOTTOM 459
#define CLRPORT 1                //Define clear viewport values
#define NO_CLRPORT 0
#define _KB_UP	72
#define _KB_DOWN 80
#define TRUE 1
#define FALSE 0
//#define LINEWIDTH THICK_WIDTH
#define LINEWIDTH NORM_WIDTH

void press_any_key(void);				// In kbdio.cpp
void title_screen(void);				// In misc_io.cpp
void init_graphics(void);				// In proj0001.cpp
void write_menu(void); 					// In misc_io.cpp
void exiterror(char *errstr);			// In misc_io.cpp
int set_menu_port(int clrport);		// In misc_io.cpp
int set_draw_port(int clrport);		// In misc_io.cpp
int scrollshapes(void);					// In shapes.cpp
int getxcoord(void);						// In misc_io.cpp
int getycoord(void);                // In misc_io.cpp
int getdepth(void);                 // In misc_io.cpp
int drawshape(int shapnum, int xloc, int yloc, signed int three_dee);
								// In shapes.cpp

/*
	OBJECT -- Structure used to define a shape.
		If the bitfield, type, is 0, draw the point (object[x].x1,object[x].y1).
		If the bitfield, type, is 1, start a line at (object[x].x1,
			object[x].y1) to (object[x].x2,object[x].y2).
		If the bitfield, type, is 2, draw an elipse at (object[x].x1,
			object[x].y1) with x aspect (object[x].x2) and
			y aspect (object[x].y2).
		If the bitfield, type, is 3, draw an arc with centre at (object[x].x1,
			object[x].y1) and starting angle of (object[x].x1) and ending angle of
			(object[x].y1) and radius from centre of (object[x].radius).
*/
struct object {
	int shap;
	int x1, y1;
	int x2, y2;
	int radius;
} ;

struct coords {
	int xloc;
	int yloc;
} ;

/* (c) Taavi Burns 1996 */
/*eof*/
