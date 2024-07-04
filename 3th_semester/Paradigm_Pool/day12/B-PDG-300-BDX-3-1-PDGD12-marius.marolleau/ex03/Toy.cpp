/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Toy
*/

#include "Toy.hpp"
#include "Picture.hpp"
#include <iostream>

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = "";
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    _type = type;
    _name = name;
    Picture picture(filename);
    if (picture.data == "ERROR") {
        this->_picture = "ERROR";
        return;
    }
    this->_picture = picture.data;
}

Toy::Toy(const Toy &t)
{
    _type = t._type;
    _name = t._name;
    _picture = t._picture;
}

Toy &Toy::operator=(const Toy &t)
{
    _name = t._name;
    _picture = t._picture;
    _type = t._type;
    return *this;
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string filename)
{
    Picture picture(filename);
    if (picture.data == "ERROR") {
        this->_picture = "ERROR";
        return false;
    }
    this->_picture = picture.data;
    return true;
}

std::string Toy::getAscii() const
{
    return this->_picture;
}

void Toy::speak(std::string statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}