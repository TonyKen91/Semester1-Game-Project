#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "GameStateManager.h"
#include "State.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include <memory>
#include <list>



class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	GameStateManager gameStateManager = {(int)eGameState::STATE_COUNT};

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	float m_cameraX, m_cameraY;
	float m_timer;
};