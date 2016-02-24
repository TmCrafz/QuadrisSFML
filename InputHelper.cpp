#ifndef INPUTHELPER_CPP
#define INPUTHELPER_CPP

#include <termios.h>
#include <iostream>
#include <cstring>
#include "InputHelper.h"

using namespace std;

int InputHelper::isKeyPressed()
{
	return 1;
}

// TMP
int InputHelper::getInputChar()
{
	int ch = '\0';
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return 'a';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return 'd';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return 'w';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return 's';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		return 'o';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		return 'p';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		return '0';
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		return '\n';

	return ch;
}

#endif // !INPUTHELPER_CPP
