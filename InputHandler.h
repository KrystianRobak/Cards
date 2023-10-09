#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enums.h"

class InputHandler
{
private:
	sf::RenderWindow& window_;
	State currentState;
public:

	InputHandler(sf::RenderWindow& window) : window_(window) {
		currentState = State::MAIN_MENU;
	}

	void ChangeState(State state) {
		currentState = state;
	}

	void CheckInput() {
		while (window_.isOpen()) {

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				std::cout << sf::Mouse::getPosition().x << " | " << sf::Mouse::getPosition().y << std::endl;
			}
		}
	}
};

