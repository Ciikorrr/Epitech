/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Peasant
*/

#include <string>
#include <iostream>
#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power) : _name(name), _power(power)
{
    this->_health = 100;
    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->_name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return this->_name;
}

int Peasant::getPower() const
{
    return this->_power;
}

int Peasant::getHp() const
{
    return this->_health;
}

int Peasant::attack()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
        this->_power -= 10;
        std::cout << this->_name << " tosses a stone." << std::endl;
        return 5;
}

int Peasant::special()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    if (this->_power + 30 > 100) {
        this->_power = 100;
        std::cout << this->_name << " takes a nap." << std::endl;
    } else {
        this->_power += 30;
        std::cout << this->_name << " takes a nap." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    if (this->_health - damage <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    this->_health -= damage;
    std::cout << this->_name << " takes " << damage << " damage." << std::endl;
}

void Peasant::drink(const IPotion &potion)
{
    std::cout << this->_name << " drinks a mysterious potion." << std::endl;
    this->_health += potion.getHeal();
    if (this->_health > 100)
        this->_health = 100;
    if (this->_health < 0)
        this->_health = 0;
    this->_power += potion.getPower();
    if (this->_power > 100)
        this->_power = 100;
}

void Peasant::drink(const HealthPotion &potion)
{
    std::cout << this->_name << " feels rejuvenated." << std::endl;
    this->_health += potion.getHeal();
    if (this->_health > 100)
        this->_health = 100;
    this->_power += potion.getPower();
    if (this->_power > 100)
        this->_power = 100;
}

void Peasant::drink(const PowerPotion &potion)
{
    std::cout << this->_name << "'s power is restored." << std::endl;
    this->_health += potion.getHeal();
    if (this->_health > 100)
        this->_health = 100;
    this->_power += potion.getPower();
    if (this->_power > 100)
        this->_power = 100;
}

void Peasant::drink(const PoisonPotion &potion)
{
    std::cout << this->_name << " has been poisoned." << std::endl;
    this->_health += potion.getHeal();
    if (this->_health < 0)
        this->_health = 0;
    this->_power += potion.getPower();
    if (this->_power > 100)
        this->_power = 100;
}
