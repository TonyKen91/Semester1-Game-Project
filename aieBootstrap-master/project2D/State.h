#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Vector3.h"
#include <iostream>
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "AlienBlobs.h"
#include "Input.h"
#include "Button.h"
#include "MyVector.h"
#include "Texture.h"
#include "MyList.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <assert.h>
class SplashState : public GameState
{
public:
	SplashState() {}
	virtual ~SplashState() {}

	virtual void onUpdate(float deltaTime)
	{
		m_stateTimer += deltaTime;
		if (m_active)
		{
			if (m_stateTimer >= 1.0f)
				m_nextState = (int)eGameState::MENU;
		}
	
	}
	virtual void onDraw(aie::Renderer2D* renderer) 
	{
		renderer->setRenderColour(1, 1, 1, 1);
		renderer->drawText(m_font, "Splash Screen  ^_^", m_windowWidth / 2.0f, m_windowHeight / 2.0f - 100);
		renderer->drawBox(m_windowWidth/2.0f, 50, 20, 30);
	}

}; 
class MenuState : public GameState
{
public:
	MenuState() {}
	virtual ~MenuState() {}
	virtual void onEnter()
	{
		m_stateTimer = 0.0f;
		for (int i = 0; i < buttonCount; i++)
		{
			std::shared_ptr<Button> newButton(new Button(m_windowWidth / 2.0f, (m_windowHeight/((float)buttonCount+2))*((float)i + 1), m_windowWidth / 5.0f, m_windowHeight / 8.0f));
			
			// Having a hard time trying not to hard code the list
			// Everything is set to In Game state since the rest are under construction
			switch (i) 
			{
			case 0: newButton->setNameAndState("Single Player", (int)eGameState::INGAME);break;
			case 1: newButton->setNameAndState("Multiplayer", (int)eGameState::INGAME);break;
			case 2: newButton->setNameAndState("Instructions", (int)eGameState::INGAME);break;
			case 3: newButton->setNameAndState("Options", (int)eGameState::INGAME);break;
			case 4: newButton->setNameAndState("Highscore List", (int)eGameState::INGAME);break;
			}
			listOfButtons.pushBack(newButton);
		}
	}



	virtual void onUpdate(float deltaTime) 
	{ 

		m_stateTimer += deltaTime;
		// input instance
		aie::Input* input = aie::Input::getInstance();

		for (int i = 0; i < buttonCount; i++)
		{
			listOfButtons[i]->buttonUpdate(m_windowWidth / 2.0f, (m_windowHeight / ((float)buttonCount + 2))*(buttonCount - (float)i + 1), m_windowWidth / 5.0f, m_windowHeight / 8.0f);
			m_mouseX = (float)input->getMouseX();
			m_mouseY = (float)input->getMouseY();
			if (listOfButtons[i]->isButtonHighlighted(m_mouseX, m_mouseY) && input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
				m_nextState = listOfButtons[i]->getNextState();
		}

	}
	virtual void onDraw(aie::Renderer2D* renderer) 
	{
		renderer->setRenderColour(1, 0, 1, 1);
		for (int i = 0; i < listOfButtons.size(); i++)
			listOfButtons[i]->drawButton(renderer);
	}

private:
	MyVector<std::shared_ptr<Button>> listOfButtons;
	float m_mouseX, m_mouseY;
	int buttonCount = 5;
};

class LevelSelectState : public GameState
{
public:
	LevelSelectState() {}
	virtual ~LevelSelectState() {}

	virtual void onUpdate(float deltaTime) {
	}
	virtual void onDraw(aie::Renderer2D* renderer)
	{
		renderer->setRenderColour(1, 0, 0, 1);
		renderer->drawCircle(200, 220, 10);
	}
};

class InGameState : public GameState
{
public:
	InGameState() {}
	virtual ~InGameState() {}

	virtual void onEnter() {
		m_stateTimer = 0.0f;

		// creating game object factory
		m_gameObjectFactory = std::unique_ptr<GameObjectFactory>(new GameObjectFactory());

		// creating game object and adding them to the game object factory
		std::shared_ptr<GameObject> ship(new GameObject("ship", "./textures/ship.png"));
		std::shared_ptr<AlienBlob> aliens(new AlienBlob("alienBlob", "./textures/ship.png"));

		m_gameObjectFactory->addPrototype(ship);
		m_gameObjectFactory->addPrototype(aliens);

		m_font = new aie::Font("./font/consolas.ttf", 32);

	}

	virtual void onUpdate(float deltaTime) {
		m_stateTimer += deltaTime;
		// input instance
		aie::Input* input = aie::Input::getInstance();

		// creates a new instance of an alien blob when mouse is pressed on screen
		if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			m_mouseX = (float)input->getMouseX();
			m_mouseY = (float)input->getMouseY();
			std::shared_ptr <IPrototype> alienSpawn;
			alienSpawn = m_gameObjectFactory->create("alienBlob");
			assert(alienSpawn != nullptr && "Error Alien Spawn is a nullptr");
			std::shared_ptr <AlienBlob> alien = std::dynamic_pointer_cast<AlienBlob>(alienSpawn);
			
			// initialises alien parameters
			alien->setPos(m_mouseX, m_mouseY);
			alien->setVel(0.0f, 0.0f);
			alien->setAcc(0.0f, -9.8f*10);
			m_alienColony.pushBack(alien);
		}
		if (m_alienColony.empty() != true)
		{
			for (auto it = m_alienColony.begin(); it != m_alienColony.end(); )
			{
				it->value->update(deltaTime, m_windowWidth, m_windowHeight);
				it = it->nextNode;
			}
		}
	}
	virtual void onDraw(aie::Renderer2D* renderer) {
		if (m_alienColony.empty() != true)
		{
			for (auto it = m_alienColony.begin(); it != m_alienColony.end(); )
			{
				it->value->draw(renderer);
				it = it->nextNode;
			}
		}
		renderer->drawText(m_font, "Press esc to exit", 200, m_windowHeight-20);
		renderer->drawText(m_font, "Press on the window to summon balls", 200, m_windowHeight - 40);
	}
private:
	float m_mouseX, m_mouseY;
	std::unique_ptr<GameObjectFactory> m_gameObjectFactory;
	MyList<std::shared_ptr<AlienBlob> > m_alienColony;

};

class PauseState : public GameState
{
public:
	PauseState() {}
	virtual ~PauseState() {}

	virtual void onUpdate(float deltaTime) {
	}
	virtual void onDraw(aie::Renderer2D* renderer) {}
};

class InstructionsState : public GameState
{
public:
	InstructionsState() {}
	virtual ~InstructionsState() {}

	virtual void onUpdate(float deltaTime) {
	}
	virtual void onDraw(aie::Renderer2D* renderer)
	{
		renderer->setRenderColour(1, 0, 0, 1);
		renderer->drawCircle(200, 220, 10);
	}
};

class OptionsState : public GameState
{
public:
	OptionsState() {}
	virtual ~OptionsState() {}

	virtual void onUpdate(float deltaTime) {
	}
	virtual void onDraw(aie::Renderer2D* renderer)
	{
		renderer->setRenderColour(1, 0, 0, 1);
		renderer->drawCircle(200, 220, 10);
	}
};

class HighscoreListState : public GameState
{
public:
	HighscoreListState() {}
	virtual ~HighscoreListState() {}

	virtual void onUpdate(float deltaTime) {
	}
	virtual void onDraw(aie::Renderer2D* renderer)
	{
		renderer->setRenderColour(1, 1, 1, 1);
		renderer->drawText(m_font, "Highscore List", m_windowWidth / 2.0f, m_windowHeight - 100.0f);
	}
private:

};

