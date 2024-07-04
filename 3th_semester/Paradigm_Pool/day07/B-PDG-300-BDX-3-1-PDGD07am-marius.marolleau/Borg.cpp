/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** Borg
*/
#include <iostream>
#include "Borg.hpp"
#include "Federation.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_repair = repair;
    this->_shield = 100;
    this->_weaponFrequency = weaponFrequency;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile." << std::endl;
    this->_location = this->_home;
}

void Borg::Ship::setupCore(WarpSystem::Core *Core)
{
    this->Core = Core;
}

void Borg::Ship::checkCore()
{
    if (this->Core->checkReactor()->isStable() == true) {
        std::cout << "Everything is in order." << std::endl;
    } else {
        std::cout << "Critical failure imminent.";
    }
}

bool Borg::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->Core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->Core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != this->_location && this->Core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move()
{
    if (this->Core->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

int Borg::Ship::getShield()
{
    return this->_shield;
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return this->_weaponFrequency;
}

short Borg::Ship::getRepair()
{
    return this->_repair;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - this->getWeaponFrequency());
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl; 
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->_repair -= 1;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instuctions." << std::endl;
    } else {
        std::cout << "Energy cells depleted, shield weakning." << std::endl;
    }
}
