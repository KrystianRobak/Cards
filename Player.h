#pragma once
#include "MovementComponent.h"

	class Player
	{
	
	public:
		MovementComponent<Player> playerMovement;
		Player() {
			playerMovement.BindKey(sf::Keyboard::F, [this]() { PressedF(); });
		}

		void PressedF() {
			std::cout << "F was pressed" << std::endl;
		}
	};

