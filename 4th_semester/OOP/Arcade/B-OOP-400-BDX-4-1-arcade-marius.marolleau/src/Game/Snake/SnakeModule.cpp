/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** Snake
*/

#include "SnakeModule.hpp"
#include "../../Error/Error.hpp"
#include <time.h>

SnakeModule::SnakeModule(std::string lib) : width(20), height(20)
{
    if ((this->libFd = dlopen(lib.c_str(), RTLD_LAZY)) == nullptr)
        throw ErrorCore("dlopen failed.");

    this->snakeAlgo = reinterpret_cast<int (*)(IGameModule &)>(dlsym(this->libFd, "snakeAlgo"));
    if (!snakeAlgo)
        throw ErrorCore("Invalid function.");

    srand(time(nullptr));
    this->gameOver = false;
    this->lengthTail = 0;
    this->dir = STOP;
    this->headCoords.first = this->width / 2;
    this->headCoords.second = (this->height - 2) / 2;
    this->tailCoords.resize(2000);
    this->tailCoords.push_back(this->headCoords);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    this->fruitCoords.first = std::rand() % 17 + 1;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    this->fruitCoords.second = std::rand() % 17 + 1;
    this->score = 0;
    this->eat = false;
}

int SnakeModule::gameAlgorithm(IGameModule &snake)
{
    if (this->snakeAlgo)
        return snakeAlgo(snake);
    return 0;
}

std::pair<int, int> SnakeModule::getFruitCoords() const
{
    return this->fruitCoords;
}

int SnakeModule::getFruitCoords(bool first) const
{
    if (!first)
        return this->fruitCoords.second;
    return this->fruitCoords.first;
}

void SnakeModule::setFruitCoords(int first, int second)
{
    if (first != -1)
        this->fruitCoords.first = first;
    if (second != -1)
        this->fruitCoords.second = second;
}
