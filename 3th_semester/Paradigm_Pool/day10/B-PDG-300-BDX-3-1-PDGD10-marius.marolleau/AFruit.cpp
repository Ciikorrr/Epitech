/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit()
{
}

AFruit::~AFruit()
{
}

unsigned int AFruit::getVitamins() const
{
    return this->_vitamins;
}

std::string AFruit::getName() const
{
    return this->_name;
}

bool AFruit::isPeeled() const
{
    return this->_isPeeled;
}

void AFruit::peel()
{
    if (_isPeeled) {
        return;
    }
    _vitamins = _nbVit;
    _isPeeled = true;
}

