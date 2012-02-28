/*
 * =====================================================================================
 *
 *       Filename:  button.cpp
 *
 *    Description:  .cpp file for Jaguti's buttons
 *
 *        Version:  1.0
 *        Created:  24. feb. 2012 kl. 01.48 +0100
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Håkon Vågsether, Audun Måseidvåg
 *   Organization:  
 *
 * =====================================================================================
 */
#include "button.h"
#include "main.h"

Button::Button()
{
}

void Button::Load(std::string filename)
{
	buttonSurface = loadImage(filename);
}

void Button::Draw(int x, int y, int w, int h)
{
	rect.x = (Sint16) x;
	rect.y = (Sint16) y;
	rect.w = (Sint16) w;
	rect.h = (Sint16) h;
	applySurface( x, y, buttonSurface, window );
}

void Button::MouseOver()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		std::cout << "Mouse is over " << "mkay" << std::endl;
	}

	
}

void Button::MouseUp()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		std::cout << "Mouse is up at " << "mkay" << std::endl;
	}
	
}

void Button::MouseDown()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		std::cout << "Mouse is down at " << "mkay" << std::endl;
	}	
}
