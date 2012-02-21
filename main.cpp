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
	if( !drawScreen() )/* Call drawScreen() */
	{
		puts("Error: Unable to start SDL");
		puts("drawScreen() returned 0 to main(), exiting!");
		exit(EXIT_FAILURE);
	}
	SDL_Delay( 5000 ); /* Wait for 3 seconds */

	SDL_FreeSurface(background);            /* Free the background from memory */
	SDL_Quit();                             /* Quit SDL and  */
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

int drawScreen()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) /* Initialise SDL */
	{
		perror("SDL_Init");
		return 0;
	}

	window = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP, SDL_SWSURFACE ); /* Set up the window */
	if(window == NULL)
	{
		perror("SDL_SetVideoMode");
		return 0;
	}
	return 1;
}
