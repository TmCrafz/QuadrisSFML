#ifndef INPUTHELPER_CPP
#define INPUTHELPER_CPP

#include <termios.h>
#include <iostream>
#include <cstring>
#include "InputHelper.h"

using namespace std;

void InputHelper::handleEvents(sf::RenderWindow *window)
{
	m_input = '\0';
	sf::Event event;
	while(window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			m_input = 'c';
			window->close();
			break;
		case sf::Event::TextEntered:
			cout << "Enterd Text unicode: " << event.text.unicode << endl;
			m_input = static_cast<char>(event.text.unicode);
			// If the player press the backspace (enter key)
			// handle it like a next line in terminal
			if (m_input == 13)
			{
				m_input = '\n';
			}
			// Handle a backspace press as Delete
			else if (m_input == 8)
			{
				m_input = 127;			
			}
			break;		
		case sf::Event::KeyPressed:
			break;
		}

	}
}

int InputHelper::isKeyPressed()
{	
	return m_input != '\0';
}

int InputHelper::getInputChar()
{
	return m_input;
}

#endif // !INPUTHELPER_CPP
