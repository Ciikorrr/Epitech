/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Client
*/

#pragma once

#include <cstdint>
#include <string>

#include "gui/Chocet/TcpChocet.hpp"
#include "gui/Client/Event.hpp"
#include "gui/Client/State.hpp"

namespace zizi::client {

class ZappyClient final {
   public:
    ZappyClient(const std::string &address, uint16_t port);

    void listen();
    void requestMapSize();

    State copyState();
    std::vector<Event> getEvents();

   private:
    chocet::TcpChocet _socket;

    State _state;
    EventQueue<Event> _events;
    std::mutex _stateMutex;
};

}  // namespace zizi::client
