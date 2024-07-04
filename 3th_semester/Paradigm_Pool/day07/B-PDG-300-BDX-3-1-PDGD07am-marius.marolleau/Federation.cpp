/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** Federation
*/
#include <iostream>
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_maxWarp = maxWarp;
    this->_name = name;
    this->_width = width;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;
    std::cout << "The ship USS " << this->_name  << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    if (this->getTorpedo() != 0)
        std::cout << "Weapons are set: " << this->getTorpedo() << " torpedoes ready." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_maxWarp = 1;
    this->_name = name;
    this->_width = width;
    this->_location = this->_home;
    std::cout << "The independent ship " << this->_name  << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

/* --------------------------------------------------------------------------------------*/

void Federation::Ship::setupCore(WarpSystem::Core *Core)
{
    this->Core = Core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << this->_name << ": The core is " << (this->Core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}



void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *Core)
{
    this->Core = Core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << this->_name << ": The core is " << (this->Core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

/* --------------------------------------------------------------------------------------*/

std::string Federation::Starfleet::Captain::getName()
{
    return this->_name;
}

int Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

/* --------------------------------------------------------------------------------------*/

Federation::Starfleet::Captain::Captain(std::string _name)
{
    this->_name = _name;
}

/* --------------------------------------------------------------------------------------*/

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    this->captain = captain;
    std::cout << this->captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." <<std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string _name)
{
    this->_name = _name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

/* --------------------------------------------------------------------------------------*/

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->Core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != this->_location && this->Core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->Core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}


bool Federation::Starfleet::Ship::move()
{
    if (this->Core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

/* --------------------------------------------------------------------------------------*/


bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->Core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->Core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != this->_location && this->Core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (this->Core->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

/* --------------------------------------------------------------------------------------*/

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

int Federation::Starfleet::Ship::getShield()
{
    return this->_shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return this->_photonTorpedo;
}

/* --------------------------------------------------------------------------------------*/

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (this->_photonTorpedo != 0) {
        this->_photonTorpedo -= 1;
        target->setShield(target->getShield() - 50);
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    } else {
        std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" << std::endl;
    }

}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (this->_photonTorpedo - torpedoes >= 0) {
        this->_photonTorpedo -= torpedoes;
        target->setShield(target->getShield() - (50 * torpedoes));
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << "torpedoes remaining." << std::endl;
    } else {
        std::cout << this->_name << ": Not enough torpedoes to fire, " << this->captain->getName() << std::endl;
    }
}

/* --------------------------------------------------------------------------------------*/

WarpSystem::Core *Federation::Ship::getCore()
{
    return this->Core;
}
