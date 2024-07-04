/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"
#include <cstddef>

nts::OutputComponent::OutputComponent(std::string name)
{
    this->_nbPins = 1;
    this->links.resize(1);
    this->pins.resize(1);
    this->links.at(0) = nullptr;
    this->_name = name;
    this->state = nts::Tristate::Undefined;
    this->_type = Output;
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw Error ("Invalid number of pin.");
    if (this->links.at(0) == nullptr)
        throw Error ("link is undefined.");
    this->state = this->links.at(0)->compute(this->pins.at(0));
    return this->state;
}