/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** CommandParser
*/

#pragma once

#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <tuple>

namespace zizi {

class CommandParser final {
   public:
    CommandParser() = default;
    CommandParser(std::span<char *> args);

    [[nodiscard]] std::tuple<uint16_t, std::string> values() const;

   private:
    void _parsePort(const std::span<char *>::iterator &cur);
    void _parseAddress(const std::span<char *>::iterator &cur);

    std::optional<uint16_t> _port;
    std::optional<std::string> _address;
};
}  // namespace zizi
