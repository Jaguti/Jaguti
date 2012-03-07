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
#include "button.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
SDL_Surface* window;
SDL_Surface* background;
SDL_Surface* options;
SDL_Event event;

bool exiting = false;

Button playButton;
Button optionsButton;
Button quitButton;
//Button backButton;


Mix_Music *song;

int main ()
{
	
	if( !drawScreen() )/* Call drawScreen() */
	{
		puts("Error: Unable to start SDL");
		puts("drawScreen() returned 0 to main(), exiting!");
		exit(EXIT_FAILURE);
	}
	playButton.Load("./concept-Art/play.png", "play");
	optionsButton.Load("./concept-Art/options.png", "options");
	quitButton.Load("./concept-Art/quit.png", "quit");
//	backButton.Load("./concept-Art/back.png", "back");

	background = loadImage("./concept-Art/background_for_testing.png");
	SDL_BlitSurface( background, NULL, window, NULL ); /* Apply image to screen */

	SDL_Flip( window );                     /* Update screen */

	playButton.Draw( 450, 250, 118, 58 );
	optionsButton.Draw( 400, 325, 220, 58 );
	quitButton.Draw( 450, 400, 116, 56 );

	SDL_Flip( window );                     /* Update screen */

	while( exiting == false )
	{
		while( SDL_PollEvent( &event ) )
		{
			switch( event.type )
			{
				case SDL_QUIT:
					exiting = true;
					break;
				
				case SDL_MOUSEMOTION:
					checkMouseOver();	
					break;

				case SDL_MOUSEBUTTONDOWN:
					checkMouseDown();
					break;

				case SDL_MOUSEBUTTONUP:
					checkMouseUp();
					break;

				 case SDL_KEYDOWN:
					// TODO: Do something!
					break;

				case SDL_KEYUP:
					// TODO: Do something!
					break;
				
			}
		}
	}

	cleanExit();                            /* clean it all up! */

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
	
	SDL_WM_SetCaption("Jaguti", NULL);     /* Set the window title */

	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	song = Mix_LoadMUS( "./musix/trololo.wav" );
	if( song == NULL )
	{
		perror("Mix_LoadMUS");
	}
	if(Mix_PlayMusic(song, -1) == -1)
	{
		perror("Mix_PlayMusic");
	}
	return 1;
}


bool applySurface( int x, int y, SDL_Surface* src, SDL_Surface* dest )
{
	SDL_Rect offset;                        /* Rectangle to hold the offsets */

	// Pass the offsets to the rectangle's offsets
	offset.x = x;
	offset.y = y;

	if( SDL_BlitSurface( src, NULL, dest, &offset ) != 0 )
	{
		perror("SDL_BlitSurface");
		return false;
	}
	
	return true;
}

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
	postImage = SDL_DisplayFormatAlpha(preImage); /* Create the optimized image */
	SDL_FreeSurface(preImage);              /* Free the original image from memory */

	return postImage;                       /* Return the optimized image */
}

void cleanExit()
{
        /* TODO: ADD MOAR "FREE"S  */
	SDL_FreeSurface(background);            /* Free the background from memory */
	SDL_Quit();                             /* Quit SDL and  */
}

void checkMouseOver()
{
	playButton.MouseOver();
	optionsButton.MouseOver();
	quitButton.MouseOver();
}

void checkMouseUp()
{
	playButton.MouseUp();
	optionsButton.MouseUp();
	quitButton.MouseUp();
}

void checkMouseDown()
{
	playButton.MouseDown();
	optionsButton.MouseDown();
	quitButton.MouseDown();

}

void checkKeyUp()
{

}

void checkKeyDown()
{

}
