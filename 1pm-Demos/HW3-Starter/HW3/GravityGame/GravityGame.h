#pragma once
#include <Box2D/Box2D.h>
#define SFML_STATIC
#include "include/SFML/Window.hpp"
#include "include/SFML/System.hpp"

#ifdef GRAVITYGAME_EXPORTS
#define GRAVITYGAME_API __declspec(dllexport)
#else
#define GRAVITYGAME_API __declspec(dllimport)
#endif

/// <summary>
/// Initializes the world, and other relevant variables. Must be called before creating bodies.
/// </summary>
/// <param name="gravity">The gravity vector of the physics world.</param>
extern "C" GRAVITYGAME_API void initVariables(b2Vec2 gravity);

/// <summary>
/// Frees all variables. Must be called at the end of the program.
/// </summary>
extern "C" GRAVITYGAME_API void releaseVariables();

/// <summary>
/// Updates the physics world every fixed timestep (1/60th of a second).
/// </summary>
/// <returns>True if the world was updated this frame, and false otherwise.</returns>
extern "C" GRAVITYGAME_API bool updateWorld();

/// <summary>
/// Detects collisions between the player and target based on distance.
/// </summary>
/// <param name="collisionDistance">The maximum distance to trigger a collision.</param>
/// <returns>True if there is a collision, and false otherwise.</returns>
extern "C" GRAVITYGAME_API bool checkCollisionAndMoveTarget(float collisionDistance);

/// <summary>
/// Applies an arbitrary force to the player's center.
/// </summary>
/// <param name="force">The force to apply.</param>
extern "C" GRAVITYGAME_API void applyForceToPlayer(b2Vec2 force);

/// <summary>
/// Creates the floor body in the box2d world.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYGAME_API void createFloor(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the ceiling body in the box2d world.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYGAME_API void createCeiling(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the right wall body in the box2d world.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYGAME_API void createRightWall(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the left wall body in the box2d world.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYGAME_API void createLeftWall(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates a dynamic body for the player and returns a pointer to it.
/// </summary>
/// <param name="center">The center point of the body's starting position.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
/// <returns>A pointer to the b2Body.</returns>
extern "C" GRAVITYGAME_API b2Body* createPlayer(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Gets a copy of the target position.
/// </summary>
/// <returns>A copy of the target position.</returns>
extern "C" GRAVITYGAME_API b2Vec2 getTargetPosition();

/// <summary>
/// Sets the min and max values for target X and Y spawn locations.
/// </summary>
/// <param name="minX">The minimum X value for target locations.</param>
/// <param name="maxX">The maximum X value for target locations.</param>
/// <param name="minY">The minimum Y value for target locations.</param>
/// <param name="maxY">The maximum Y value for target locations.</param>
extern "C" GRAVITYGAME_API void setTargetBounds(float minX, float maxX, float minY, float maxY);