// CardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Client.h"
#include "Game.h"

int main()
{
	std::unique_ptr<Client> client = std::make_unique<Client>("Siema");

	client->Run();

	return 0;
}

