#include "Functions.h"
#include <iostream>
#include <GravityGame.h>

using namespace std;

void display(b2Body* player)
{
	cout << "Target: (" << getTargetPosition().x << ", " << getTargetPosition().y << ")  ";
	cout << "Player: (" << player->GetPosition().x << ", " << player->GetPosition().y << ")  ";
	cout << " Velocity: (" << player->GetLinearVelocity().x << ", " << player->GetLinearVelocity().y << ")" << endl;
}

void handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		applyForceToPlayer(b2Vec2(0.0f, VERT_FORCE));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyForceToPlayer(b2Vec2(-HOR_FORCE, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyForceToPlayer(b2Vec2(HOR_FORCE, 0.0f));
	}
}
