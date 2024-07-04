/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

nts::AndComponent::AndComponent(std::string name)
{
    this->_nbPins = 3;
    this->links.resize(3);
    this->pins.resize(3);
    for (size_t i = 0; i < 3; i += 1)
        this->links.at(i) = nullptr;
    this->_name = name;
    this->_type = Gate;
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
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
        return nts::Tristate::True;
    if (
        stateOne == nts::Tristate::False ||
        stateTwo == nts::Tristate::False
        )
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}
