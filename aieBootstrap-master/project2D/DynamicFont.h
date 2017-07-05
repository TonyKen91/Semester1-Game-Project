#pragma once


#include <Font.h>

class DynamicFont
{
	DynamicFont(const char* path, float initialSize)
	{
		this->path = path;
		m_size = initialSize;
		rebuildFont();
	}

	aie::Font* getFont()
	{
		rebuildFont();
		return m_font;
	}

	void setSize(float size)
	{
		if (m_size != size)
		{
			m_needNewFont = true;
			m_size = size;
		}
	}

private:

	void rebuildFont()
	{
		if (m_needNewFont)
		{
			if (m_font != nullptr) delete m_font;
			m_font = new aie::Font(path, m_size);
			m_needNewFont = false;
		}
	}

	bool m_needNewFont = true;
	aie::Font* m_font = nullptr;

	float m_size;
	const char* path;
};