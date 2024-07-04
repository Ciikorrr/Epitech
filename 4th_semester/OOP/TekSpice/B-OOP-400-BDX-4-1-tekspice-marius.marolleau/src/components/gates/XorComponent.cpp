/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent(std::string name)
{
    this->_nbPins = 3;
    this->links.resize(3);
    this->pins.resize(3);
    for (size_t i = 0; i < 3; i += 1)
        this->links.at(i) = nullptr;
    this->_name = name;
    this->_type = Gate;
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin != 3)
        throw Error("Invalid number of pin");
    if (!this->links.at(0) || !this->links.at(1))
        throw Error("Link is undefined");
    nts::Tristate stateOne = this->links.at(0)->compute(this->pins.at(0));
    nts::Tristate stateTwo = this->links.at(1)->compute(this->pins.at(1));
    if (
        stateOne == nts::Tristate::True &&
        stateTwo == nts::Tristate::True
        )
        return nts::Tristate::False;
    if (
        stateOne == nts::Tristate::False &&
        stateTwo == nts::Tristate::False
        )
        return nts::Tristate::False;
    if (
        (stateOne == nts::Tristate::True &&
        stateTwo == nts::Tristate::False) ||
        (stateOne == nts::Tristate::False &&
        stateTwo == nts::Tristate::True)
        )
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}