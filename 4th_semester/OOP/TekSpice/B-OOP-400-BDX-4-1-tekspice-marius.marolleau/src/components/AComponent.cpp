/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "IComponent.hpp"

nts::AComponent::AComponent() : waitingValue(Tristate::None)
{}

void nts::AComponent::setLink(std::size_t entryOne, IComponent &gate, std::size_t entryTwo, std::size_t stop)
{
    if (stop == 0)
        return;
    this->links.at(entryOne - 1) = &gate;
    this->pins.at(entryOne - 1) = entryTwo;
    gate.setLink(entryTwo, *this, entryOne, stop - 1);
}

std::string nts::AComponent::getName() const
{
    return this->_name;
}

size_t nts::AComponent::getNbPins() const
{
    return this->_nbPins;
}

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (this->waitingValue != nts::Tristate::None) {
        this->state = this->waitingValue;
        this->waitingValue = nts::Tristate::None;
    }
}

nts::Tristate nts::AComponent::getState(void) const
{
    return this->state;
}

nts::Types nts::AComponent::getType() const
{
    return this->_type;
}

void nts::AComponent::setWaitingState(nts::Tristate state)
{
    this->waitingValue = state;
}