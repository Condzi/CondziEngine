#include "Managing/StateManager.hpp"

ce::StateManager::StateManager(unsigned short stateToStart)
{
	m_currentState = stateToStart;
}

void ce::StateManager::AddSate(unsigned short id, State * state, ce::ErrorCode::StateManager * errCode)
{
	for (auto it = m_states.begin(); it != m_states.end(); ++it)
	{
		if (it->first == id)
		{
			if (errCode != nullptr)
			{
				*errCode = ErrorCode::StateManager::ADD_SAME;
			}

			return;
		}
	}

	m_states[id] = state;
}

void ce::StateManager::Run(ce::ErrorCode::StateManager * errCode)
{
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

			if (errCode != nullptr)
			{
				*errCode = ErrorCode::StateManager::STATE_NOT_FOUND;
			}

			// Pooping to menu or somewhere
			nextState = 0;
		}
	}
}
