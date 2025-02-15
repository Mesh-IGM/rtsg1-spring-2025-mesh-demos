// InputLoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> // continuous input/output

using namespace std;

void cinInputLoop(int xTarget);
void kbhitInputLoop(int xTarget);

int main()
{
	//cinInputLoop(10); 
	kbhitInputLoop(100);
}


// Logic/physics synced to the input loop is problematic.
void cinInputLoop(int xTarget)
{
	// Setup & prompt
	int xPosition = 0;
	int yPosition = 0;

	cout << "Welcome to 'Run To xPosition = " << xTarget << endl;
	cout << "Use WASD followed by <Enter> to Move" << endl;

	// Use cin and keep reading into the variable
	char userInput;
	while (xPosition < xTarget)
	{
		// Pause & wait for input.
		// User has to hit enter for things to continue
		cin >> userInput;

		// our game logic happens once per input loop
		switch (userInput)
		{
		case 'w':
		case 'W':
			yPosition++;
			break;

		case 'a':
		case 'A':
			xPosition--;
			break;

		case 's':
		case 'S':
			yPosition--;
			break;

		case 'd':
		case 'D':
			xPosition++;
			break;

		default: break;
		}

		cout << "Player is at (" << xPosition << "," << yPosition << ")" << endl;

		// Ignores everything in the buffer that we haven't read already so the
		// buffer is clear for the next cin
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "You Win!" << endl;
}

// Our goal is real-time, continuous input. We don't want to stop and wait for
// input & we don't want the user to need to press enter!
void kbhitInputLoop(int xTarget)
{
	// Setup & prompt
	int xPosition = 0;
	int yPosition = 0;

	cout << "Welcome to 'Run To xPosition = " << xTarget << endl;
	cout << "Use WASD to Move" << endl;

	while (xPosition != xTarget)
	{
		// ONLY perform our input logic if a key is actively being held down
		if (_kbhit()) 
		{
			// Not perfect. Doesn't support multiple inputs at once.
			// Gives us the most recent key pressed.
			char input = _getch();

			// Rest of our logic is the same
			switch (input)
			{
			case 'w':
			case 'W':
				yPosition++;
				break;

			case 'a':
			case 'A':
				xPosition--;
				break;

			case 's':
			case 'S':
				yPosition--;
				break;

			case 'd':
			case 'D':
				xPosition++;
				break;

			default: break;
			}
		}

		cout << "Player is at (" << xPosition << "," << yPosition << ")" << endl;
	}

	cout << "You Win!" << endl << endl;

	// Extra cin at the end just so the program doesn't close on us when we win
	cout << "Press enter to continue" << endl;
	char tmp;
	cin >> tmp;
}