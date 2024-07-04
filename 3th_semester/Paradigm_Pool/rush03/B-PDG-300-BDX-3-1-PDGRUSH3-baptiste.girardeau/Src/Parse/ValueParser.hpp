/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** ValueParser
*/

#pragma once

#include <optional>
#include <string>

namespace ValueParser {

std::optional<int> toInt(const std::string &str);
std::optional<double> toDouble(const std::string &str);

}  // namespace ValueParser
