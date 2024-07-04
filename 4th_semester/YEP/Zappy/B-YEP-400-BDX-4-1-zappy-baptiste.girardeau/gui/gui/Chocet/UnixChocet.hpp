/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** UnixChocet.hpp
*/

#pragma once
#include "Chocet.hpp"

namespace chocet {

class UnixChocet final : public Chocet {
    UnixChocet(const std::string &address, bool abstract);
};

}  // namespace chocet
