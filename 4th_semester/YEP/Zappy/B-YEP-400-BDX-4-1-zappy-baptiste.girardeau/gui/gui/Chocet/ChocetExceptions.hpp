/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ChocetExceptions.hpp
*/

#pragma once

#include <cstring>
#include <exception>
#include <string>

namespace chocet {
class ChocetBufferException : public std::exception {
   public:
    explicit ChocetBufferException(const int errnum) : _errnum{errnum} {}

    [[nodiscard]] const char *what() const noexcept override
    {
        return std::strerror(_errnum);
    }

    [[nodiscard]] int errnum() const noexcept
    {
        return _errnum;
    }

   private:
    int _errnum;
};

class ReadChocetBufferError final : public ChocetBufferException {
    using ChocetBufferException::ChocetBufferException;
};

class WriteChocetBufferError final : public ChocetBufferException {
    using ChocetBufferException::ChocetBufferException;
};

class ChocetException : public std::exception {
   public:
    explicit ChocetException(const int errnum) : _errnum{errnum}
    {
        using std::string_literals::operator""s;
        _strerr = "Chocet: "s + std::strerror(_errnum);
    }

    [[nodiscard]] const char *what() const noexcept override
    {
        return _strerr.c_str();
    }

    [[nodiscard]] int errnum() const noexcept
    {
        return _errnum;
    }

   private:
    std::string _strerr;
    int _errnum;
};

class CreationChocetError final : public ChocetException {
    using ChocetException::ChocetException;
};

class ConnectionChocetError final : public ChocetException {
    using ChocetException::ChocetException;
};
}  // namespace chocet
