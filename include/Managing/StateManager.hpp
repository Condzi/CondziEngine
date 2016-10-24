#pragma once
#include <map>
#include "Managing/State.hpp"
#include "Debug/Debug.hpp"

namespace ce
{
	class StateManager
	{
	public:
		StateManager(unsigned short stateToStart = 1);

		void AddSate(unsigned short id, State * state);

		void Run();

	private:
		unsigned short m_currentState;
		std::map< unsigned short, State* > m_states;
	};
}