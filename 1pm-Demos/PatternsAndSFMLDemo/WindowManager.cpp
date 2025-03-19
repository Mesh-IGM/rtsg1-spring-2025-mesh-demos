#include "WindowManager.h"
#include "GameClock.h"

WindowManager* WindowManager::getInstance()
{
	static WindowManager instance;
	return &instance;
}

WindowManager::WindowManager()
{
	objects = std::vector<sf::Shape*>();
}

void WindowManager::add(sf::Shape* s)
{
	objects.push_back(s);
}

void WindowManager::draw(sf::RenderWindow& window)
{
	for (sf::Shape* s : objects)
	{
		window.draw(*s);
	}
}

sf::Vector2f WindowManager::genRandomPosition()
{
	return sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
}
