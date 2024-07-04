/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** ParseCmd
*/

#include "../Circuit/Circuit.hpp"

bool setInputValue(std::string value, std::shared_ptr<nts::IComponent> &elem)
{
    if (value == "1") {
        elem.get()->setWaitingState(nts::Tristate::True);
        return true;
    }
    if (value == "0") {
        elem.get()->setWaitingState(nts::Tristate::False);
        return true;
    }
    if (value == "U") {
        elem.get()->setWaitingState(nts::Tristate::Undefined);
        return true;
    }
    return false;
}

bool checkInputName(std::vector<std::string> inputValue, Circuit &circuit)
{
    for (auto elem : circuit.inputs) {
        if (elem.get()->getName() == inputValue.front()) {
            return setInputValue(inputValue.back(), elem);
        }
    }
    return false;
}

bool ParseCmd(std::string line, Circuit &circuit)
{
    (void)circuit;
    if (line.find("=") == line.npos)
        return false;
    std::vector<std::string> inputValue;
    inputValue.push_back(line.substr(0, line.find("=")));
    inputValue.push_back(line.substr(line.find("=") + 1));
    return checkInputName(inputValue, circuit);
}