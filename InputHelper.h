#ifndef INPUTHELPER_H
#define INPUTHELPER_H
#include <SFML/Graphics.hpp>

class InputHelper
{
private:
	char m_input;	
public:
	
	void handleEvents(sf::RenderWindow *window);

	int isKeyPressed();
	
	int getInputChar();
};

#endif // !INPUTHELPER
