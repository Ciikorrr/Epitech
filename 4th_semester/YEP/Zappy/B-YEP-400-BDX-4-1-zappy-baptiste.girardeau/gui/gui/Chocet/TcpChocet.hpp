/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TcpSocket.hpp
*/

#pragma once

#include <netinet/in.h>
#include <sys/socket.h>

#include "Chocet.hpp"

namespace chocet {
class TcpChocet : public Chocet {
   public:
    explicit TcpChocet();

    TcpChocet(const TcpChocet &) = delete;
    TcpChocet(TcpChocet &&oth);

    TcpChocet &operator=(const TcpChocet &) = delete;
    TcpChocet &operator=(TcpChocet &&oth);

    ~TcpChocet() override = default;

    void connect(const std::string &address, uint16_t port) const;
};
}  // namespace chocet
