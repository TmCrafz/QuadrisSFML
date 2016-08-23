#include <iostream>
#include <cstring>
#include "InputHelper.h"

using namespace std;

InputHelper::InputHelper():
m_input('\0'),
m_pausedByPlayer(false)
{
}

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
		case sf::Event::Resized:
			{
			// Do nothing
			//float width = window->getSize().x;
			//float height = window->getSize().y;
			//window->setView(sf::View(sf::FloatRect(0, 0, width, height))); 
			break;
			}
		case sf::Event::LostFocus:
			// Pause Game when lost focus, but only when the game is not allready
			// paused by the player
			if (!m_pausedByPlayer)
			{
				m_input = '0';
			}
			break;
		case sf::Event::GainedFocus:
			// Only stop pausing when the game is not paused by player input,
			// only when paused by losing window focus
			if (!m_pausedByPlayer)
			{
				m_input = '0';
			}
			break;
		case sf::Event::KeyReleased:
			// Do nothing
			break;
		case sf::Event::MouseWheelMoved:
			// Do nothing
			break;
		case sf::Event::MouseWheelScrolled:
			// Do nothing
			break;
		case sf::Event::MouseButtonPressed:
			// Do nothing
			break;
		case sf::Event::MouseButtonReleased:
			// Do nothing
			break;
		case sf::Event::MouseMoved:
			// Do nothing
			break;
		case sf::Event::MouseEntered:
			// Do nothing
			break;
		case sf::Event::MouseLeft:
			// Do nothing
			break;
		case sf::Event::JoystickButtonPressed:
			// Do nothing
			break;
		case sf::Event::JoystickButtonReleased:
			// Do nothing
			break;
		case sf::Event::JoystickMoved:
			// Do nothing
			break;
		case sf::Event::JoystickConnected:
			// Do nothing
			break;
		case sf::Event::JoystickDisconnected:
			// Do nothing
			break;
		case sf::Event::TouchBegan:
			// Do nothing
			break;
		case sf::Event::TouchMoved:
			// Do nothing
			break;
		case sf::Event::TouchEnded:
			// Do nothing
			break;
		case sf::Event::SensorChanged:
			// Do nothing
			break;
		case sf::Event::Count:
			// Do nothing
			break;
		case sf::Event::TextEntered:
			m_input = static_cast<char>(event.text.unicode);
			// If the player press the backspace (enter key)
			// handle it like a next line in terminal
			if (m_input == '0')
			{
				m_pausedByPlayer = !m_pausedByPlayer; 
			}
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
