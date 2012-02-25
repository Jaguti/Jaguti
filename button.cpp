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
 *         Author:  YOUR NAME (), 
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
