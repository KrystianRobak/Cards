#pragma once

#include <queue>
#include <iostream>

class Server
{
public:
	Server(std::string name) {
		std::string name;
		std::queue<Task> taskInput;
		std::queue<Task> taskOutput;
	}
};

