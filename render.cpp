/*
 * =====================================================================================
 *
 *       Filename:  render.cpp
 *
 *    Description:  The file containing RenderClass. It should be noted that this is the
 *    		    only source file that does not have its own header file. 
 *    		    RenderClass is declared in main.h.
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */

#include "main.h"

namespace Jaguti
{ 
	void RenderClass::Initialise()
	{
		if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0 ) /* Initialise SDL */
		{
			perror("SDL_Init");
			exit(EXIT_FAILURE);
		}
	
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
		SDL_Surface* window = SDL_SetVideoMode( window_width, window_height, window_bpp, SDL_OPENGL ); /* Set up the window */
		if(window == NULL)
		{
			perror("SDL_SetVideoMode");
			exit(EXIT_FAILURE);
		}
		
		SDL_WM_SetCaption("Jaguti", NULL);     /* Set the window title */
	
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
	
		SDL_GL_SwapBuffers();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
		glClear(GL_COLOR_BUFFER_BIT);
	
		glViewport(0,0, window_width, window_height);
	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	
		glOrtho(0.0, 1000.0, 600.0, 0.0, 0.0, 1.0);
	
		glFinish();
	
		SDL_GL_SwapBuffers();
		//Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
		//song = Mix_LoadMUS( "./musix/trololo.wav" );
		//if( song == NULL )
		//{
		//	perror("Mix_LoadMUS");
		//}
		/*
		TODO: This is commented out because music is annoying. 
		if(Mix_PlayMusic(song, -1) == -1)
		{
			perror("Mix_PlayMusic");
		}
		*/
	}
	
	void RenderClass::PissOff()
	{
		glDisable(GL_BLEND);
		SDL_Quit();
#ifdef DEBUG
		std::cout << "Adieu!" << std::endl;
#endif
	}
	
} // namespace Jaguti 

/*void LoadAll()
{
	GLint background[4];

	playButton.Load("./concept-Art/play.png", "play");
	optionsButton.Load("./concept-Art/options.png", "options");
	quitButton.Load("./concept-Art/quit.png", "quit");


	background[0] = SOIL_load_OGL_texture(
			"concept-Art/background_for_testing.png", 
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID, 
			SOIL_FLAG_NTSC_SAFE_RGB|SOIL_FLAG_COMPRESS_TO_DXT);

	background[1] = SOIL_load_OGL_texture(
			"concept-Art/optionsbackground.png", 
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID, 
			SOIL_FLAG_NTSC_SAFE_RGB|SOIL_FLAG_COMPRESS_TO_DXT);
	
	background[2] = SOIL_load_OGL_texture(
			"concept-Art/playbackground.png", 
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID, 
			SOIL_FLAG_NTSC_SAFE_RGB|SOIL_FLAG_COMPRESS_TO_DXT);
			

	if( !background[1] || !background[0] || !background[2] )
	{
		printf( "SOIL: %s\n", SOIL_last_result() );
		exit(EXIT_FAILURE);
	}
	
	backButton.Load("./concept-Art/back.png", "back");
	toggleSoundButton.Load("./concept-Art/toggleSound.png", "sound");
	toggleEasterEggButton.Load("./concept-Art/toggleEasterEgg.png", "toggleeasteregg");

	elementButtons[0].Load("./concept-Art/waterText.png", "waterText");
	
}*/
