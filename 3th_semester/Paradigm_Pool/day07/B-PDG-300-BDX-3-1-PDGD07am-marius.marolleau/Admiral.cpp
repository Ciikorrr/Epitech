/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** Admiral
*/

#include <iostream>
#include "Admiral.hpp"
#include "Federation.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
    this->_name = name;
    this->firePtr = &Federation::Starfleet::Ship::fire;
    this->movePtr = &Federation::Starfleet::Ship::move;
    std::cout << "Admiral " << this->_name << " ready for action." << std::endl;
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
    (ship->*firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination d)
{
    return (ship->*movePtr)(d);
}

