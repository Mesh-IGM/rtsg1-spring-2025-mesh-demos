#pragma once

#include <mutex>

struct FibCalc
{
	void PrintFibNum(int num);
	void PrintFibNumMtx(int num, std::mutex* mtx);

	// helper
	unsigned int CalcFibNum(int num);
};

