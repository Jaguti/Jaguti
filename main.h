/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  Jaguti's main header file
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_gfxPrimitives.h>

#define debug(...) puts(__VA_ARGS__) /* Define debug(..) as a macro with parameters which are passed to puts */
 
#define	WINDOW_HEIGHT 600			/* The window's height */
#define	WINDOW_WIDTH 1000			/* The window's width */
#define	WINDOW_BPP 32	  		/* The window's Bits Per Pixel */

// Declare a bool for quit
extern bool exiting;

extern Mix_Music *song;

// Declare the surfaces
extern SDL_Surface* window;
extern SDL_Surface* background;         /* Declare the background */

// Declare the buttons
//extern Button playButton;
//extern Button optionsButton;
//extern Button quitButton;

// Declare the event
extern SDL_Event event;

// Declare functions
extern int drawScreen();       /* Draw the window */
extern SDL_Surface *loadImage( std::string filename );
extern bool applySurface( int x, int y, SDL_Surface* src, SDL_Surface* dest );
extern void cleanExit();
/* extern void checkMouseOver();
extern void checkMouseUp();
extern void checkMouseDown();
extern void checkKeyUp();
extern void checkKeyDown();
*/

extern int randum;

#endif
