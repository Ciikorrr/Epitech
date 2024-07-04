/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Knight
*/
#include <iostream>
#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->_name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
    this->_power -= 10;
    std::cout << this->_name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power < 30) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << this->_name << " impales his enemy." << std::endl;
    this->_power -= 30;
    return 50;

}

void Knight::rest()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    if (this->_power + 50 > 100) {
        this->_power = 100;
        std::cout << this->_name << " eats." << std::endl;
    } else {
        this->_power += 50;
        std::cout << this->_name << " eats." << std::endl;
    }
}
