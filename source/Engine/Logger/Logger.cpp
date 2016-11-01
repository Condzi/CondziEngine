#include "Engine/Logger/Logger.hpp"


void ce::Logger::LogToFile(const std::string & msg, MessageType type)
{
#ifdef _DEBUG_

	static std::ofstream logFile;
	char prefix = ' ';

	switch (type)
	{
	case MessageType::AssertError:	prefix = 'A'; break;
	case MessageType::Error:		prefix = 'X'; break;
	case MessageType::Warning:		prefix = '!'; break;
	case MessageType::Info:			prefix = 'i'; break;
	}

	if (!logFile.is_open())
	{
		logFile.open("log.txt");
		logFile << "";
		logFile.close();

		logFile.open("log.txt", std::ios::app);
	}

	logFile << "[" << prefix <<"] " << msgCounter << ": "<< msg << "\n";

	++msgCounter;

#endif
}

void ce::Logger::LogToConsole(const std::string & msg, MessageType type)
{
#ifdef _DEBUG_

	char prefix = ' ';

	switch (type)
	{
	case MessageType::AssertError:	prefix = 'A'; break;
	case MessageType::Error:		prefix = 'X'; break;
	case MessageType::Warning:		prefix = '!'; break;
	case MessageType::Info:			prefix = 'i'; break;
	}

	std::cout << "[" << prefix << "] " << msgCounter << ": " << msg << "\n";
	
	++msgCounter;

#endif
}

void ce::Logger::LogToBoth(const std::string & msg, MessageType type)
{
	LogToFile(msg, type);
	// To make id in file and console match
	--msgCounter;
	LogToConsole(msg, type);
}

