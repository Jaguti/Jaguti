/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  The main header file for Jaguti
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */

#ifndef JAGUTI_MAIN_H
#define JAGUTI_MAIN_H

#include <chrono>
#include <iostream>
#include <thread>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <SOIL.h>

namespace Jaguti
{
	
	
	const std::chrono::duration<double> sleepDuration(0.025); /* 25 milliseconds, 1  / 40  = 0.025 			 */
								  /* We do this in order to lock the framerate at 40 FPS */

	// Better wrap these up somehow!
	const int window_width = 1000;
	const int window_height = 600;
	const int window_bpp = 32;


	class RenderClass
	{
		public:
			static void Initialise();
	};
}


#endif
