/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** hubFunctionsManager
*/

#include "factory/Factory.hpp"
#include "Circuit/Circuit.hpp"
#include <string>

std::vector<std::string> openFile(std::string filePath);
void parseComponents(Factory &factory, std::vector<std::string> lines);
void loopToCircuit(Circuit &circuit);

int hubFunctionManager(std::string filePath)
{
    Factory factory;

    try {
        std::vector<std::string> lines = openFile(filePath);
        if (lines.empty())
            throw Error("File is empty");
        parseComponents(factory, lines);
        if (factory.getComponents().size() <= 0)
            throw Error("No components.");
        Circuit circuit(factory);
        loopToCircuit(circuit);
    } catch (const Error &e) {
        std::cout << e.what() << std::endl;
        return ERROR;
    }
    return SUCCESS;
}