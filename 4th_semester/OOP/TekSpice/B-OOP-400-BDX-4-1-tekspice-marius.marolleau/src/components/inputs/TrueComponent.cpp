/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"
#include "components/IComponent.hpp"

nts::TrueComponent::TrueComponent(std::string name)
{
    this->_nbPins = 1;
    this->links.resize(1);
    this->pins.resize(1);
    this->links.at(0) = nullptr;
    this->_name = name;
    this->state = nts::Tristate::True;
    this->_type = Gate;
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw Error("Invalid number of pin.\n");
    if (links.at(0) == nullptr)
        throw Error ("Link is undefined.");
    return Tristate::True;
}