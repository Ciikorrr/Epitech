/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Socket.cpp
*/

#include "Chocet.hpp"

#include <iostream>
#include <sys/un.h>
#include <unistd.h>
#include <utility>

#include "ChocetExceptions.hpp"

namespace chocet {
Chocet::Chocet(const int fd) : _fd{fd}, _buffer{fd}
{
    std::iostream::rdbuf(&_buffer);
}

Chocet::Chocet(const int domain, const int type, const int protocol)
    : Chocet{[&] {
          const int sockfd = socket(domain, type, protocol);
          if (sockfd == -1) {
              throw CreationChocetError{errno};
          }
          return sockfd;
      }()}
{}

Chocet::Chocet(Chocet &&oth) noexcept : _fd{oth._fd}, _buffer{std::move(oth._buffer)}
{
    std::iostream::rdbuf(&_buffer);
}

Chocet &Chocet::operator=(Chocet &&oth) noexcept
{
    if (this != &oth) {
        _buffer = std::move(oth._buffer);
        _fd = std::exchange(oth._fd, -1);
        std::iostream::rdbuf(&_buffer);
    }
    return *this;
}

Chocet::~Chocet()
{
    if (_fd != -1) {
        close(_fd);
        return;
    }
    std::clog << "Cringe\n";
}

ChocetBuffer &Chocet::sobuf()
{
    return _buffer;
}

void Chocet::connect(const sockaddr *addr, const socklen_t addrlen) const
{
    if (::connect(_fd, addr, addrlen) == -1) {
        throw ConnectionChocetError{errno};
    }
}
}  // namespace chocet
