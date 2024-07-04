/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** NotComponent
*/

#include "NotComponent.hpp"
#include "components/IComponent.hpp"

nts::NotComponent::NotComponent(std::string name)
{
    this->_nbPins = 2;
    this->links.resize(2);
    this->pins.resize(2);
    for (size_t i = 0; i < 2; i += 1)
        this->links.at(i) = nullptr;
    this->_name = name;
    this->_type = Gate;
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != 2)
        throw Error("Invalid number of pin");
    if (!this->links.at(0))
        throw Error("Link is undefined");
    nts::Tristate stateOne = this->links.at(0)->compute(this->pins.at(0));
    if (stateOne == nts::Tristate::True)
        return nts::Tristate::False;
    if (stateOne == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}
