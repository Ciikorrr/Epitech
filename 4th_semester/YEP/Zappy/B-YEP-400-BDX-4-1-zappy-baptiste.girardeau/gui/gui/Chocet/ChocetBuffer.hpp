/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ChocetBuffer.hpp
*/

#pragma once

#include <array>
#include <mutex>
#include <streambuf>

namespace chocet {
class ChocetBuffer final : public std::streambuf {
   public:
    explicit ChocetBuffer(int fd);
    ChocetBuffer(const ChocetBuffer &) = delete;
    ChocetBuffer(ChocetBuffer &&oth) noexcept;

    ChocetBuffer &operator=(const ChocetBuffer &) = delete;
    ChocetBuffer &operator=(ChocetBuffer &&oth) noexcept;

    ~ChocetBuffer() override;

    [[nodiscard]] int fd() const
    {
        return _fd;
    }

    int &rflags()
    {
        return _rflags;
    }

    int &wflags()
    {
        return _wflags;
    }

   protected:
    int_type underflow() override;
    int_type overflow(int_type c) override;
    int_type sync() override;

   private:
    std::mutex _inbuffer_mutex;
    std::mutex _outbuffer_mutex;
    static constexpr size_t BUFFER_SIZE = 1024;
    static constexpr size_t PUTBACK_SIZE = 128;
    int _fd;
    int _rflags{0};
    int _wflags{0};
    std::array<char, BUFFER_SIZE + PUTBACK_SIZE> _inbuffer{};
    std::array<char, BUFFER_SIZE> _outbuffer{};
};
}  // namespace chocet
