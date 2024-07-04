/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Factory
*/

#include "Factory.hpp"

void Factory::createComponent(const std::string &type, std::string name)
{
    if (type == "and")
        this->components.push_back(this->createAnd(name));
    if (type == "or")
        this->components.push_back(this->createOr(name));
    if (type == "xor")
        this->components.push_back(this->createXor(name));
    if (type == "true")
        this->components.push_back(this->createTrue(name));
    if (type == "false")
        this->components.push_back(this->createFalse(name));
    if (type == "not")
        this->components.push_back(this->createNot(name));
    if (type == "input")
        this->components.push_back(this->createInput(name));
    if (type == "output")
        this->components.push_back(this->createOutput(name));
    if (type == "clock")
        this->components.push_back(this->createClock(name));
    if (type == "4071")
        this->components.push_back(this->create4071(name));
    if (type == "4030")
        this->components.push_back(this->create4030(name));
    if (type == "4081")
        this->components.push_back(this->create4081(name));
    if (type == "4011")
        this->components.push_back(this->create4011(name));
    if (type == "4069")
        this->components.push_back(this->create4069(name));
}

std::vector<std::shared_ptr<nts::IComponent>> Factory::getComponents() const
{
    return this->components;
}

std::shared_ptr<nts::IComponent> Factory::createTrue(std::string name) const
{
    std::shared_ptr<nts::IComponent> trueGate = std::make_unique<nts::TrueComponent>(name);
    return trueGate;
}

std::shared_ptr<nts::IComponent> Factory::createFalse(std::string name) const
{
    std::shared_ptr<nts::IComponent> falseGate = std::make_unique<nts::FalseComponent>(name);
    return falseGate;
}

std::shared_ptr<nts::IComponent> Factory::createOr(std::string name) const
{
    std::shared_ptr<nts::IComponent> orGate = std::make_unique<nts::OrComponent>(name);
    return orGate;
}

std::shared_ptr<nts::IComponent> Factory::createXor(std::string name) const
{
    std::shared_ptr<nts::IComponent> xorGate = std::make_unique<nts::XorComponent>(name);
    return xorGate;
}

std::shared_ptr<nts::IComponent> Factory::createNot(std::string name) const
{
    std::shared_ptr<nts::IComponent> notGate = std::make_unique<nts::NotComponent>(name);
    return notGate;
}

std::shared_ptr<nts::IComponent> Factory::createAnd(std::string name) const
{
    std::shared_ptr<nts::IComponent> andGate = std::make_unique<nts::AndComponent>(name);
    return andGate;
}

std::shared_ptr<nts::IComponent> Factory::createInput(std::string name) const
{
    std::shared_ptr<nts::IComponent> InputGate = std::make_unique<nts::InputComponent>(name);
    return InputGate;
}

std::shared_ptr<nts::IComponent> Factory::createOutput(std::string name) const
{
    std::shared_ptr<nts::IComponent> outputGate = std::make_unique<nts::OutputComponent>(name);
    return outputGate;
}

std::shared_ptr<nts::IComponent> Factory::createClock(std::string name) const
{
    std::shared_ptr<nts::IComponent> clockComponent = std::make_unique<nts::ClockComponent>(name);
    return clockComponent;
}

std::shared_ptr<nts::IComponent> Factory::create4071(std::string name) const
{
    std::shared_ptr<nts::IComponent> component4071 = std::make_unique<nts::Component4071>(name);
    return component4071;
}

std::shared_ptr<nts::IComponent> Factory::create4030(std::string name) const
{
    std::shared_ptr<nts::IComponent> component4030 = std::make_unique<nts::Component4030>(name);
    return component4030;
}

std::shared_ptr<nts::IComponent> Factory::create4081(std::string name) const
{
    std::shared_ptr<nts::IComponent> component4081 = std::make_unique<nts::Component4081>(name);
    return component4081;
}

std::shared_ptr<nts::IComponent> Factory::create4011(std::string name) const
{
    std::shared_ptr<nts::IComponent> component4011 = std::make_unique<nts::Component4011>(name);
    return component4011;
}

std::shared_ptr<nts::IComponent> Factory::create4069(std::string name) const
{
    std::shared_ptr<nts::IComponent> component4069 = std::make_unique<nts::Component4069>(name);
    return component4069;
}