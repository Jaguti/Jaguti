/*
 * =====================================================================================
 *
 *       Filename:  element.cpp
 *
 *    Description:  Source file for Jaguti's elements
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */

#include "element.h"

/* The Element constructor */
Element::Element(int type, int x, int y)
{
	/*switch(type)
	{
		case 0:
			debug("Flame!");
			surf = loadImage("./concept-Art/flamepixel.png");
			break;
		case 1:
			debug("Water!");
			surf = loadImage("./concept-Art/waterpixel.png");
			break;
		case 2:
			debug("Gunpowder!");
			surf = loadImage("./concept-Art/gunpowderpixel.png");
			break;
	}*/
}

Element::Draw(const char * filename, int x, int y)
{
	applySurface(x, y, surf, window);       /* apply the pixel to the window */
}
