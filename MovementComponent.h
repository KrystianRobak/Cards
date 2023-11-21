#pragma once
#include "InputRegister.h"
template <typename T>
class MovementComponent
{
	
	
public:
	InputRegister inputRegister;
	MovementComponent() {
	}

	void BindKey(sf::Keyboard::Key key, std::function<void()> func) {
		inputRegister.RegisterInputKey(key, func);
	}
};

