#pragma once
#include "Engine/Assert.hpp"
#include <random>
#include <ctime>

namespace ce
{
	// Namespace for randomizing functions
	namespace Random
	{
		namespace
		{
			static std::default_random_engine randomEngine(static_cast<unsigned long>(std::time(nullptr)));
		}

		// Randomizes float 
		// begin	- minimum value
		// end		- maximum value
		static inline float Value(float begin, float end)
		{
			CE_ASSERT(end > begin, "begin value greater than end");

			std::uniform_real_distribution<float> dist(begin, end);
			return dist(randomEngine);
		}

		// Randomizes int 
		// begin	- minimum value
		// end		- maximum value
		static inline int Value(int begin, int end)
		{
			CE_ASSERT(end > begin, "begin value greater than end");

			std::uniform_int_distribution<int> dist(begin, end);
			return dist(randomEngine);
		}
	}
}