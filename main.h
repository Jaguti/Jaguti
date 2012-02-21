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
#include <SDL/SDL_image.h>

#define	WINDOW_HEIGHT 600			/* The window's height */
#define	WINDOW_WIDTH 1000			/* The window's width */
#define	WINDOW_BPP 32	  		/* The window's Bits Per Pixel */


// Declare the surfaces
SDL_Surface* window = NULL;
SDL_Surface* background = NULL;         /* Declare the background */

// Declare functions
int drawScreen();       /* Draw the window */


// Define functions
SDL_Surface *loadImage( std::string filename )
{
	SDL_Surface* preImage = NULL;           /* The original image */
	SDL_Surface* postImage = NULL;          /* The optimized(?) image that SDL will use */
	
	preImage = IMG_Load( filename.c_str() ); /* Load the image */

	if( preImage == NULL )
	{
		perror("IMG_Load");
		return NULL;
	}
	postImage = SDL_DisplayFormat(preImage); /* Create the optimized image */
	SDL_FreeSurface(preImage);              /* Free the original image from memory */

	return postImage;                       /* Return the optimized image */
}
