#pragma once

#define _DEBUG_

#include <iostream>
#include <fstream>
#include <string>

namespace ce
{
	namespace Logger
	{
		// Message type
		enum class MessageType
		{
			AssertError = 0,
			Error,
			Warning,
			Info
		};

		// Output 
		enum class Output
		{
			All = 0,
			File,
			Console
		};

		// Saves message to specified output.
		// msg		- message
		// type		- type of message (error, warning, info)
		// output	- where save message
		void Log(const std::string & msg, MessageType type, Output output);

		// Internal log methods
		namespace LoggerInternal
		{
			static unsigned int messageCounter = 0;

			// Saves message to log.txt file.
			// msg	- message
			// type - type of message (error, warning, info)
			void logToFile(const std::string & msg, MessageType type);

			// Prints message to console.
			// msg	- message
			// type	- type of message (error, warning, info)
			void logToConsole(const std::string & msg, MessageType type);
		}
	}
}

