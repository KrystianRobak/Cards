#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include "GraphicHandler.h"
#include "InputHandler.h"
#include "Task.h"
#include "Server.h"
#include "Enums.h"

class Client
{
private:
	State state;
	GraphicHandler graphicHandler;
	InputHandler inputHandler;
	sf::RenderWindow window;
	std::queue<Task> graphicTaskInput;
	std::queue<Task> graphicTaskOutput;

	std::queue<Task> inputTaskInput;
	std::queue<Task> inpuTaskOutput;

public:
	Client(std::string name) : window(sf::VideoMode(800, 600), "Not Tetris"), graphicHandler(window), inputHandler(window){
		this->state = State::MAIN_MENU;
	}

	void Run() {
		Init();
	}

	std::unique_ptr<Server> CreateServer() {
		return std::make_unique<Server>();
	}

	void Init() {
		sf::Thread thread(&GraphicHandler::Render, &graphicHandler);
		thread.launch();
		sf::Thread thread2(&InputHandler::CheckInput, &inputHandler);
		thread2.launch();
	}
};

