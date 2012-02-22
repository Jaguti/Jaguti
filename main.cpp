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
	
	background = loadImage("./concept-Art/background_for_testing.png"); /* Load background */
	play = loadImage("./concept-Art/Play.png"); /* Load the play button */
	options = loadImage("./concept-Art/options.png"); /* Load the options button */
	quit = loadImage("./concept-Art/quit.png"); /* Load the quit button */

	SDL_WM_SetCaption("Jaguti", NULL);     /* Set the window title */

	SDL_BlitSurface( background, NULL, window, NULL ); /* Apply image to screen */

	SDL_Flip( window );                     /* Update screen */

	applySurface( 450, 250, play, window ); /* Apply the play button the the window */
	applySurface( 400, 325, options, window ); /* Apply the options button to the window */
	applySurface( 450, 400, quit, window ); /* Apply the quit button to the window */

	SDL_Flip( window );                     /* Update screen */

	SDL_Delay( 5000 ); /* Wait for 3 seconds */
	
	SDL_FreeSurface(background);            /* Free the background from memory */
	SDL_FreeSurface(play);                  /* Free the play button from memory */
	SDL_FreeSurface(options);               /* Free the options button from memory */
	SDL_FreeSurface(quit);                  /* Free the quit button from memory */
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
