#pragma once
#include <random>
#include "Engine/Logger/Logger.hpp"

namespace ce
{
	namespace random
	{
		// Sets generator seed (call once in program)
		// If you want to overwrite seed set flag overwrite to true
		void SetSeed(unsigned int seed, bool overwrite = false);
		// Returns random value between rangeBegin and rangeEnd
		int GetValue(int rangeBegin, int rangeEnd);
	}
}