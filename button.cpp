/*
 * =====================================================================================
 *
 *       Filename:  button.cpp
 *
 *    Description:  Source file for Jaguti's buttons
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <TODO: Add your email address here>
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

void Button::Load(std::string filename, std::string name)
{
	buttonSurface = loadImage(filename);
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
		std::cout << "Mouse is over " << buttonName << std::endl;
	}

	
}

void Button::MouseUp()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		std::cout << "Mouse is up at " << buttonName << std::endl;

		switch(WHAT_WINDOW)
		{
			case 0:
				if(buttonName == "quit")
				{
					cleanExit();
					exit(EXIT_SUCCESS);
				}
				
	
				if(buttonName == "options")
				{
					std::cout << "Options!" << std::endl;
					background = loadImage("./concept-Art/optionsbackground.png");	//TODO: Remove this comment!
					SDL_BlitSurface( background, NULL, window, NULL );
					//TODO: Add buttons!
					WHAT_WINDOW=1; /* We are now officially in the options menu! :D */
					//backButton.Draw(?,?,?,?);
					//toggleEasterEggButton.Draw(?,?,?,?);
					//toggleSoundButton.Draw(?,?,?,?);
					//TODO: Remove the main menu's buttons!!
					SDL_Flip(window);
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
		std::cout << "Mouse is down at " << buttonName << std::endl;
	}	
}

Button::~Button()
{
	SDL_FreeSurface(buttonSurface);	
}
