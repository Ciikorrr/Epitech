/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** loopToCircuit
*/

#include "Circuit/Circuit.hpp"

bool ParseCmd(std::string line, Circuit &circuit);
void loop(Circuit &circuit);

void simulate(Circuit &circuit)
{
    for (auto elem : circuit.outputs)
        elem.get()->compute(1);
    circuit.setTick(circuit.getTick() + 1);
}

void display(Circuit &circuit)
{
    std::cout << "tick: " << circuit.getTick() << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto elem : circuit.inputs) {
        std::string currentState = elem.get()->getState() == nts::Tristate::Undefined ?
            "U" :
            std::to_string(elem.get()->getState());
        std::cout << "  " << elem.get()->getName() << ": " << currentState << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto elem : circuit.outputs) {
        std::string currentState = elem.get()->getState() == nts::Tristate::Undefined ?
            "U" :
            std::to_string(elem.get()->getState());
        std::cout << "  " << elem.get()->getName() << ": " << currentState << std::endl;
    }
}

void cmdHolder(std::string line, Circuit &circuit)
{
    if (line == "")
        return;
    if (line == "display")
        return display(circuit);
    if (line == "simulate")
        return simulate(circuit);
    if (line == "loop")
        return loop(circuit);
    if (!ParseCmd(line, circuit))
        std::cout << "Wrong format to set a value to an input." << std::endl;
}

void loopToCircuit(Circuit &circuit)
{
    (void)circuit;
    std::string line;
    bool loop = true;
    simulate(circuit);
    circuit.setTick(0);
    std::cout << "> ";
    while (loop && getline(std::cin, line)) {
        if (line == "exit") {
            loop = false;
            break;
        }
        cmdHolder(line, circuit);
        std::cout << "> ";
    }
}