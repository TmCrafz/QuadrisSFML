#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H
#include <iostream>
#include <SFML/Graphics.hpp>

class ScreenBuffer
{
private:
	const int m_BufferHeight;
	const int m_BufferWidth;
	// Store the chars which get drawn in drawToScreen method
	char **m_screenBuffer;
	
	sf::RenderWindow m_window;
	
	sf::Color m_backgroundColor;

	sf::Font m_font;
	sf::Text m_text;


public:
	ScreenBuffer(const int screenWidth, const int screenHeight);

	~ScreenBuffer();
		
	int getHeight() const;

	int getWidth() const;

	void add(const int X, const int Y, const char C);

	void add(const int StartX, const int StartY, const std::string Text);
		
	void changeBackground();

	void clear();
	
	// Display all drawn things on Screen
	void display();

	sf::RenderWindow * getWindow();

private:

	// Only true when the position is in screen area
	bool isInBufferArea(const int X, const int Y) const;


};


#endif // !SCREENBUFFER_H
