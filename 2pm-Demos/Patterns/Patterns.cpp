// Patterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "WindowManager.h"
#include "GameClock.h"
#include "Ball.h"

#include <vector>
#include <iostream>
using namespace std;

const unsigned int NUM_BALLS = 10;

void bouncingBalls();

int main()
{
    bouncingBalls();

    if (_CrtDumpMemoryLeaks())
        cout << "\nmemory leaks?" << endl;
    else
        cout << "\nNo memory leaks. :)" << endl;
}

void bouncingBalls()
{
    GameClock* gClock = GameClock::getInstance();
    WindowManager* wManager = WindowManager::getInstance();

    std::vector<Ball*> toys;

    for (int i = 0; i < NUM_BALLS; i++)
    {
        unsigned int radius = rand() % 45 + 10;
        sf::Color color = sf::Color(
            rand() % 155 + 100,
            0,
            rand() % 155 + 100
        );
        toys.push_back(new Ball(radius, color, WindowManager::genRandomPosition()));
    }

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        gClock->tick();
        wManager->draw(window);

        window.display();
    }

    for(Ball* toy : toys)
	{
		delete toy;
	}
}
