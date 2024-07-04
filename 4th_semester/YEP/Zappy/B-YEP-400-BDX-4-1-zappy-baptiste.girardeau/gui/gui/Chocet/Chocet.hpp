/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Socket.hpp
*/

#pragma once

#include <istream>
#include <sys/socket.h>

#include "ChocetBuffer.hpp"

namespace chocet {
class Chocet : public std::iostream {
   public:
    explicit Chocet(int fd);
    Chocet(int domain, int type, int protocol);

    Chocet(const Chocet &) = delete;
    Chocet(Chocet &&oth) noexcept;

    Chocet &operator=(const Chocet &) = delete;
    Chocet &operator=(Chocet &&oth) noexcept;

    ~Chocet() override;

    ChocetBuffer &sobuf();

    void connect(const sockaddr *addr, socklen_t addrlen) const;

   protected:
    int _fd;

   private:
    ChocetBuffer _buffer;
};

[[deprecated]] Chocet uconnect(const std::string &name, bool abstract = false);
}  // namespace chocet
