/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** CommandParser
*/

#include "CommandParser.hpp"

#include <cstring>
#include <span>
#include <stdexcept>

namespace zizi {

CommandParser::CommandParser(std::span<char *> args)
{
    if (args.size() < 2) {
        throw std::runtime_error("Invalid number of arguments");
    }

    auto current = args.begin();
    std::advance(current, 1);

    while (current != args.end()) {
        if (std::strcmp(*current, "-p") == 0 && current + 1 != args.end()) {
            _parsePort(++current);
        }
        if (std::strcmp(*current, "-h") == 0 && current + 1 != args.end()) {
            _parseAddress(++current);
        }
        ++current;
    }

    if (!_port.has_value() || !_address.has_value()) {
        throw std::runtime_error("Invalid arguments");
    }
}

void CommandParser::_parsePort(const std::span<char *>::iterator &cur)
{
    _port = std::stoul(std::string{*cur});
}

void CommandParser::_parseAddress(const std::span<char *>::iterator &cur)
{
    _address = std::string{*cur};
}

std::tuple<uint16_t, std::string> CommandParser::values() const
{
    if (!_port.has_value() || !_address.has_value()) {
        throw std::runtime_error("Parser has not been initialized");
    }

    return {*_port, *_address};
}

}  // namespace zizi
