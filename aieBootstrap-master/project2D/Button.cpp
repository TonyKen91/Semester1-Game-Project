#include "Button.h"

//Button::Button()
//{
//	m_x = m_y = m_width = m_height = 0;
//	m_minX = m_maxX = m_minY = m_maxY = 0;
//}

Button::Button(float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f) : m_x(x), m_y(y), m_width(width), m_height (height)
{
	m_minX = x - width / 2;
	m_maxX = x + width / 2;
	m_minY = y - height / 2;
	m_maxY = y + height / 2;
	m_font = new aie::Font("./font/consolas.ttf", 32);
}

Button::~Button()
{
}

void Button::drawButton(aie::Renderer2D* renderer)
{
	// either draw it by texture or by boxes
	// for now just using the box command
	const char* word = m_buttonName.c_str();
	renderer->setRenderColour(1, 0, 0, 1);
	renderer->drawBox(m_x, m_y, m_width, m_height);
	renderer->setRenderColour(1, 1, 1, 1);
	renderer->drawText(m_font, word, m_minX + 10, m_y);
}

bool Button::isButtonHighlighted(float mouseX, float mouseY)
{
	if (mouseX >= m_minX && mouseX <= m_maxX &&
		mouseY >= m_minY && mouseY <= m_maxY)
		return true;
	else
		return false;
}

void Button::buttonUpdate(float x, float y, float width, float height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_minX = x - width / 2;
	m_maxX = x + width / 2;
	m_minY = y - height / 2;
	m_maxY = y + height / 2;

}

void Button::setNameAndState(std::string buttonName, int stateID)
{
	m_buttonName = buttonName;
	m_nextState = stateID;
}

int Button::getNextState()
{
	return m_nextState;
}
