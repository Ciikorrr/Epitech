/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** HealthPotion
*/
#include <iostream>
#include "HealthPotion.hpp"

int HealthPotion::getHeal() const
{
    return this->_heal;
}

int HealthPotion::getPower() const
{
    return this->_power;
}

