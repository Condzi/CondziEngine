#include "Engine/Util/Utility.hpp"

void ce::random::SetSeed(unsigned int seed, bool overwrite)
{
	static bool seedSet = false;

	if (seedSet && !overwrite)
	{
		return;
	}

	std::srand(seed);

	seedSet = true;
}

int ce::random::GetValue(int rangeBegin, int rangeEnd)
{
	if (rangeEnd < rangeBegin)
	{
		Logger::LogToFile("Random: rangeBegin > rangeEnd, unexpected behavior may occure");
	}

	return rangeBegin + (rand() % (int)(rangeEnd - rangeBegin + 1));
}
