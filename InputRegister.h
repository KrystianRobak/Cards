#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include <map>
#include <functional>

class InputRegister
{
public:
     // Adjust the function pointer type
    InputRegister()
    {
        currentState = State::MAIN_MENU;
    }

	void ChangeState(State state) {
		currentState = state;
	}

	void RegisterInputKey(sf::Keyboard::Key key,std::function<void()> func ) {
		inputRegistry.insert(std::make_pair(key, func));
	}

    void CheckInput()
    {
        while (true) {
            for (std::map< sf::Keyboard::Key, std::function<void()>>::iterator it = inputRegistry.begin(); it != inputRegistry.end(); it++) {
                if (sf::Keyboard::isKeyPressed(it->first)) {
                    it->second();
                }
            }
        }
    }
private:
    State currentState;
    std::map<sf::Keyboard::Key,std::function<void()>> inputRegistry;

};

