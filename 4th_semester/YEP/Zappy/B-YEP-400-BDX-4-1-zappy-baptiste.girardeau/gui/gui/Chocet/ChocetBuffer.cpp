/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ChocetBuffer.cpp
*/

#include "ChocetBuffer.hpp"

#include <cstring>
#include <iostream>
#include <sys/socket.h>

#include "ChocetExceptions.hpp"

namespace chocet {
ChocetBuffer::ChocetBuffer(const int fd) : _fd(fd)
{
    setg(
        _inbuffer.data() + PUTBACK_SIZE,
        _inbuffer.data() + PUTBACK_SIZE,
        _inbuffer.data() + PUTBACK_SIZE
    );
    setp(_outbuffer.data(), _outbuffer.data() + _outbuffer.size());
}

ChocetBuffer::ChocetBuffer(ChocetBuffer &&oth) noexcept : _fd(oth._fd), _inbuffer(oth._inbuffer)
{
    std::scoped_lock lock(oth._inbuffer_mutex, oth._outbuffer_mutex);
    setg(oth.eback(), oth.gptr(), oth.egptr());
}

ChocetBuffer &ChocetBuffer::operator=(ChocetBuffer &&oth) noexcept
{
    std::scoped_lock lock(
        _inbuffer_mutex, _outbuffer_mutex, oth._inbuffer_mutex, oth._outbuffer_mutex
    );
    if (this != &oth) {
        _fd = oth._fd;
        _inbuffer = oth._inbuffer;
        setg(oth.eback(), oth.gptr(), oth.egptr());
    }
    return *this;
}

ChocetBuffer::~ChocetBuffer() = default;

std::streambuf::int_type ChocetBuffer::underflow()
{
    std::scoped_lock lock(_inbuffer_mutex);
    const ssize_t n_pb = std::min(gptr() - eback(), static_cast<ssize_t>(PUTBACK_SIZE));

    std::memmove(_inbuffer.data() + PUTBACK_SIZE - n_pb, gptr() - n_pb, n_pb);
    const ssize_t n_read = recv(_fd, _inbuffer.data() + PUTBACK_SIZE, BUFFER_SIZE, _rflags);
    if (n_read == -1) {
        setg(
            _inbuffer.data() + (PUTBACK_SIZE - n_pb),
            _inbuffer.data() + PUTBACK_SIZE,
            _inbuffer.data() + PUTBACK_SIZE
        );
        throw ReadChocetBufferError(errno);
    }

    setg(
        _inbuffer.data() + (PUTBACK_SIZE - n_pb),
        _inbuffer.data() + PUTBACK_SIZE,
        _inbuffer.data() + PUTBACK_SIZE + n_read
    );

    return traits_type::to_int_type(*gptr());
}

std::streambuf::int_type ChocetBuffer::overflow(const int_type c)
{
    std::scoped_lock lock(_outbuffer_mutex);
    if (send(
            _fd,
            _outbuffer.data(),
            std::min(pptr() - pbase(), static_cast<ssize_t>(BUFFER_SIZE)),
            _wflags
        ) == -1)
    {
        throw WriteChocetBufferError(errno);
    }
    if (traits_type::eq_int_type(c, traits_type::eof())) {
        return traits_type::eof();
    }
    _outbuffer.at(0) = traits_type::to_char_type(c);
    setp(_outbuffer.data(), _outbuffer.data() + _outbuffer.size());
    pbump(1);
    return c;
}

std::streambuf::int_type ChocetBuffer::sync()
{
    std::scoped_lock lock(_outbuffer_mutex);
    if (send(
            _fd,
            _outbuffer.data(),
            std::min(pptr() - pbase(), static_cast<ssize_t>(BUFFER_SIZE)),
            _wflags
        ) == -1)
    {
        throw WriteChocetBufferError(errno);
    }
    return 0;
}
}  // namespace chocet
