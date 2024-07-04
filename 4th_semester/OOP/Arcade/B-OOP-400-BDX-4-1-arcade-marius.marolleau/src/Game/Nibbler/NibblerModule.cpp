/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** NibblerModule
*/

#include "NibblerModule.hpp"
#include "../../Error/Error.hpp"

std::array<std::pair<int, int>, 72> wallCoords = {
    std::make_pair(1, 16), std::make_pair(1, 15), std::make_pair(1, 14),
    std::make_pair(1, 13), std::make_pair(2, 16), std::make_pair(3, 16),
    std::make_pair(4, 16), std::make_pair(16, 16), std::make_pair(13, 16),
    std::make_pair(15, 16), std::make_pair(14, 16), std::make_pair(16, 15),
    std::make_pair(16, 14), std::make_pair(16, 13), std::make_pair(15, 2),
    std::make_pair(14, 14), std::make_pair(3, 14), std::make_pair(1, 6),
    std::make_pair(0, 0), std::make_pair(17, 0), std::make_pair(1, 2),
    std::make_pair(2, 2), std::make_pair(2, 1), std::make_pair(4, 1),
    std::make_pair(3, 1), std::make_pair(16, 2), std::make_pair(15, 1),
    std::make_pair(14, 1), std::make_pair(13, 1), std::make_pair(12, 1),
    std::make_pair(5, 1), std::make_pair(5, 2), std::make_pair(5, 3),
    std::make_pair(5, 4), std::make_pair(6, 4), std::make_pair(7, 4),
    std::make_pair(8, 4), std::make_pair(9, 4), std::make_pair(10, 4),
    std::make_pair(11, 4), std::make_pair(12, 4), std::make_pair(12, 3),
    std::make_pair(12, 2), std::make_pair(9, 2), std::make_pair(8, 2),
    std::make_pair(10, 2), std::make_pair(7, 2), std::make_pair(2, 7),
    std::make_pair(3, 8), std::make_pair(4, 9), std::make_pair(5, 10),
    std::make_pair(16, 6), std::make_pair(15, 7), std::make_pair(14, 8),
    std::make_pair(13, 9), std::make_pair(12, 10), std::make_pair(11, 11),
    std::make_pair(10, 12), std::make_pair(6, 11), std::make_pair(7, 12),
    std::make_pair(1, 7), std::make_pair(2, 8), std::make_pair(3, 9),
    std::make_pair(4, 10), std::make_pair(5, 11), std::make_pair(6, 12),
    std::make_pair(11, 12), std::make_pair(12, 11), std::make_pair(13, 10),
    std::make_pair(14, 9), std::make_pair(15, 8), std::make_pair(16, 7)
};

std::array<std::pair<int, int>, 13> fruitsCoords = {
    std::make_pair(9, 3), std::make_pair(1, 1), std::make_pair(16, 1),
    std::make_pair(8, 1), std::make_pair(2, 15), std::make_pair(15, 15),
    std::make_pair(5, 9), std::make_pair(12, 9), std::make_pair(1, 8),
    std::make_pair(16, 8), std::make_pair(16, 16), std::make_pair(0, 17),
    std::make_pair(17, 17)
};

NibblerModule::NibblerModule(std::string lib) : width(20), height(20)
{
    if ((this->libFd = dlopen(lib.c_str(), RTLD_LAZY)) == nullptr)
        throw ErrorCore("dlopen failed.");

    this->nibblerAlgo = reinterpret_cast<int (*)(IGameModule &)>(dlsym(this->libFd, "nibblerAlgo"));
    if (!nibblerAlgo)
        throw ErrorCore("Invalid function.");

    this->gameOver = false;
    this->lengthTail = 3;
    this->dir = STOP;
    this->headCoords = std::make_pair(9, 12);
    this->tailCoords.resize(2000);
    this->tailCoords.push_back(this->headCoords);
    this->tailCoords.push_back(std::make_pair(9, 13));
    this->tailCoords.push_back(std::make_pair(9, 14));
    this->tailCoords.push_back(std::make_pair(9, 15));
    this->eat = false;
    this->_time = 5;
    this->loopLap = 0;
    this->setFruits();
    this->setWalls();
}

std::vector<std::pair<int, int>> NibblerModule::getWalls(void) const
{
    return this->walls;
}

std::vector<std::pair<std::pair<int, int>, bool>> NibblerModule::getFruitsCoords(void) const
{
    return this->fruits;
}

std::pair<std::pair<int, int>, bool> NibblerModule::getFruitsCoords(int index) const
{
    return this->fruits.at(index);
}

void NibblerModule::setFruitVisible(int index, bool b)
{
    this->fruits.at(index).second = b;
}

int NibblerModule::gameAlgorithm(IGameModule &snake)
{
    if (this->nibblerAlgo)
        return nibblerAlgo(snake);
    return 0;
}

void NibblerModule::setFruits(void)
{
    for (auto elem : fruitsCoords)
        this->fruits.push_back(std::make_pair(elem, true));
}

void NibblerModule::setWalls(void)
{
    for (size_t i = 0; i < 18; i += 1) {
        this->walls.push_back({i, -1});
        this->walls.push_back({i, 18});
        this->walls.push_back({-1, i});
        this->walls.push_back({18, i});
    }
    for (auto elem : wallCoords)
        this->walls.push_back(elem);
}