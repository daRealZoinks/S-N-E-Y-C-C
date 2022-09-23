#pragma once

#include <random>

class Random
{
public:
	static void Init()
	{
		s_RandomEngine.seed(std::random_device()());
	}

	static int Range(int min, int max)
	{
		int number = (int)s_Distribution(s_RandomEngine) / (int)std::numeric_limits<uint32_t>::max();
		return number % (max - min) + min;
	}

private:
	static std::mt19937 s_RandomEngine;
	static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
};

