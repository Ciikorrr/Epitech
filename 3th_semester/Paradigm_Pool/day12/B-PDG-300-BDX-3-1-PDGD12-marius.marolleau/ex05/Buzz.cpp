/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Buzz
*/

#include "Buzz.hpp"
#include "Picture.hpp"
#include <iostream>

Buzz::Buzz(std::string name, std::string ascii) : Toy(BUZZ, name, ascii)
{    
}

Buzz::~Buzz()
{
}

void Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: " << this->getName() << " " << "\"" << statement << "\"" << std::endl;
}

bool Buzz::speak_es(std::string statement)
{
    std::cout << "BUZZ: " << this->getName() << " senorita " << "\"" << statement << "\" senorita" << std::endl;
    return true;
}