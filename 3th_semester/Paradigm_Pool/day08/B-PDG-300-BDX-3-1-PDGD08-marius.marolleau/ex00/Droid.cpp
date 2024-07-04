/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD08-marius.marolleau
** File description:
** Droid
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid(std::string Id) : _Energy(70), _Attack(50), _Toughness(15)
{
    this->_Id = Id;
    this->_Status = new std::string("Standing by");
    std::cout << "Droid '" << this->_Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &copy) : _Attack(copy._Attack), _Toughness(copy._Toughness)
{
    this->_Energy = copy._Energy;
    this->_Id = copy._Id;
    if (copy._Status)
        this->_Status = new std::string(*(copy._Status));
    else
        this->_Status = new std::string("Standing by");
    std::cout << "Droid '" << copy._Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (this->_Status)
        delete this->_Status;
    std::cout << "Droid '" << this->_Id << "' Destroyed" <<std::endl;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        this->_Energy = 100;
    else
        this->_Energy = energy;
}

void Droid::setId(std::string id)
{
    this->_Id = id;
}

void Droid::setStatus(std::string *status)
{
    delete this->_Status;
    this->_Status = status;
}

size_t Droid::getAttack() const
{
    return this->_Attack;
}

size_t Droid::getEnergy() const
{
    return this->_Energy;
}

size_t Droid::getToughness() const
{
    return this->_Toughness;
}

std::string Droid::getId() const
{
    return this->_Id;
}

std::string Droid::getStatus() const
{
    return *this->_Status;
}

bool Droid::operator==(const Droid &d1) const
{
    if (this->_Attack != d1._Attack || this->_Energy != d1._Energy || this->_Id != d1._Id || this->_Status != d1._Status || this->_Toughness != d1._Toughness)
        return false;
    return true;
}

bool Droid::operator!=(const Droid &d1) const
{
    return !(*this == d1);
}

std::ostream &operator<<(std::ostream &s, const Droid &d1)
{
    s << "Droid '" << d1.getId() << "', " << d1.getStatus() << ", " << d1.getEnergy();
    return s;
}

Droid &Droid::operator=(const Droid &d2)
{
    this->_Id = d2._Id;
    this->_Energy = d2._Energy;
    delete this->_Status;
    this->_Status = new std::string(*(d2._Status));
    return (*this);
}

size_t &Droid::operator<<(size_t &battery)
{
    size_t need = 100 - this->_Energy;
    if (battery < need)
        need = battery;
    this->_Energy += need;
    battery -= need;
    return battery;
}
