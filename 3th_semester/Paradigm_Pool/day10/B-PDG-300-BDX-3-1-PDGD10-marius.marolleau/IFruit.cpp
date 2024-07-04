/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <string>
#include <iostream>

std::ostream &operator<<(std::ostream &s, IFruit const &f1)
{
    s << "[name: \"" << f1.getName() << "\", vitamins: " << f1.getVitamins() << ", peeled: " << std::boolalpha << f1.isPeeled() << "]";
    return s;
}