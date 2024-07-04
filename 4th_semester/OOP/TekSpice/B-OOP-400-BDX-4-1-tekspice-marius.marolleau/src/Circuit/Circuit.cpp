/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "components/IComponent.hpp"
#include "factory/Factory.hpp"
#include <memory>

Circuit::Circuit(Factory &factory) : tick(0)
{
    for (auto elem : factory.getComponents()) {
        if (elem.get()->getType() == nts::Input)
            this->inputs.push_back(elem);
        if (elem.get()->getType() == nts::Output)
            this->outputs.push_back(elem);
        if (elem.get()->getType() == nts::Gate)
            this->gates.push_back(elem);
    }
}

Circuit::~Circuit()
{
}

std::size_t Circuit::getTick() const
{
    return this->tick;
}

void Circuit::setTick(std::size_t tick)
{
    this->tick = tick;
}
