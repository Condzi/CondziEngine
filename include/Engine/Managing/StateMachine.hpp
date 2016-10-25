#pragma once
#include <map>
#include "Engine/Managing/State.hpp"
#include "Engine/Logger/Logger.hpp"

namespace ce
{
	// First (1) state should be Menu
	class StateMachine
	{
	public:
		StateMachine(unsigned short stateToStart = 1);

		void AddState(unsigned short id, State * state);

		void Run();

	private:
		unsigned short m_currentState;
		std::map< unsigned short, State* > m_states;
	};
}