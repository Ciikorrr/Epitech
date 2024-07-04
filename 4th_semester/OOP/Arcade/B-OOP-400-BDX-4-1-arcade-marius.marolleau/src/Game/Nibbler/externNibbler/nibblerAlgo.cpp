/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** algo
*/

#include <ctime>
#include <iostream>
#include "../../IGameModule.hpp"

bool isTailTouched(IGameModule &nibbler, std::pair<int, int> head)
{
    for (size_t i = 0; i < nibbler.getTailCoords().size(); i += 1)
        if (nibbler.getTailCoords(i) == head)
            return true;
    return false;
}

bool isWallTouched(IGameModule &nibbler, std::pair<int, int> head)
{
    for (auto elem : nibbler.getWalls())
        if (elem == head)
            return true;
    return false;
}

bool eatFruit(std::pair<int, int> head, IGameModule &nibbler)
{
    for (size_t i = 0; i < nibbler.getFruitsCoords().size(); i += 1) {
        if (nibbler.getFruitsCoords(i).second && nibbler.getFruitsCoords(i).first == head) {
            nibbler.setFruitVisible(i, false);
            return true;
        }
    }
    return false;
}

void setDirection(IGameModule &nibbler)
{
    if (nibbler.getSnakeDir() == LEFT || nibbler.getSnakeDir() == RIGHT) {
        if (!isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) + 1)) &&
        !isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) - 1))) {
            nibbler.setSnakeDir(STOP);
            return;
        }
        if (isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) + 1)) &&
        !isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) - 1))) {
            nibbler.setSnakeDir(UP);
            return;
        }
        if (!isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) + 1)) &&
        isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) - 1))) {
            nibbler.setSnakeDir(DOWN);
            return;
        }
        return;
    }
    if (!isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) + 1, nibbler.getHeadCoords(false))) &&
    !isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) - 1, nibbler.getHeadCoords(false)))) {
        nibbler.setSnakeDir(STOP);
        return;
    }
    if (isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) + 1, nibbler.getHeadCoords(false))) &&
    !isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) - 1, nibbler.getHeadCoords(false)))) {
        nibbler.setSnakeDir(LEFT);
        return;
    }
    if (!isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) + 1, nibbler.getHeadCoords(false))) &&
    isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) - 1, nibbler.getHeadCoords(false)))) {
        nibbler.setSnakeDir(RIGHT);
        return;
    }
}

bool wallManager(IGameModule &nibbler)
{
    switch (nibbler.getSnakeDir()) {
        case LEFT:
            if (isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) - 1, nibbler.getHeadCoords(false)))) {
                setDirection(nibbler);
                return true;
            }
            break;
        case UP:
            if (isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) - 1))) {
                setDirection(nibbler);
                return true;
            }
            break;
        case DOWN:
            if (isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true), nibbler.getHeadCoords(false) + 1))) {
                setDirection(nibbler);
                return true;
            }
            break;
        case RIGHT:
            if (isWallTouched(nibbler, std::make_pair(nibbler.getHeadCoords(true) + 1, nibbler.getHeadCoords(false)))) {
                setDirection(nibbler);
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

extern "C" int nibblerAlgo(IGameModule &nibbler)
{
    nibbler.setLoopLap(nibbler.getLoopLap() + 1);
    if (nibbler.getLoopLap() == 10) {
        nibbler.setLoopLap(0);
        nibbler.setTime(nibbler.getTime() - 1);
    }
    if (nibbler.getTime() <= 0) {
        nibbler.setGameOver(true);
        return 84;
    }
    if (nibbler.getSnakeDir() == STOP || wallManager(nibbler))
        return 0;
    srand(time(nullptr));
    nibbler.setEating(false);
    std::pair<int, int> prev = nibbler.getTailCoords().front();
    std::pair<int, int> prevTwo;

    nibbler.setTailCoords(-1, nibbler.getHeadCoords());
    for (int i = 1; i < nibbler.getSnakeSize(); i += 1) {
        prevTwo = nibbler.getTailCoords(i);
        nibbler.setTailCoords(i, prev);
        prev = prevTwo;
    }

    switch (nibbler.getSnakeDir()) {
        case LEFT:
            nibbler.setHeadCoords(nibbler.getHeadCoords().first - 1, -84);
            break;
        case UP:
            nibbler.setHeadCoords(-84, nibbler.getHeadCoords().second - 1);
            break;
        case DOWN:
            nibbler.setHeadCoords(-84, nibbler.getHeadCoords().second + 1);
            break;
        case RIGHT:
            nibbler.setHeadCoords(nibbler.getHeadCoords().first + 1, -84);
            break;
        default:
            break;
    }

    for (int i = 0; i < nibbler.getSnakeSize(); i += 1)
        if (nibbler.getTailCoords(i) == nibbler.getHeadCoords())
            nibbler.setGameOver(true);

    if (eatFruit(nibbler.getHeadCoords(), nibbler)) {
        nibbler.setSnakeSize(nibbler.getSnakeSize() + 1);
        nibbler.setEating(true);
        nibbler.setTime(nibbler.getTime() + 2);
    }
    return 0;
}
