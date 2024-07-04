/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** SnakeModule
*/

#ifndef SNAKEMODULE_HPP_
#define SNAKEMODULE_HPP_
#include "../AGameModule.hpp"
#include <vector>
#include <iostream>
#include <iomanip>

class SnakeModule : public AGameModule {
    public:
        SnakeModule(std::string lib);
        ~SnakeModule() = default;

        int getFruitCoords(bool first) const override;
        std::pair<int, int> getFruitCoords() const override;
        void setFruitCoords(int first, int second) override;
        void setFruitVisible(int index [[maybe_unused]], bool b [[maybe_unused]]) {};
        std::vector<std::pair<std::pair<int, int>, bool>> getFruitsCoords() const
        {
            std::vector<std::pair<std::pair<int, int>, bool>> unused;
            return unused;
        }
        std::pair<std::pair<int, int>, bool> getFruitsCoords(int index [[maybe_unused]]) const
        {
            std::pair<std::pair<int, int>, bool> unused;
            return unused;
        }
        std::vector<std::pair<int, int>> getWalls() const
        {
            std::vector<std::pair<int, int>> unused;
            return unused;
        }

        int (*snakeAlgo)(IGameModule &snake);

        int gameAlgorithm(IGameModule &snake) override;
    protected:
    private:
        const int width;
        const int height;
        std::pair<int, int> fruitCoords;
};

#endif /* !SNAKEMODULE_HPP_ */
