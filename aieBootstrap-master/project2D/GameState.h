#pragma once
#include <vector>
#include "Renderer2D.h"
#include "Font.h"


class GameState
{
	friend class GameStateManager;
public:

	GameState() {}
	virtual ~GameState() {}
	bool isActive() const { return m_active; }											// returns state of the current state
	int getNextState() { return m_nextState; }											// returns the next state
	void setWindowParameters(const float& windowWidth, const float& windowHeight);		// set the window parameters
	bool toggleCursor() { return m_showCursor; }										// toggles the cursor on or off

protected:
	virtual void onUpdate(float deltaTime) = 0;											// update states
	virtual void onDraw(aie::Renderer2D* renderer) = 0;									// draw states

	void enter() { m_active = true; onEnter(); }
	void exit() { m_active = false; onExit(); }

	virtual void onEnter() { m_stateTimer = 0.0f; m_font = new aie::Font("./font/consolas.ttf", 32);}
	virtual void onExit() {}
	virtual void onPushed() {}
	virtual void onPopped() {}
	
	
	int m_nextState = 0;
	float m_stateTimer = 0.0f;
	aie::Font* m_font;

	// application object parameters
	bool m_quit = false;
	bool m_showCursor = true;
	float m_windowHeight = 0.0f;
	float m_windowWidth = 0.0f;

	bool m_active = false;

private:
};

