#pragma once

#include <chrono> 
#include <vector>
#include "ClockListener.h"

class GameClock
{
public:
	static GameClock* getInstance();
	void registerObserver(ClockListener* obs);
	void tick();
	void clearObservers();

private:
	static GameClock instance;
	GameClock();
	std::chrono::high_resolution_clock clock;
	std::chrono::steady_clock::time_point prevTime;
	std::vector<ClockListener*> observers;
};

