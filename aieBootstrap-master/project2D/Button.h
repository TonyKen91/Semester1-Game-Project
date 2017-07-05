#pragma once
#include "Vector2.h"
#include "Renderer2D.h"
#include "Font.h"
#include <string>

class Button
{
public:
	//Button();															// default button constructor
	Button(float x, float y, float width, float height);				// sets the parameters of the button
	~Button();															// default button destructor
	void drawButton(aie::Renderer2D* renderer);							// draws the button
	bool isButtonHighlighted(float mouseX, float mouseY);				// returns a bool if the button is highlighted or not
	void setNameAndState(std::string buttonName, int stateID);			// sets the name of button and the state the current button signifies
	int getNextState();													// returns the next state that the button signifies
	void buttonUpdate(float x, float y, float width, float height);		// function is useful if the user wants a dynamic button

private:
	aie::Font* m_font;													// font of the button name

	std::string m_buttonName;											// button name
	int m_nextState = 0;												// specifies the next state when the button is pressed

	float m_x, m_y;														// the position of the button
	float m_width, m_height;											// the height and width of the button

	float m_minX, m_maxX;												// used to detect the x limits of the button for colliding with the mouse
	float m_minY, m_maxY;												// used to detect the y limits of the button for colliding with the mouse
};

