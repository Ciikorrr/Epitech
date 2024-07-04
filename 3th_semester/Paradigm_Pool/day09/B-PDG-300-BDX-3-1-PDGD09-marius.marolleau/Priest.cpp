/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Priest
*/
#include <iostream>
#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << this->_name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->_name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    this->_power = 100;
    this->_health = 100;
    std::cout << this->_name << " prays." << std::endl;
}
