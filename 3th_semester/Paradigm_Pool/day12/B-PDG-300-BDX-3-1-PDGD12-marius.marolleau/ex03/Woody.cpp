/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Woody
*/

#include "Woody.hpp"
#include <iostream>

Woody::Woody(std::string name, std::string ascii) : Toy(WOODY, name, ascii)
{
}

Woody::~Woody()
{
}

void Woody::speak(std::string statement)
{
    std::cout << "WOODY: " << this->getName() << " " << "\"" << statement << "\"" << std::endl;
}