/*
 * =====================================================================================
 *
 *       Filename:  element.h
 *
 *    Description:  Header file for Jaguti's elements
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */

#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
private:
	SDL_Surface* surf;
public:
	void Draw(std::string filename, int x, int y);
};

#endif
