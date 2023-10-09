#pragma once
#include <SFML/Graphics.hpp>
#include <queue>

class Client
{
public:
	Client(std::string name) {
		std::string name;
		std::queue<Task> taskInput;
		std::queue<Task> taskOutput;
	}

	void Run() {
		InitGraphics();
	}

	void InitGraphics() {
		sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris");

		sf::Event event;

		while (window.isOpen()) {

			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {

					window.close();
				}
			}
		}
	}

	void CreateServer() {
		
	}
};

