#pragma once

#include "ClockListener.h"

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ball : public ClockListener
{
public:
	Ball(unsigned int radius, sf::Color color, sf::Vector2f initPos);
	void tick(float timeElapsed) override;
	sf::Shape* getShape();

private:
	unsigned int radius;
	sf::Vector2f velocity;
	sf::CircleShape circle;
};

