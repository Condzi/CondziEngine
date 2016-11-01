#pragma once
#include "Engine/Managing/State.hpp"

namespace ce
{
	// State Machine
	// (used by Game class)
	// Starting state should be Menu 
	// Usually staring state number - 0
	class StateMachine
	{
	public:
		// StateMachine constructor (default)
		// stateToStart = 0	- number of state to start
		StateMachine(unsigned short stateToStart = 0);

		void AddState(unsigned short id, State * state);

		void Run();

	private:
		unsigned short m_currentState;
		std::map< unsigned short, State* > m_states;
	};
}