#include "Engine/Managing/StateMachine.hpp"

ce::StateMachine::StateMachine(unsigned short stateToStart)
{
	m_currentState = stateToStart;
}

void ce::StateMachine::AddState(unsigned short id, State * state)
{
	CE_ASSERT(state, "State is nullptr");

	for (auto it = m_states.begin(); it != m_states.end(); ++it)
	{
		if (it->first == id)
		{
			Logger::Log("StateMachine: Cannot add state, found same state id! ID: " + std::to_string(id), Logger::MessageType::Error, Logger::Output::All);
			return;
		}
	}

	m_states[id] = state;
}

void ce::StateMachine::Run()
{
	CE_ASSERT(m_states.size(), "cannot run StateMachine, no states");

	int nextState = 0;
	bool stateFound = false;

	while (nextState != -1)
	{
		nextState = m_states[m_currentState]->Run();

		if (nextState != m_currentState)
		{
			stateFound = false;
			for (auto it = m_states.begin(); it != m_states.end(); ++it)
			{
				if (it->first == nextState)
				{
					m_currentState = nextState;
					stateFound = true;
					break;
				}
			}

			if (!stateFound)
			{
				m_currentState = 0;

				Logger::Log("StateMachine: Cannot switch states, switching to " + std::to_string(m_currentState) + "!", Logger::MessageType::Warning, Logger::Output::Console);
			}
		}
	}
}
