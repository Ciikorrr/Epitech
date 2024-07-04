/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include "AFruit.hpp"
#include <iostream>

FruitBox::FruitBox(unsigned int size) : _size(size), _nbFruit(0)
{
}

FruitBox::~FruitBox()
{
    for (auto elem : this->box) {
        if (elem != nullptr)
            delete elem;
    }
}

unsigned int FruitBox::nbFruits() const
{
    return this->_nbFruit;
}

unsigned int FruitBox::getSize() const
{
    return this->_size;
}

void FruitBox::setNbFruit(int nb)
{
    this->_nbFruit = nb;
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (this->_nbFruit == this->_size)
        return false;
    for (IFruit *elem : this->box) {
        if (elem == fruit)
            return false;
    }
    this->box.push_back(fruit);
    this->_nbFruit += 1;
    return true;
}

IFruit *FruitBox::popFruit()
{
    if (this->_nbFruit == 0)
        return nullptr;
    this->_nbFruit -= 1;
    IFruit *tmp = this->box.front();
    this->box.pop_front();
    return tmp;
}

std::ostream &operator<<(std::ostream &s, FruitBox const &f1)
{
    s << "[";
    auto list = f1.getList();
    unsigned int count = 0;
    for (auto *elem : list) {
        s << *elem;
        if (count + 1 == f1.nbFruits())
            break;
        s << ", ";
        count++;
    }
    s << "]";
    return s;
}

std::list<IFruit *>FruitBox::getList() const
{
    return this->box;
}

void FruitBox::setList(std::list<IFruit *> list)
{
    this->box = list;
}
