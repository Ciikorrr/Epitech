/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** algo
*/

#include <ctime>
#include <iostream>
#include "../../IGameModule.hpp"

extern "C" int snakeAlgo(IGameModule &snake)
{
    srand(time(nullptr));
    snake.setEating(false);
    std::pair<int, int> prev = snake.getTailCoords().front();
    std::pair<int, int> prevTwo;

    snake.setTailCoords(-1, snake.getHeadCoords());
    for (int i = 1; i < snake.getSnakeSize(); i += 1) {
        prevTwo = snake.getTailCoords().at(i);
        snake.setTailCoords(i, prev);
        prev = prevTwo;
    }

    switch (snake.getSnakeDir()) {
        case LEFT:
            snake.setHeadCoords(snake.getHeadCoords().first - 1, -84);
            break;
        case UP:
            snake.setHeadCoords(-84, snake.getHeadCoords().second - 1);
            break;
        case DOWN:
            snake.setHeadCoords(-84, snake.getHeadCoords().second + 1);
            break;
        case RIGHT:
            snake.setHeadCoords(snake.getHeadCoords().first + 1, -84);
            break;
        default:
            break;
    }

    if (snake.getHeadCoords().first >= 18 || snake.getHeadCoords().first < 0 ||
    snake.getHeadCoords().second >= 18 || snake.getHeadCoords().second < 0) {
        snake.setGameOver(true);
        return 84;
    }

    for (int i = 0; i < snake.getSnakeSize(); i += 1)
        if (snake.getTailCoords().at(i) == snake.getHeadCoords())
            snake.setGameOver(true);

    if (snake.getHeadCoords() == snake.getFruitCoords()) {
        snake.setScore(snake.getScore() + 10);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        snake.setFruitCoords(std::rand() % 17 + 1, -1);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        snake.setFruitCoords(-1, std::rand() % 17 + 1);
        snake.setSnakeSize(snake.getSnakeSize() + 1);
        snake.setEating(true);
    }
    return 0;
}
