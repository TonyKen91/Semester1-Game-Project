#include "GameStateManager.h"


void GameStateManager::registerState(int id, GameState* state)
{
	m_registeredStates[id] = state;
}

void GameStateManager::pushState(int id) 
{
	m_pushedStates.push_back(m_registeredStates[id]);
}

void GameStateManager::popState()
{
	m_popState = true;
}