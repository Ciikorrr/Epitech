/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main.cpp
*/

#include <cstdint>
#include <iostream>
#include <span>
#include <thread>

#include "gui/Client/Client.hpp"
#include "gui/CommandParser.hpp"
#include "gui/Gui/Gui.hpp"

namespace {

constexpr int SUCCESS = 0;
constexpr int FAILURE = 84;

void run(const uint16_t port, const std::string &address)
{
    zizi::client::ZappyClient client(address, port);
    zizi::gui::Gui gui;
    std::thread clientThread([&] { client.listen(); });

    client.requestMapSize();
    while (gui.isOpen()) {
        gui.render(std::move(client.copyState()), client.getEvents());
    }

    pthread_cancel(clientThread.native_handle());
    clientThread.join();
}

}  // namespace

int main(const int argc, char *argv[])
{
    const std::span args{argv, static_cast<std::span<char *>::size_type>(argc)};

    zizi::CommandParser parser;

    try {
        parser = zizi::CommandParser{args};
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
        std::cerr << "Usage: zappy [-p port] [-h address]\n";
        return FAILURE;
    }

    try {
        auto [port, address] = parser.values();
        run(port, address);
        return SUCCESS;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
        return FAILURE;
    }
}
