/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4069
*/

#include "Component4069.hpp"
#include "components/IComponent.hpp"

nts::Component4069::Component4069(std::string name)
{
    this->_nbPins = 14;
    this->links.resize(14);
    this->pins.resize(14);
    for (size_t i = 0; i < 14; i += 1)
        this->links.at(i) = nullptr;
    this->_name = name;
    this->_type = Gate;
}

nts::Component4069::~Component4069()
{
}

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    if (pin != 2 && pin != 4 && pin != 6 && pin != 8 && pin != 10 && pin != 12)
        throw Error ("Invalid number of pin");
    nts::Tristate stateOne;
    if (pin == 2) {
        if (!this->links.at(0))
            throw Error("Link is undefined");
        stateOne = this->links.at(0)->compute(this->pins.at(0));
        if (stateOne == nts::Tristate::True)
            return nts::Tristate::False;
        if (stateOne == nts::Tristate::False)
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (pin == 4) {
        if (!this->links.at(2))
            throw Error("Link is undefined");
        stateOne = this->links.at(2)->compute(this->pins.at(2));
        if (stateOne == nts::Tristate::True)
            return nts::Tristate::False;
        if (stateOne == nts::Tristate::False)
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (pin == 6) {
        if (!this->links.at(4))
            throw Error("Link is undefined");
        stateOne = this->links.at(4)->compute(this->pins.at(4));
        if (stateOne == nts::Tristate::True)
            return nts::Tristate::False;
        if (stateOne == nts::Tristate::False)
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (pin == 8) {
        if (!this->links.at(8))
            throw Error("Link is undefined");
        stateOne = this->links.at(8)->compute(this->pins.at(8));
        if (stateOne == nts::Tristate::True)
            return nts::Tristate::False;
        if (stateOne == nts::Tristate::False)
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (pin == 10) {
        if (!this->links.at(10))
            throw Error("Link is undefined");
        stateOne = this->links.at(10)->compute(this->pins.at(10));
        if (stateOne == nts::Tristate::True)
            return nts::Tristate::False;
        if (stateOne == nts::Tristate::False)
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (!this->links.at(12))
            throw Error("Link is undefined");
    stateOne = this->links.at(12)->compute(this->pins.at(12));
    if (stateOne == nts::Tristate::True)
        return nts::Tristate::False;
    if (stateOne == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}
