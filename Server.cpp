#include "Server.h"

Server::Server() {
	this->enabled = true;
	this->listener.listen(55001);
}


void Server::Run() {
	while (this->enabled) {
		if (this->selector.wait()) {
			if (this->selector.isReady(this->listener)) {
				std::unique_ptr<sf::TcpSocket> client = std::make_unique<sf::TcpSocket>();
				if (this->listener.accept(*client) == sf::Socket::Done) {
					clients.push_back(std::move(client));
					selector.add(*client);
				}
				else client.release();
			}
			else {
				for (auto& client : clients) {
					if (selector.isReady(*client)) {
						sf::Packet packet;
						if (client->receive(packet) == sf::Socket::Done) {
							//this->ParsePacket(packet);
						}
					}
				}
			}
		}
	}
}