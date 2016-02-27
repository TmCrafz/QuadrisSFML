#ifndef INPUTHELPER_H
#define INPUTHELPER_H
#include <SFML/Graphics.hpp>

class InputHelper
{
private:
	char m_input;
	// True when player paused the game by pressing pause key, 
	// not affected from focus change of window
	bool m_pausedByPlayer;
public:

	InputHelper();

	void handleEvents(sf::RenderWindow *window);

	int isKeyPressed();
	
	int getInputChar();
};

#endif // !INPUTHELPER
