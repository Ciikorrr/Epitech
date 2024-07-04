/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** ValueParser
*/

#include "ValueParser.hpp"

std::optional<int> ValueParser::toInt(const std::string &str) {
    try {
        return std::stoi(str);
    } catch (std::exception &e) {
        return std::nullopt;
    }
}

std::optional<double> ValueParser::toDouble(const std::string &str) {
    try {
        return std::stod(str);
    } catch (std::exception &e) {
        return std::nullopt;
    }
}
