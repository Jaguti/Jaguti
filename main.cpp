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

#include <iostream>
#include <thread>
#include <chrono>

const std::chrono::duration<double> sleepDuration(0.025); /* 25 milliseconds, 1  / 40  = 0.025 			 */
							  /* We do this in order to lock the framerate at 40 FPS */

void timer1();

int main()
{
	std::thread tTimer1(timer1);
	std::cout << "test" << std::endl;
	
	tTimer1.join();
	return 0;
}
 
void timer1()
{
	std::this_thread::sleep_for(sleepDuration);
}
