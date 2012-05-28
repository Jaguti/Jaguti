/*
 * =====================================================================================
 *
 *       Filename:  button.h
 *
 *    Description:  Header file for Jaguti's buttons
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL/SDL.h>
#include <iostream>
#include <GL/glu.h>

extern SDL_Surface* window;
extern int WHAT_WINDOW;

class Button
{
private:
	GLint texture;
	const char* buttonName;
	SDL_Rect rect;
public:
	Button();                /*  */
	void Load(const char * filename, const char* name);
	void Draw(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	void MouseOver();
	void MouseUp();
	void MouseDown();
	~Button();
};


extern Button playButton;
extern Button optionsButton;
extern Button quitButton;
extern Button backButton;
extern Button toggleSoundButton;
extern Button toggleEasterEggButton;

extern Button elementButtons[1];
#endif
