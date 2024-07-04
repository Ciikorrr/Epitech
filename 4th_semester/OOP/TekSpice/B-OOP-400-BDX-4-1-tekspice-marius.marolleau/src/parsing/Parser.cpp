/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** OpenFile
*/

#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include "File.hpp"
#include "../factory/Factory.hpp"
#include "../error/Error.hpp"

const char *COMPONENTS[24] = {
    "true",
    "false",
    "and",
    "or",
    "xor",
    "not",
    "input",
    "output",
    "clock",
    "4001",
    "4011",
    "4030",
    "4069",
    "4071",
    "4081",
    "4008",
    "4013",
    "4017",
    "4040",
    "4094",
    "4512",
    "4514",
    "4801",
    "2716"
};

bool verif_alpha(std::string str)
{
    for (auto c : str) {
        if (std::isalpha(c))
            return true;
    }
    return false;
}

void linksParsing(Factory &factory, std::string elem)
{
    std::stringstream stream(elem);
    std::string entryOne;
    std::string entryTwo;
    std::vector<std::string> vectEntryOne;
    std::vector<std::string> vectEntryTwo;
    bool errorNameOne = true;
    bool errorNameTwo = true;
    std::shared_ptr<nts::IComponent> tmpOne;
    std::shared_ptr<nts::IComponent> tmpTwo;

    stream >> entryOne;
    stream >> entryTwo;

    size_t posColon = entryTwo.find(":");
    size_t posHash = entryTwo.find("#");

    vectEntryOne.push_back(entryOne.substr(0, entryOne.find(":")));
    vectEntryOne.push_back(entryOne.substr(entryOne.find(":") + 1));
    vectEntryTwo.push_back(entryTwo.substr(0, posColon));
    vectEntryTwo.push_back(entryTwo.substr(posColon + 1, posHash - posColon - 1));
    if (vectEntryOne.back() == "" || vectEntryTwo.back() == "")
        throw Error("No pin specify for link.");
    if (verif_alpha(vectEntryOne.back()) || verif_alpha(vectEntryTwo.back()))
        throw Error ("Alphabetic pin detected.");
    if (stof(vectEntryOne.back()) < 0  || stof(vectEntryTwo.back()) < 0)
        throw Error("Negative pin detected.");
    for (auto elem : factory.getComponents()) {
        if (elem.get()->getName() == vectEntryOne.front()) {
            errorNameOne = false;
            if (stof(vectEntryOne.back()) > elem.get()->getNbPins())
                throw Error("Invalid number of pins");
            tmpOne = elem;
        }
        if (elem.get()->getName() == vectEntryTwo.front()) {
            errorNameTwo = false;
            if (stof(vectEntryTwo.back()) > elem.get()->getNbPins())
                throw Error("Invalid number of pins");
            tmpTwo = elem;
        }
    }
    if (errorNameOne || errorNameTwo)
        throw Error("Wrong gate name.");
    tmpOne.get()->setLink(stof(vectEntryOne.back()), *tmpTwo, stof(vectEntryTwo.back()), 2);
}

void chipsetsParsing(Factory &factory, std::string elem)
{
    std::stringstream stream(elem);
    std::string type;
    std::string name;

    stream >> type;
    stream >> name;
    if (type[0] == '#')
        return;
    if (name == "")
        throw Error("The component name isn't provide.");
    for (auto elem : factory.getComponents()) {
        if (elem.get()->getName() == name)
            throw Error("Two components have the same name.");
    }
    for (int i = 0; i < 24; i += 1) {
        if (type == COMPONENTS[i]) {
            factory.createComponent(type, name);
            return;
        }
    }
    throw Error("Wrong component type");
}

void parseComponents(Factory &factory, std::vector<std::string> lines)
{
    bool chipset = false;
    bool link = false;
    for (auto elem : lines) {
        if (elem.front() == '#' || elem.front() == '\0' || elem.front() == '\n')
            continue;
        if (elem.find(".chipsets:") == 0) {
            chipset = true;
            link = false;
            continue;
        }
        if (elem.find(".links:") == 0) {
            chipset = false;
            link = true;
            continue;
        }
        if (chipset)
            chipsetsParsing(factory, elem);
        if (link)
            linksParsing(factory, elem);
    }

}

std::vector<std::string> openFile(std::string filePath)
{
    File fileGetter(filePath);
    return fileGetter.GetLines();
}
