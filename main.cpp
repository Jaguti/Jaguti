/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Jaguti main.cpp
 *
 *        Version:  
 *        Created:  02/19/2012 11:52:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Håkon Vågsether, Audun Måseidvåg
 *   Organization:  Jaguti
 *
 * =====================================================================================
 */
#include "main.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ()
{
	drawScreen();

	SDL_Delay( 3000 ); /* Wait for 3 seconds */

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

int drawScreen()
{
	// Declare the surfaces
	SDL_Surface* window = NULL;             /* Initialise the window */
	
	SDL_Init( SDL_INIT_EVERYTHING );        /* Initialise SDL */

	window = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE ); /* Set up the window */
}
