#pragma once
#include <Box2D/Box2D.h>

void display(b2Body* player);
void handleInput();

// Change these as needed to balance your gameplay
const float GRAVITY = -9.8f;
const float HOR_FORCE = 0.15;
const float VERT_FORCE = 2.0f;
