#include "Managing/StateManager.hpp"

ce::StateManager::StateManager(unsigned short stateToStart)
{
	m_currentState = stateToStart;
}

void ce::StateManager::AddSate(unsigned short id, State * state)
{
	for (auto it = m_states.begin(); it != m_states.end(); ++it)
	{
		if (it->first == id)
		{
			Logger::LogToFile("StateManager: Cannot add state, found same state name!");
			return;
		}
	}

	m_states[id] = state;
}

void ce::StateManager::Run()
{
	if (!m_states.size())
	{
		Logger::LogToFile("StateManager: Cannot run, no states!");
		return;
	}

	int nextState = 0;

	while (nextState != -1)
	{
		nextState = m_states[m_currentState]->Run();

		if (nextState != m_currentState)
		{
			for (auto it = m_states.begin(); it != m_states.end(); ++it)
			{
				if (it->first == nextState)
				{
					m_currentState = nextState;
					break;
				}
			}

	
			// Pooping to menu or somewhere
			m_currentState = 0;

			Logger::LogToFile("StateManager: Cannot switch states, switching to " + std::to_string(m_currentState) + "!");
		}
	}
}
