#pragma once
#include <random>
#include <ctime>
#include "Engine/Logger/Logger.hpp"

namespace ce
{
	namespace Random
	{
		static std::default_random_engine randomEngine(static_cast<unsigned long>(std::time(nullptr)));

		static inline float Value(float begin, float end)
		{
			if (begin > end)
			{
				ce::Logger::LogToFile("Random: begin value greater than end, strange behavior may occur");
			}

			std::uniform_real_distribution<float> dist(begin, end);
			return dist(randomEngine);
		}

		static inline int Value(int begin, int end)
		{
			if (begin > end)
			{
				ce::Logger::LogToFile("Random: begin value greater than end, strange behavior may occur");
			}

			std::uniform_int_distribution<int> dist(begin, end);
			return dist(randomEngine);
		}
	}
}