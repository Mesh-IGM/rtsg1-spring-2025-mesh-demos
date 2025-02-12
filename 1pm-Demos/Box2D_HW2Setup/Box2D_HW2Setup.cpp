// Box2D_HW2Setup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Box2D/Box2D.h>

int main()
{
	// test that things compile/link
	b2Vec2 gravity(0.0f, -9.8f);

	// We want ONE world
	b2World* world = new b2World(gravity);

	// ** static body setup **

	// definition
	b2BodyDef groundBoxDef;
	groundBoxDef.position.Set(0.0f, -10.0f);

	// use the def to create the body in the world
	b2Body* groundBody = world->CreateBody(&groundBoxDef);

	// give it a shape
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 5.0f); // 100 wide & 10 tall

	// apply the shape to the body
	groundBody->CreateFixture(&groundBox, 0.0f); // static body so density 0 is fine


	// ** dynamic body setup **

	b2BodyDef fallingBoxDef;
	fallingBoxDef.position.Set(0.0f, 10.0f);
	fallingBoxDef.type = b2_dynamicBody;

	b2Body* fallingBody = world->CreateBody(&fallingBoxDef);

	b2PolygonShape fallingBox;
	fallingBox.SetAsBox(0.5f, 0.5f);

	// for things to move, a little more setup
	b2FixtureDef fallingFixtureDef;
	fallingFixtureDef.shape = &fallingBox;
	fallingFixtureDef.density = 1.0f;
	fallingFixtureDef.friction = 0.3f;
	fallingBody->CreateFixture(&fallingFixtureDef);

	// ** simulation loop **

	// typically a true game loop with logic!!!

	while (true)
	{
		// see where the box is
		b2Vec2 boxPos = fallingBody->GetPosition();
		std::cout << "box(" << boxPos.x << ", " << boxPos.y << ")" << std::endl;

		// manually advance time
		world->Step(
			1.0f / 60.0f, // time step
			6, // velocity it
			2 // position it
		);
	}

	// clean up
	delete world;
}
