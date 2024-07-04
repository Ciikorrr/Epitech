/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TcpChocet.cpp
*/

#include "TcpChocet.hpp"

#include <netdb.h>
#include <unistd.h>

#include "ChocetExceptions.hpp"

namespace chocet {
TcpChocet::TcpChocet() : Chocet{AF_INET6, SOCK_STREAM, 0}
{
    const int off = 0;
    setsockopt(_fd, IPPROTO_IPV6, IPV6_V6ONLY, &off, sizeof(off));
}

void TcpChocet::connect(const std::string &address, const uint16_t port) const
{
    addrinfo *result{};
    addrinfo hints{};
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_ALL | AI_V4MAPPED;

    if (const int err = getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &result);
        err)
    {
        throw std::runtime_error(gai_strerror(err));
    }

    for (const addrinfo *rp = result; rp != nullptr; rp = rp->ai_next) {
        try {
            Chocet::connect(rp->ai_addr, rp->ai_addrlen);
            freeaddrinfo(result);
            return;
        }
        catch (const ConnectionChocetError &e) {
            if (e.errnum() != ECONNREFUSED) {
                throw;
            }
        }
    }
    freeaddrinfo(result);
    throw ConnectionChocetError{EADDRNOTAVAIL};
}
}  // namespace chocet
