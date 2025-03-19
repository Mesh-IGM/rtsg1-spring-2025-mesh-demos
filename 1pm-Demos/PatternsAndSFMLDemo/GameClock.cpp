#include "GameClock.h"

GameClock* GameClock::getInstance()
{
	static GameClock instance;
	return &instance;
}

GameClock::GameClock()
{
	prevTime = clock.now();
	observers = std::vector<ClockListener*>();
}

void GameClock::registerObserver(ClockListener* obs)
{
	observers.push_back(obs);
}

void GameClock::tick()
{
	auto currTime = clock.now();
	auto changeSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(currTime - prevTime);
	float deltaTime = changeSeconds.count();

	for(ClockListener* obs : observers)
	{
		obs->tick(deltaTime);
	}

	prevTime = currTime;
}

void GameClock::clearObservers()
{
	observers.clear();
}
