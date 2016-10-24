#include "Debug\Debug.hpp"


void ce::Logger::LogToFile(const std::string & msg)
{
#ifdef DEBUG_LOG

	std::ofstream logFile;
	static unsigned int msgCounter = 0;

	if (!logFile.is_open())
	{
		logFile.open("log.txt");
		logFile << "";
		logFile.close();

		logFile.open("log.txt", std::ios::app);
	}

	logFile << msgCounter << ": "<< msg << "\n";

	++msgCounter;
#endif
}

