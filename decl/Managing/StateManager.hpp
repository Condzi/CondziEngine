#pragma once
#include <map>
#include "Managing/State.hpp"
#include "ErrorCodes.hpp"

namespace ce
{
	class StateManager
	{
	public:
		StateManager(unsigned short stateToStart = 1);

		void AddSate(unsigned short id, State * state, ErrorCode::StateManager * errCode = nullptr);

		void Run(ErrorCode::StateManager * errCode = nullptr);

	private:
		unsigned short m_currentState;
		std::map< unsigned short, State* > m_states;
	};
}