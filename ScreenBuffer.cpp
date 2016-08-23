#include "ScreenBuffer.h"

using namespace std;

ScreenBuffer::ScreenBuffer(const int screenWidth, const int screenHeight):
m_BufferHeight(screenHeight),
m_BufferWidth(screenWidth),
// Allocate the memory for the 2d array
m_screenBuffer(new char *[m_BufferHeight]),
// In the Terminal the height of a row is more then a field is wide,
// so we have to increase the height
m_window(sf::VideoMode(/*800, 600*/screenWidth * 10, (screenHeight * 10) * 2) , "Quadris", 
		sf::Style::Titlebar | sf::Style::Close),
m_backgroundColor(sf::Color::Black)
{
	for (int i = 0; i != m_BufferHeight; i++)
	{
		m_screenBuffer[i] = new char[m_BufferWidth];	
	}
	if (!m_font.loadFromFile("Fonts/UbuntuMono-R.ttf"))
	{
		cout << "Error cannot load Font" << endl;
	}
	m_text.setFont(m_font);
	m_text.setCharacterSize(20);
	m_text.setFillColor(sf::Color::White);

}

ScreenBuffer::~ScreenBuffer()
{
	// Free the memory of the screenBuffer
	for (int i = 0; i != m_BufferHeight; i++)
	{
		delete[] m_screenBuffer[i];
	}
	delete[] m_screenBuffer;
}

int ScreenBuffer::getHeight() const
{
	return m_BufferHeight;
}

int ScreenBuffer::getWidth() const
{
	return m_BufferWidth;
}

void ScreenBuffer::add(const int X, const int Y, const char C)
{
	if (isInBufferArea(X, Y))
	{
		m_screenBuffer[Y][X] = C;
	}
}

void ScreenBuffer::add(const int StartX, const int StartY, const string Text)
{
	for (size_t x = StartX; x != StartX + Text.length(); x++)
	{
		if (isInBufferArea(x, StartY))
		{
			m_screenBuffer[StartY][x] = Text[x - StartX];	
		}
	}
}

void ScreenBuffer::changeBackground()
{
	if (m_backgroundColor == sf::Color::Black)
	{
		m_backgroundColor = sf::Color(44,0,30,0);
	}
	else
	{
		m_backgroundColor = sf::Color::Black;
	}
}

void ScreenBuffer::clear()
{
	//m_window.clear(sf::Color(44,0,30,0));
	//m_window.clear(sf::Color::Black);
	m_window.clear(m_backgroundColor);
	for (int y = 0; y != m_BufferHeight; y++)
	{
		for (int x = 0; x != m_BufferWidth; x++)
		{
			m_screenBuffer[y][x] = ' ';
		}	
	}
}

void ScreenBuffer::display() 
{
	for (int y = 0; y != m_BufferHeight; y++)
	{
		for (int x = 0; x != m_BufferWidth; x++)
		{
			m_text.setPosition(x * 10, y * 20);
			m_text.setString(m_screenBuffer[y][x]);
			m_window.draw(m_text);
		}	
	}
	m_window.display();
	
}

sf::RenderWindow * ScreenBuffer::getWindow()
{
	return &m_window;
}

bool ScreenBuffer::isInBufferArea(const int X, const int Y) const
{
	return (X >= 0 && X < m_BufferWidth && Y >= 0 && Y < m_BufferHeight);
}
