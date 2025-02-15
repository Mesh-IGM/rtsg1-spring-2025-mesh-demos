#include <Box2D/Box2D.h> 
#include "box2d_helpers.h"

b2Body* CreateStaticBox(b2World* world, float posX, float posY, float hWidth, float hHeight)
{
	b2BodyDef boxDef;
	boxDef.position.Set(posX, posY);
	b2Body* body = world->CreateBody(&boxDef);
	b2PolygonShape box;
	box.SetAsBox(hWidth, hHeight);
	body->CreateFixture(&box, 0.0f);
	return body;
}

b2Body* CreateDynamicBox(b2World* world, float posX, float posY, float hWidth, float hHeight)
{
	b2BodyDef boxDef;
	boxDef.position.Set(posX, posY);
	boxDef.type = b2_dynamicBody;
	b2Body* body = world->CreateBody(&boxDef);
	b2PolygonShape box;
	box.SetAsBox(hWidth, hHeight);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
	fixtureDef.density = 1.0f; 
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
	return body;
}

