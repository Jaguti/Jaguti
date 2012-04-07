/*
 * =====================================================================================
 *
 *       Filename:  button.h
 *
 *    Description:  Header file for Jaguti's buttons
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL/SDL.h>
#include <iostream>

extern SDL_Surface* window;
extern SDL_Surface* background;
extern int WHAT_WINDOW;

class Button
{
private:
	SDL_Surface* buttonSurface;
	std::string buttonName;
	SDL_Rect rect;
public:
	Button();                /*  */
	void Load(std::string filename, std::string name);
	void Draw( int x, int y, int w, int h );
	void MouseOver();
	void MouseUp();
	void MouseDown();
	~Button();
};

extern Button playButton;
extern Button optionsButton;
extern Button quitButton;
#endif
