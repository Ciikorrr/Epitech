/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Paladin
*/
#include <iostream>
#include <string>
#include "Paladin.hpp"
#include "Enchanter.hpp"
#include "ICharacter.hpp"
#include "IPotion.hpp"


Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    std::cout << this->_name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->_name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return Knight::attack();
}

int Paladin::special()
{
    return Enchanter::special();
}

void Paladin::rest()
{
    return Priest::rest();
}
