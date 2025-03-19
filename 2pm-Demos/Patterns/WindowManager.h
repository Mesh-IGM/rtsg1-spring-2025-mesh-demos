#pragma once

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <chrono> 

const unsigned int WINDOW_WIDTH = 400;
const unsigned int WINDOW_HEIGHT = 600;

class WindowManager
{
public:
	static WindowManager* getInstance();
	static sf::Vector2f genRandomPosition();
	void add(sf::Shape* go);
	void draw(sf::RenderWindow& window);

private:
	WindowManager();
	static WindowManager instance;
	std::vector<sf::Shape*> objects;
};

