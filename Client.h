#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include "GraphicHandler.h"
#include "Player.h"
#include "Task.h"
#include "Server.h"
#include "Enums.h"
#include <thread>

class Client
{
private:
	State state;
	GraphicHandler graphicHandler;
	Player player;
	sf::RenderWindow window;
	std::queue<Task> graphicTaskInput;
	std::queue<Task> graphicTaskOutput;

	std::queue<Task> inputTaskInput;
	std::queue<Task> inpuTaskOutput;

public:
	Client(std::string name) : window(sf::VideoMode(800, 600), "Not Tetris"), graphicHandler(window) {
		this->state = State::MAIN_MENU;
	}

	void Run() {
		Init();
	}

	std::unique_ptr<Server> CreateServer() {
		return std::make_unique<Server>();
	}

	void Init() {
		std::thread thread(&GraphicHandler::Render, &graphicHandler);
		std::thread thread2(&InputRegister::CheckInput, player.playerMovement.inputRegister);
		thread.join();
		thread2.join();
	}
};

