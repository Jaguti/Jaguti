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

// Allan, please add a comment.

#include "main.h"


using namespace Jaguti;

void timer1();

int main()
{
	/* Hello world! :) */
	std::thread tInitialise( * RenderClass::Initialise );

	tInitialise.join();

	std::cout << "Done!" << std::endl;

	std::thread tTimer1(timer1);
	
	tTimer1.join();
	return 0;
}
 
void timer1()
{
	std::this_thread::sleep_for(sleepDuration);
}
