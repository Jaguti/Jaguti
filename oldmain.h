/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  Jaguti's main header file
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */
#ifndef MAIN_H
#define MAIN_H

#include "button.h"
#include <stdlib.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SOIL.h>
#include "element.h"

#define debug(...) puts(__VA_ARGS__) /* Define debug(..) as a macro with parameters which are passed to puts */
 
#define	WINDOW_HEIGHT 600			/* The window's height */
#define	WINDOW_WIDTH 1000			/* The window's width */
#define	WINDOW_BPP 32	  		/* The window's Bits Per Pixel */

#define ELEMENT_COUNT 1 		/* The amount of elements featured in the game */

/* 
typedef struct
{
	SDL_Surface *surf;
} menu;

menu WINDOW[4];
*/
// Declare a bool for quit

namespace Jaguti
{
	extern bool exiting;
	extern bool dolan;
	
	//extern Mix_Music *song;
	
	// Declare the surfaces
	extern SDL_Surface* window;
	
	// Declare the buttons
	extern Button playButton;
	extern Button optionsButton;
	extern Button quitButton;
	
	// Declare the event
	extern SDL_Event event;
	
	// Declare functions
	int drawScreen();       /* Draw the window */
	void cleanUp();
	int drawScene();
	/* extern void checkMouseOver();
	extern void checkMouseUp();
	extern void checkMouseDown();
	extern void checkKeyUp();
	extern void checkKeyDown();
	*/
	
	GLint background[4];
	extern const GLint elementButtonCount;
	
	
	class RenderClass
	{
	public:
		static void Initialise();
		static void LoadAll();
	};
}

#endif
