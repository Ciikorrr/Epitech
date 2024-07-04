/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** UnixChocet.cpp
*/

#include "UnixChocet.hpp"

#include <sys/un.h>

namespace chocet {
UnixChocet::UnixChocet(const std::string &address, bool abstract) : Chocet{AF_UNIX, SOCK_STREAM, 0}
{
    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;
    size_t len{};

    if (abstract) {
        len = address.copy(&addr.sun_path[1], sizeof(addr.sun_path) - 1) + 1;
    } else {
        len = address.copy(&addr.sun_path[0], sizeof(addr.sun_path));
    }
    socklen_t addrlen = offsetof(sockaddr_un, sun_path) + len;

    connect(reinterpret_cast<const sockaddr *>(&addr), addrlen);
}
}  // namespace chocet
