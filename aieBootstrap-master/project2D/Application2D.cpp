#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameStateManager.h"
#include "State.h"
#include "GameObject.h"
#include <iostream>


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");


	// registers the different states in the game state stack
	gameStateManager.registerState((unsigned int)eGameState::SPLASH, new SplashState());
	gameStateManager.registerState((unsigned int)eGameState::MENU, new MenuState());
	gameStateManager.registerState((unsigned int)eGameState::LEVELSELECT, new LevelSelectState());
	gameStateManager.registerState((unsigned int)eGameState::INGAME, new InGameState());
	gameStateManager.registerState((unsigned int)eGameState::PAUSE, new PauseState());
	gameStateManager.registerState((unsigned int)eGameState::INSTRUCTIONS, new InstructionsState());
	gameStateManager.registerState((unsigned int)eGameState::OPTIONS, new OptionsState());
	gameStateManager.registerState((unsigned int)eGameState::HIGHSCORELIST, new HighscoreListState());

	// push the first state into the stack for initialisation
	gameStateManager.pushState((unsigned int) eGameState::SPLASH);

	// initialise the update of the first state
	gameStateManager.update(0);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();


	if (gameStateManager.activeStateCount() > 0)
	{
		float windowHeight = (float) getWindowHeight();
		float windowWidth = (float) getWindowWidth();
		gameStateManager.getTopState()->setWindowParameters(windowWidth, windowHeight);
		setShowCursor(gameStateManager.getTopState()->toggleCursor());
		gameStateManager.update(deltaTime);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	if (gameStateManager.activeStateCount() > 0)
	{
		float windowHeight = (float)getWindowHeight();
		float windowWidth = (float)getWindowWidth();
		gameStateManager.getTopState()->setWindowParameters(windowWidth, windowHeight);
		gameStateManager.draw(m_2dRenderer);
	}

	// done drawing sprites
	m_2dRenderer->end();
}