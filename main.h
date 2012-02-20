/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  Jaguti's main header file
 *
 *        Version:  1.0
 *        Created:  02/20/2012 12:41:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Håkon Vågsether, Audun Måseidvåg
 *   Organization:  Jaguti
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <SDL/SDL.h>

#define	WINDOW_HEIGHT 480			/* The window's height */
#define	WINDOW_WIDTH 640			/* The window's width */
#define	WINDOW_BPP 32	  		/* The window's Bits Per Pixel */


// Declare the surfaces
SDL_Surface* window = NULL;

// Declare functions
int drawScreen();                               /* Draw the window */
