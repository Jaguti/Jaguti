/*
 * =====================================================================================
 *
 *       Filename:  element.h
 *
 *    Description:  Header file for Jaguti's elements
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <GL/glu.h>

enum elementType
{
	WATER,
	FIRE
};

struct position
{
	GLint x, y;
};

class Element
{
public:
	bool in_use;
	struct position pos;
	enum elementType type;
	void Draw(GLfloat x, GLfloat y);
};

extern Element lol;

#endif
