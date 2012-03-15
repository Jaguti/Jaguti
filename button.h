/*
 * =====================================================================================
 *
 *       Filename:  button.h
 *
 *    Description:  Header file for Jaguti's buttons
 *
 *        Version:  
 *        Created:  24. feb. 2012 kl. 00.05 +0100
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Håkon Vågsether, Audun Måseidvåg
 *   Organization:  Jaguti
 *
 * =====================================================================================
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL/SDL.h>
#include <iostream>

extern SDL_Surface* window;
extern SDL_Surface* background;

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
