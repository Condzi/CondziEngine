#include "Engine/Logger/Logger.hpp"

void ce::Logger::Log(const std::string & msg, MessageType type, Output output)
{
#ifdef _DEBUG_

	switch (output)
	{
	case ce::Logger::Output::All:
		internal::logToConsole(msg, type);
		// To make id in file and console match
		--msgCounter;
		internal::logToFile(msg, type);
		break;
	case ce::Logger::Output::File:
		internal::logToFile(msg, type);
		break;
	case ce::Logger::Output::Console:
		internal::logToConsole(msg, type);
		break;
	}

#endif // _DEBUG_
}

void ce::Logger::internal::logToFile(const std::string & msg, MessageType type)
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

void ce::Logger::internal::logToConsole(const std::string & msg, MessageType type)
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

