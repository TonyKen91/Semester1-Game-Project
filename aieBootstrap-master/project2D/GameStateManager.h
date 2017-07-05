#pragma once
#include "GameState.h"
#include <vector>
#include "Renderer2D.h"
#include <iostream>
#include "Input.h"
#include "MyVector.h"

enum class eGameState {
	SPLASH,
	MENU,
	LEVELSELECT,
	INGAME,
	PAUSE,
	INSTRUCTIONS,
	OPTIONS,
	HIGHSCORELIST,
	STATE_COUNT
};

class GameStateManager {
public:
	GameStateManager(unsigned int stateCount) {
		m_registeredStates.resize(stateCount);
	}
	~GameStateManager() {
		for (auto state : m_registeredStates) delete state;
	}

	void registerState(int id, GameState* state);
	void pushState(int id);
	void popState();







	void update(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();

		// pushes the next state into the stack
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
			pushState(m_stateStack.size());


		while (m_popState) 
		{
			m_popState = false;

			// deactivate previous top state
			m_stateStack.back()->exit();
			auto temp = m_stateStack.back();
			m_stateStack.popBack();
			temp->onPopped();


			// activate the one under the previous top state if it exists
			if (m_stateStack.empty() == false)
				m_stateStack.back()->enter();
		}


		for (auto pushedState : m_pushedStates) 
		{
			// deactivate previous top state
			if (m_stateStack.empty() == false)
				m_stateStack.back()->exit();

			// activate new top state
			pushedState->onPushed();
			m_stateStack.pushBack(pushedState);
			m_stateStack.back()->enter();
		}


		m_pushedStates.clear();

		for (auto state : m_stateStack)
		{		
			state->onUpdate(deltaTime);
		}
		
		m_nextState = m_stateStack.back()->getNextState();

		if (m_nextState != 0 && m_currentState != m_nextState)
		{
			m_currentState = m_nextState;
			pushState(m_currentState);
		}
	}

	void draw(aie::Renderer2D* renderer) {
		// draw from the bottom of the stack up
		m_stateStack.back()->onDraw(renderer);
	}


	int activeStateCount() const { return m_stateStack.size(); }
	GameState* getTopState() const { return m_stateStack.back(); }
	GameState* getState(int id) const {
		return m_registeredStates[id];
	}

private:
	std::vector<GameState*> m_pushedStates;
	bool m_popState = false;
	int m_currentState = 0;
	int m_nextState = 0;


	// change these into custom containers
	MyVector<GameState*> m_stateStack;
	MyVector<GameState*> m_registeredStates;
};

