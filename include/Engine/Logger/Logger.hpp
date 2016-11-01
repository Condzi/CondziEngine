#pragma once

#define _DEBUG_

#include <iostream>
#include <fstream>
#include <string>

namespace ce
{
	namespace Logger
	{
		namespace
		{
			static unsigned int msgCounter = 0;
		}

		// Message type
		enum class MessageType
		{
			AssertError = -1,
			Error,
			Warning,
			Info
		};

		// Saves message to log.txt file.
		// msg	- message
		// type - type of message (error, warning, info)
		void LogToFile(const std::string & msg, MessageType type);

		// Prints message to console.
		// msg	- message
		// type	- type of message (error, warning, info)
		void LogToConsole(const std::string & msg, MessageType type);

		// Prints message to console and saves to log.txt file.
		// msg	- message
		// type	- type of message (error, warning, info)
		void LogToBoth(const std::string & msg, MessageType type);
	}
}

