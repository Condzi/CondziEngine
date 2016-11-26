#include "Engine/Managing/StateMachine.hpp"

ce::StateMachine::StateMachine(unsigned short stateToStart)
{
	m_currentState = stateToStart;
}

ce::StateMachine::~StateMachine()
{
	Logger::Log("StateMachine: (destructor) trying to delete " + std::to_string(m_states.size()) + " states", Logger::MessageType::Info, Logger::Output::File);

	for (auto it = m_states.begin(); it != m_states.end(); ++it)
	{
		delete it->second;
	}
	
	Logger::Log("StateMaching: (destructor) StateMachine deleted", Logger::MessageType::Info, Logger::Output::File);
}

void ce::StateMachine::Run()
{
	CE_ASSERT(m_states.size(), "cannot run StateMachine, no states");

	int nextState = 0;
	bool stateFound = false;

	while (nextState != -1)
	{
		m_states[m_currentState]->onActivation();
		nextState = m_states[m_currentState]->Run();

		if (nextState != m_currentState)
		{
			m_states[m_currentState]->onDeactivation();

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
