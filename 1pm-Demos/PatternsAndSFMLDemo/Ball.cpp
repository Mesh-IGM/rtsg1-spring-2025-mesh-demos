#include "Ball.h"
#include "WindowManager.h"
#include "GameClock.h"

const unsigned int MAX_SPEED = 100;
const unsigned int MIN_SPEED = 20;

Ball::Ball(unsigned int radius, sf::Color color, sf::Vector2f initPos)
{
	this->radius = radius;
	circle = sf::CircleShape(radius);

	circle.setFillColor(color);

	velocity = sf::Vector2f(
		(int)(rand() % MAX_SPEED) + MIN_SPEED,
		(int)(rand() % MAX_SPEED) + MIN_SPEED
	);

	if(initPos.x + radius * 2 > WINDOW_WIDTH)
	{
		initPos.x = WINDOW_WIDTH - radius * 2;
	}
	else if(initPos.x < 0)
	{
		initPos.x = 0;
	}

	if(initPos.y + radius * 2 > WINDOW_HEIGHT)
	{
		initPos.y = WINDOW_HEIGHT - radius * 2;
	}
	else if(initPos.y < 0)
	{
		initPos.y = 0;
	}

	circle.setPosition(initPos);

	GameClock::getInstance()->registerObserver(this);
	WindowManager::getInstance()->add(&circle);
}

void Ball::tick(float timeElapsed)
{
	sf::Vector2f pos = circle.getPosition();

	if (pos.x + radius * 2 > WINDOW_WIDTH)
	{
		pos.x = WINDOW_WIDTH - radius * 2;
		velocity.x = -velocity.x;
	}
	else if (pos.x < 0)
	{
		pos.x = 0;
		velocity.x = -velocity.x;
	}

	if (pos.y + radius * 2 > WINDOW_HEIGHT)
	{
		pos.y = WINDOW_HEIGHT - radius * 2;
		velocity.y = -velocity.y;
	}
	else if (pos.y < 0)
	{
		pos.y = 0;
		velocity.y = -velocity.y;
	}

	pos += velocity * timeElapsed;

	circle.setPosition(pos);
}

sf::Shape* Ball::getShape()
{
	return &circle;
}
