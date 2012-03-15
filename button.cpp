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
			//backButton.Draw(?,?,?,?);
			//toggleEasterEggButton.Draw(?,?,?,?);
			//toggleSoundButton.Draw(?,?,?,?);
			//TODO: Remove the main menu's buttons!!
			SDL_Flip(window);
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
