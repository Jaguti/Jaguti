/*
 * =====================================================================================
 *
 *       Filename:  element.cpp
 *
 *    Description:  Source file for Jaguti's elements
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */

#include "element.h"
#include <SDL/SDL.h>


void Element::Draw(GLfloat x, GLfloat y)
{
	in_use = 1;
	
	switch(type)
	{
		case WATER:
			glColor3f(0.0, 0.0, 1.0);
			break;
	}
	glRectf(x, y, x+5.0, y+5.0);
	glColor3f(1.0, 1.0, 1.0);
	
	glFlush();
	SDL_GL_SwapBuffers();
	
	pos.x = x;
	pos.y = y;
}
