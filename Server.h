#pragma once

#include <queue>
#include <iostream>
#include <SFML/Network.hpp>
#include <list>

class Server
{
public:
	bool enabled;
	sf::SocketSelector selector;
	sf::TcpListener listener;

	std::list<std::unique_ptr<sf::TcpSocket>> clients;
	//std::queue<Task> taskInput;
	//std::queue<Task> taskOutput;
	Server();
	void Run();
	//void ParsePacket(sf::Packet);
};

