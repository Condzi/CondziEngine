#pragma once

#define DEBUG_LOG

#include <fstream>
#include <string>

namespace ce
{
	namespace Logger
	{
		// Message without \n and other formatting
		void LogToFile(const std::string & msg);
	}
}

