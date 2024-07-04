/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** BorgQueen
*/

#include "Destination.hpp"
#include "Borg.hpp"

Borg::BorgQueen::BorgQueen()
{
    this->movePtr = &Borg::Ship::move;
    this->firePtr = &Borg::Ship::fire;
    this->destroyPtr = &Borg::Ship::fire;
}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    return (ship->*movePtr)(dest);
}

void Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    (ship->*firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    (ship->*destroyPtr)(target);
}
