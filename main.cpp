/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Jaguti's main source file
 *
 * 	  Authors:  Håkon Vågsether <hauk142@gmail.com>, 
 * 	  	    Audun Måseidvåg <au.maas@adsl.no>,
 * 	  	    Kent Moe <kentvegard@hotmail.com>
 *
 * =====================================================================================
 */
#include "main.h"
#include "button.h"


SDL_Surface* window;
SDL_Surface* options;
SDL_Event event;

GLint background[4];

bool exiting = false;

Button playButton;
Button optionsButton;
Button quitButton;
Button backButton;
Button toggleSoundButton;
Button toggleEasterEggButton;

Button elementButtons[1];
const GLint elementButtonCount = 1;

Mix_Music *song;

int main ()
{
	
	if( !drawScreen() )/* Call drawScreen() */
	{
		puts("Error: Unable to start SDL");
		puts("drawScreen() returned 0 to main(), exiting!");
		exit(EXIT_FAILURE);
	}
	playButton.Load("./concept-Art/play.png", "play");
	optionsButton.Load("./concept-Art/options.png", "options");
	quitButton.Load("./concept-Art/quit.png", "quit");

	background[0] = SOIL_load_OGL_texture(
			"concept-Art/background_for_testing.png", 
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID, 
			SOIL_FLAG_NTSC_SAFE_RGB|SOIL_FLAG_COMPRESS_TO_DXT);

		

	drawScene();
	
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



	if(!background[1]||!background[0])
	{
		debug("fail!");
		printf("SOIL: %s\n", SOIL_last_result());
	}
	
	backButton.Load("./concept-Art/back.png", "back");
	toggleSoundButton.Load("./concept-Art/toggleSound.png", "sound");
	toggleEasterEggButton.Load("./concept-Art/toggleEasterEgg.png", "toggleeasteregg");

	elementButtons[0].Load("./concept-Art/waterText.png", "waterText");

	/* This, my friends, is known as the */
	/*     		   MAIN LOOP 	     */
	while(1)
	{
		while( SDL_PollEvent( &event ) )
		{
			switch( event.type )
			{
				case SDL_QUIT:
					cleanUp();
					exit(EXIT_SUCCESS);
					break;
				
				case SDL_MOUSEMOTION:
					if(!WHAT_WINDOW)
					{
						playButton.MouseOver();
						optionsButton.MouseOver();
						quitButton.MouseOver();
					}
					if(WHAT_WINDOW)
					{
						backButton.MouseOver();
						toggleSoundButton.MouseOver();
						toggleEasterEggButton.MouseOver();
					}
					break;

				case SDL_MOUSEBUTTONDOWN:
					if(!WHAT_WINDOW)
					{
						playButton.MouseDown();
						optionsButton.MouseDown();
						quitButton.MouseDown();
					}
					if(WHAT_WINDOW)
					{
						backButton.MouseDown();
						toggleSoundButton.MouseDown();
						toggleEasterEggButton.MouseDown();
					}
					break;

				case SDL_MOUSEBUTTONUP:
					if(!WHAT_WINDOW)
					{
						playButton.MouseUp();
						optionsButton.MouseUp();
						quitButton.MouseUp();
					}
					if(WHAT_WINDOW)
					{
						backButton.MouseUp();
						toggleSoundButton.MouseUp();
						toggleEasterEggButton.MouseUp();
					}
					if(WHAT_WINDOW==2)
					{
						for(int i=0;i<elementButtonCount;i++)
						{
							elementButtons[i].MouseUp();
						}
					}
					break;

				 case SDL_KEYDOWN:
					// TODO: Do something!
					break;

				 case SDL_KEYUP:
					// TODO: Do something!
					break;
				default:
					break;
				
			}
		drawScene();
		}
		if(WHAT_WINDOW==2 || WHAT_WINDOW==3)
		{
			/* Move shizz */
		}
	}

	cleanUp();                            /* clean it all up! */

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

int drawScene()
{
	switch(WHAT_WINDOW)
	{
		case 0: /* We are in the main menu */
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, background[0]);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f); // Bottom left
				glTexCoord2f(1.0f, 0.0f); glVertex2f(1000.0f, 0.0f); // Bottom right
				glTexCoord2f(1.0f, 1.0f); glVertex2f(1000.0f, 600.0f); // Top right
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 600.0f); // Top left
			glEnd();
			
			playButton.Draw( 450.0, 250.0, 118.0, 58.0 );
			optionsButton.Draw( 400.0, 325.0, 220.0, 58.0 );
			quitButton.Draw( 450.0, 400.0, 116.0, 56.0 );

			glDisable(GL_TEXTURE_2D);
			glFlush();
			
			SDL_GL_SwapBuffers();
			break;

		case 1:
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, background[1]);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f); // Bottom left
				glTexCoord2f(1.0f, 0.0f); glVertex2f(1000.0f, 0.0f); // Bottom right
				glTexCoord2f(1.0f, 1.0f); glVertex2f(1000.0f, 600.0f); // Top right
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 600.0f); // Top left
			glEnd();
				
			backButton.Draw(450,400, 149, 50);
			toggleSoundButton.Draw(290, 250, 462, 62);
			toggleEasterEggButton.Draw(200, 328, 658, 62);

			glDisable(GL_TEXTURE_2D);
			glFlush();

			SDL_GL_SwapBuffers();
			break;
			
		case 2:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, background[2]);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f); // Bottom left
				glTexCoord2f(1.0f, 0.0f); glVertex2f(1000.0f, 0.0f); // Bottom right
				glTexCoord2f(1.0f, 1.0f); glVertex2f(1000.0f, 600.0f); // Top right
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 600.0f); // Top left
			glEnd();

			elementButtons[0].Draw(835, 10, 53, 13);

			glDisable(GL_TEXTURE_2D);
			glColor3f(0.0f, 0.0f, 1.0f);
			glRectf(900.0f, 15.0f, 910.0f, 25.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			glFlush();

			SDL_GL_SwapBuffers();

		default:
			break;
	}
	return 0;
}
int drawScreen()
{
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0 ) /* Initialise SDL */
	{
		perror("SDL_Init");
		return 0;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP, SDL_OPENGL ); /* Set up the window */
	if(window == NULL)
	{
		perror("SDL_SetVideoMode");
		return 0;
	}
	
	SDL_WM_SetCaption("Jaguti", NULL);     /* Set the window title */

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	SDL_GL_SwapBuffers();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0,0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, 1000.0, 600.0, 0.0, 0.0, 1.0);

	glFlush();

	SDL_GL_SwapBuffers();
	//Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	//song = Mix_LoadMUS( "./musix/trololo.wav" );
	//if( song == NULL )
	//{
	//	perror("Mix_LoadMUS");
	//}
	/*
	 * TODO: This is commented out because music is annoying. 
	if(Mix_PlayMusic(song, -1) == -1)
	{
		perror("Mix_PlayMusic");
	}
	*/
	return 1;
}


bool applySurface( int x, int y, SDL_Surface* src, SDL_Surface* dest )
{
	SDL_Rect offset;                        /* Rectangle to hold the offsets */

	// Pass the offsets to the rectangle's offsets
	offset.x = x;
	offset.y = y;

	if( SDL_BlitSurface( src, NULL, dest, &offset ) != 0 )
	{
		perror("SDL_BlitSurface");
		return false;
	}
	
	return true;
}

SDL_Surface *loadImage( std::string filename )
{
	SDL_Surface* preImage = NULL;           /* The original image */
	SDL_Surface* postImage = NULL;          /* The optimized(?) image that SDL will use */
	
	preImage = IMG_Load( filename.c_str() ); /* Load the image */

	if( preImage == NULL )
	{
		perror("IMG_Load");
		return NULL;
	}
	postImage = SDL_DisplayFormatAlpha(preImage); /* Create the optimized image */
	SDL_FreeSurface(preImage);              /* Free the original image from memory */

	return postImage;                       /* Return the optimized image */
}

void cleanUp()
{
        /* TODO: ADD MOAR "FREE"S  */
	glDisable(GL_BLEND);
	SDL_Quit();                             /* Quit SDL and  */

}

/* 
void checkKeyUp()
{

}

void checkKeyDown()
{

}
*/
