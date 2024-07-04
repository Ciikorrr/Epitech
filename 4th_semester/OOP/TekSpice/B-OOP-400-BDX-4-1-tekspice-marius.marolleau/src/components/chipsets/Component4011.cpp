/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4011
*/

#include "Component4011.hpp"

nts::Component4011::Component4011(std::string name)
{
    this->_nbPins = 14;
    this->links.resize(14);
    this->pins.resize(14);
    for (size_t i = 0; i < 14; i += 1)
        this->links.at(i) = nullptr;
    this->_name = name;
    this->_type = Gate;
}

nts::Component4011::~Component4011()
{
}

nts::Tristate nts::Component4011::compute(std::size_t pin)
{
    if (pin != 3 && pin != 4 && pin != 10 && pin != 11)
        throw Error("Invalid number of pin");
    nts::Tristate stateOne;
    nts::Tristate stateTwo;
    if (pin == 3) {
        if (!this->links.at(0) || !this->links.at(1))
            throw Error("Link is undefined");
        stateOne = this->links.at(0)->compute(this->pins.at(0));
        stateTwo = this->links.at(1)->compute(this->pins.at(1));
        if (
            stateOne == nts::Tristate::True &&
            stateTwo == nts::Tristate::True
            )
            return nts::Tristate::False;
        if (
            stateOne == nts::Tristate::False ||
            stateTwo == nts::Tristate::False
            )
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (pin == 4) {
        if (!this->links.at(4) || !this->links.at(5))
            throw Error("Link is undefined");
        stateOne = this->links.at(4)->compute(this->pins.at(4));
        stateTwo = this->links.at(5)->compute(this->pins.at(5));
        if (
            stateOne == nts::Tristate::True &&
            stateTwo == nts::Tristate::True
            )
            return nts::Tristate::False;
        if (
            stateOne == nts::Tristate::False ||
            stateTwo == nts::Tristate::False
            )
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (pin == 10) {
        if (!this->links.at(7) || !this->links.at(8))
            throw Error("Link is undefined");
        stateOne = this->links.at(7)->compute(this->pins.at(7));
        stateTwo = this->links.at(8)->compute(this->pins.at(8));
        if (
            stateOne == nts::Tristate::True &&
            stateTwo == nts::Tristate::True
            )
            return nts::Tristate::False;
        if (
            stateOne == nts::Tristate::False ||
            stateTwo == nts::Tristate::False
            )
            return nts::Tristate::True;
        return nts::Tristate::Undefined;
    }
    if (!this->links.at(11) || !this->links.at(12))
        throw Error("Link is undefined");
    stateOne = this->links.at(11)->compute(this->pins.at(11));
    stateTwo = this->links.at(12)->compute(this->pins.at(12));
    if (
        stateOne == nts::Tristate::True &&
        stateTwo == nts::Tristate::True
        )
        return nts::Tristate::False;
    if (
        stateOne == nts::Tristate::False ||
        stateTwo == nts::Tristate::False
        )
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}