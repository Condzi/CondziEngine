// Condzi Engine Assert 
// Borrowed from https://github.com/fallahn/xygine

#pragma once
#include "Engine/Logger/Logger.hpp"
#include <sstream>

#ifdef _MSC_VER
#define __func__ __FUNCTION__
#endif //_MSC_VER

#ifdef _DEBUG_

// Condzi Engine Assert 
#define CE_ASSERT(condition, message) \
do \
{ \
    if(!(condition)) \
    { \
        std::stringstream ss; \
        ss << "Assertion failed in " << __FILE__ << ", function `" << __func__ << "`, line " << __LINE__ << ": " << message; \
        Logger::LogToBoth(ss.str(), ce::Logger::MessageType::AssertError); \
        abort(); \
    } \
}while (false)

#endif // _DEBUG_