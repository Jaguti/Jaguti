/*
 * =====================================================================================
 *
 *       Filename:  button.h
 *
 *    Description:  Header file for Jaguti's buttons
 *
 *        Version:  1.0
 *        Created:  24. feb. 2012 kl. 00.05 +0100
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
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
	SDL_Rect rect;
public:
	Button();                /*  */
	void Load(std::string filename);
	void Draw( int x, int y, int w, int h );
};

#endif
