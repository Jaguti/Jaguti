/*
 * =====================================================================================
 *
 *       Filename:  button.cpp
 *
 *    Description:  Source file for Jaguti's buttons
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */
#include "button.h"
#include "main.h"

/*-----------------------------------------------------------------------------
 *  			INFORMATION REGARDING WHAT_WINDOW
 *  
 *  WHAT_WINDOW is used to keep track of what menu, window or screen the user
 *  is interacting with. 
 *  Each values has its own menu:
 *  		0 - main menu
 *  		1 - options menu
 *  		2 - playing the game (without element picker)
 *  		3 - playing the game (with element picker)
 *-----------------------------------------------------------------------------*/
int WHAT_WINDOW = 0;

Button::Button()
{
}

void Button::Load(const char * filename, const char* name)
{
	texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB);
	buttonName = name;
}

void Button::Draw(int x, int y, int w, int h)
{
	rect.x = (Sint16) x;
	rect.y = (Sint16) y;
	rect.w = (Sint16) w;
	rect.h = (Sint16) h;
	applySurface( x, y, buttonSurface, window );
}

void Button::MouseOver()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		debug((const char *)buttonName);
	}

	
}

void Button::MouseUp()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		debug(buttonName);

		switch(WHAT_WINDOW)
		{
			case 0:
				if(!strcmp(buttonName, "quit"))
				{
					cleanUp();
					exit(EXIT_SUCCESS);
				}
				
	
				if(!strcmp(buttonName, "options"))
				{
					debug("Options\n");
					background = loadImage("./concept-Art/optionsbackground.png");	//TODO: Remove this comment!
					SDL_BlitSurface( background, NULL, window, NULL );
					SDL_GL_SwapBuffers();
					//TODO: Add buttons!
					WHAT_WINDOW=1; /* We are now officially in the options menu! :D */
					backButton.Draw(450,400, 149, 50);
					toggleSoundButton.Draw(290, 250, 462, 62);
					toggleEasterEggButton.Draw(200, 328, 658, 62);
					//TODO: Remove the main menu's buttons!!
					SDL_GL_SwapBuffers();
				}

				if(!strcmp(buttonName, "play"))
				{
					debug("Play\n");
					background = loadImage("./concept-Art/playBackground.png");
					SDL_BlitSurface( background, NULL, window, NULL );
					WHAT_WINDOW=2;
					SDL_GL_SwapBuffers();
				}
				break;
			case 1:
				if(!strcmp(buttonName, "back"))
				{
					debug("Back!\n");
					background = loadImage("./concept-Art/background_for_testing.png");
					SDL_BlitSurface( background, NULL, window, NULL );
					SDL_GL_SwapBuffers();

					WHAT_WINDOW=0;
					playButton.Draw( 450, 250, 118, 58 );
					optionsButton.Draw( 400, 325, 220, 58 );
					quitButton.Draw( 450, 400, 116, 56 );

					SDL_GL_SwapBuffers();
				}

				if(!strcmp(buttonName, "toggleeasteregg"))
				{
					debug("ToggleEasterEgg\n");
					//TODO: Toggle Dolan Mode!
				}

				if(!strcmp(buttonName, "sound"))
				{
					debug("ToggleSound!\n");
					//TODO: Toggle the sound!
				}
				break;
		}
	}
	
}

void Button::MouseDown()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		debug(buttonName);
	}	
}

Button::~Button()
{
	SDL_FreeSurface(buttonSurface);	
}
