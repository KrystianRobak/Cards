#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include <iostream>

class GraphicHandler
{
private:
	sf::RenderWindow& window_;
	State currentState;
public:

	GraphicHandler(sf::RenderWindow& window) : window_(window) {
		currentState = State::MAIN_MENU;
	}

	void ChangeState(State state) {
		currentState = state;
	}

	void Render() {
		sf::Event event;
		
		while (window_.isOpen()) {
			switch (currentState) {
				case State::MAIN_MENU:
					break;
				case State::MULTIPLAYER:
					break;
				case State::HOSTING:
					break;
				case State::JOINING:
					break;
				case State::GAME_SCENE:
					break;
			}
			while (window_.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {

					window_.close();
				}
			}
		}
	}
};

