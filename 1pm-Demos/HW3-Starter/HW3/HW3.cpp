/*
* IGME-209 - HW3 - Graphical Gravity Game
* 
* NAME:
* 
* RELEASE NOTES:
* 
* TECHNICAL OVERVIEW: 
* (major functions, classes, their purpose, etc. -- i.e., things to help us understand your approach)
* 
* SCORING SYSTEM:
* 
* ADDITIONAL FEATURE(S):
* 
*/


#include <iostream>
#include <iomanip>

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Functions.h"

using namespace std;

#include <GravityGame.h>

/* GravityGame.h is the header file for a dynamically linked library (dll) called
* GravityGameDLL.dll. The GravityGame library is a set of functions that satisfy the
* requirements of HW2 - Gravity Game. In order to allow you to complete HW3 without
* the need for a done version of HW2, this DLL has been created. Using it's functions,
* you can implement HW3 without the HW2 code. A full breakdown of it's functions
* can be found in the homework document.
*/

int main()
{
	//Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	// Sets the possible bounds of where the target can spawn (-9, -9) to (9, 9) here
	// so that the target is always within the walls with a little room to spare.
	// This function is from the DLL.
	setTargetBounds(-9.0f, 9.0f, -9.0f, 9.0f);

	// Create the physics world, and all the objects.
	// These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));
	createFloor(b2Vec2(0.0f, -10.5f), 10.0f, 0.5f);
	createCeiling(b2Vec2(0.0f, 10.5f), 10.0f, 0.5f);
	createLeftWall(b2Vec2(-10.5f, 0.0f), 0.5f, 10.0f);
	createRightWall(b2Vec2(10.5f, 0.0f), 0.5f, 10.0f);

	//Create the player in the physics world. Return a pointer.
	b2Body* player = createPlayer(b2Vec2(0.0f, 0.0f), 0.75f, 0.75f);

	int targetsLeft = 2;

	while (targetsLeft >  0)
	{
		//This function advances the physics world every fixed timestep (1/60th of a second)
		//This function is from the DLL.
		bool physicsFrame = updateWorld();

		//Process input and apply forces to the player.
		//This function is in Functions.h.
		handleInput();

		//Display the current target and player positions. Only displays on
		//physics frames, since those are the only ones where things move.
		//This function is in Functions.h, and won't be used in the final HW3.
		if (physicsFrame) 
		{
			display(player);
		}

		//This function checks if the player is close to the target. 
		//It takes in a maximum collision distance.
		//This function is from the DLL.
		if (checkCollisionAndMoveTarget(1.0f))
		{
			targetsLeft--;
		}
	}

	/* The following block of code is from the SFML drawing tutorial. To accomplish
	* the requirements of HW3, you will need to take the code above and modify it
	* to work within the code provided below. Rather than using the display() method
	* like above, you will need to render shapes to represent the walls, player, and
	* target.
	* 
	* You may find it helpful to create new helpers in Functions.h/cpp and/or create
	* a new class to manage the game state, SFML window, and rendering.
	* 
	* However you architect your system, make sure to document it well in your code!
	* 
	* Note, you should be creating your SFML shapes BEFORE the while (window.isOpen())
	* loop, then render them WITHIN the loop. Additionally, the while(targetsCollected < 2)
	* loop from up above will need to be turned into an if statement so that it doesn't
	* block SFML from rendering new frames to the window.
	*/

	/*
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Game");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}
	*/

	// REMOVE THIS CODE when swapping to the SFML window
	cout << "Press escape to exit!" << endl;
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		//Get stuck in this loop til they hit escape
	}
	releaseVariables();


}