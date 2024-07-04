/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent(std::string name)
{
    this->_nbPins = 1;
    this->links.resize(1);
    this->pins.resize(1);
    this->links.at(0) = nullptr;
    this->_name = name;
    this->state = nts::Tristate::Undefined;
    this->_type = Input;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw Error ("Invalid number of pin.\n");
    if (links.at(0) == nullptr)
        throw Error ("Link is undefined.\n");
    this->simulate(0);
    return this->state;
}