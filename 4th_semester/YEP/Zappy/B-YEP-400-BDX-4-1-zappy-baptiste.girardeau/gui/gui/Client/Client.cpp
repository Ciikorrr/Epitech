/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Client
*/

#include "Client.hpp"

#include <sstream>
#include <string>

#include "gui/Client/CommandHandler.hpp"

namespace zizi::client {

ZappyClient::ZappyClient(const std::string &address, const uint16_t port)
{
    std::string data;

    _socket.connect(address, port);
    std::getline(_socket, data);
    if (data != "WELCOME") {
        throw std::runtime_error("Invalid welcome message");
    }
    _socket << "GRAPHIC\n" << std::flush;
}

void ZappyClient::listen()
{
    std::string data;
    CommandHandler handler(_state, _events);

    while (std::getline(_socket, data)) {
        std::lock_guard lock(_stateMutex);
        std::istringstream input{data};
        std::string command;

        input >> command;
        handler.handleCommand(command, input);
    }
}

State ZappyClient::copyState()
{
    std::lock_guard lock(_stateMutex);
    return _state;
}

std::vector<Event> ZappyClient::getEvents()
{
    return _events.clear();
}

void ZappyClient::requestMapSize()
{
    _socket << "msz\n" << std::flush;
}

}  // namespace zizi::client
