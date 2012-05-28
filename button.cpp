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
 *  		2 - playing the game 
 *-----------------------------------------------------------------------------*/
int WHAT_WINDOW = 0;

Button::Button()
{
}

void Button::Load(const char * filename, const char* name)
{
	buttonName = name;
	texture = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_NTSC_SAFE_RGB|SOIL_FLAG_COMPRESS_TO_DXT);

}

void Button::Draw(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y); // Bottom left
		glTexCoord2f(1.0f, 0.0f); glVertex2f(x+w, y); // Bottom right
		glTexCoord2f(1.0f, 1.0f); glVertex2f(x+w, y+h); // Top right
		glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y+h); // Top left
	glEnd();
	rect.x = (Sint16) x;
	rect.y = (Sint16) y;
	rect.w = (Sint16) w;
	rect.h = (Sint16) h;
	/*  applySurface( x, y, buttonSurface, window );*/
}

void Button::MouseOver()
{
	int x = event.motion.x, y = event.motion.y;

	if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
	{
		debug(buttonName);
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
					WHAT_WINDOW=1; // We are now officially in the options menu! :D 
					drawScene();
				}

				if(!strcmp(buttonName, "play"))
				{
					debug("Play\n");
					WHAT_WINDOW=2;
					drawScene();
				}
				break;
			case 1:
				if(!strcmp(buttonName, "back"))
				{
					debug("Back!\n");
					WHAT_WINDOW=0;
					drawScene();
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
}
