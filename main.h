/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  Jaguti's main header file
 *
 *        Version:  
 *        Created:  02/20/2012 12:41:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Håkon Vågsether, Audun Måseidvåg
 *   Organization:  Jaguti
 *
 * =====================================================================================
 */
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
 
#define	WINDOW_HEIGHT 600			/* The window's height */
#define	WINDOW_WIDTH 1000			/* The window's width */
#define	WINDOW_BPP 32	  		/* The window's Bits Per Pixel */

// Declare a bool for quit
extern bool exiting;

// Declare the surfaces
extern SDL_Surface* window;
extern SDL_Surface* background;         /* Declare the background */
 
//SDL_Surface* play = NULL;                       /* Declare the menu's play button*/
//SDL_Surface* options = NULL;                    /* Declare the menu's options button */
//SDL_Surface* quit = NULL;                       /* Declare the menu's quit button */

// Declare the buttons
//Button playButton;
//Button optionsButton;
//Button quitButton;

// Declare the event
extern SDL_Event event;

// Declare functions
extern int drawScreen();       /* Draw the window */
extern SDL_Surface *loadImage( std::string filename );
extern bool applySurface( int x, int y, SDL_Surface* src, SDL_Surface* dest );
extern void cleanExit();

#endif
