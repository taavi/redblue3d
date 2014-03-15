#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "math3d.h"
void main()
{
	int go_again=TRUE;
	init_graphics();							//Start graphics session
	title_screen();							//Draw the title screen
	setlinestyle(SOLID_LINE, NULL, LINEWIDTH);
//	drawshape(RIGHT_TRIANGLE, 50,300,50);  //Demo various drawing objects
//	drawshape(ISO_TRIANGLE, 250,200,-50);
//	drawshape(GOLDRECTANGLE, 450,100, 0);
//	drawshape(EQ_TRIANGLE, 280,280,50);
//	drawshape(FACE, 450,150,25);
	write_menu();
	while (go_again)
	{
		switch (getch())
		{
			case 'q':							//Fall through
			case 'Q':
				go_again=FALSE;
				break;
			case 'c':							//Fall through
			case 'C':
				set_draw_port(CLRPORT);
				break;
			case 'd':							//Fall through
			case 'D':
				set_menu_port(CLRPORT);
				{
					int shap, xloc, yloc, three_dee;
					shap=scrollshapes();
					xloc=getxcoord();
					yloc=getycoord();
					three_dee=getdepth();
					drawshape(shap,xloc,yloc,three_dee);
				}
				write_menu();
				break;
			}
		}
	closegraph();								//End graphics session
}

void init_graphics()
{
	int vga=VGA, vgahi=VGAHI, errorcode;//Set graphics mode variables
													//640x480, 16 colour, 1 page
													//VGA and VGAHI defined in graphics.h

	registerbgidriver(EGAVGA_driver);  //register .obj bgi driver

	initgraph(&vga, &vgahi, "");			//Init graphics, use .obj BGI driver
	errorcode=graphresult();
	if(errorcode!=0)								//Check for success
	{
		fprintf(stderr,"\nProblem %d initialising the BGI driver.\n",errorcode);
		press_any_key();
		exit(1);
	}
}


/* (c) Taavi Burns 1996 */
/*eof*/
