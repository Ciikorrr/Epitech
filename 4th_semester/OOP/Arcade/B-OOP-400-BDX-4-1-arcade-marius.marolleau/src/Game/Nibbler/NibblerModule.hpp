/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** NibblerModule
*/

#ifndef NIBBLERMODULE_HPP_
#define NIBBLERMODULE_HPP_
#include "../AGameModule.hpp"

class NibblerModule : public AGameModule {
    public:
        NibblerModule(std::string lib);
        ~NibblerModule() = default;

        virtual void setFruitCoords(int first [[maybe_unused]], int second [[maybe_unused]]) {};
        void setFruitVisible(int index, bool b) override;
        virtual int getFruitCoords(bool first [[maybe_unused]]) const {return 0;};
        virtual std::pair<int, int> getFruitCoords() const
        {
            std::pair<int, int> unused;
            return unused;
        }
        std::vector<std::pair<int, int>> getWalls() const override;
        std::vector<std::pair<std::pair<int, int>, bool>> getFruitsCoords() const override;
        std::pair<std::pair<int, int>, bool> getFruitsCoords(int index) const override;

        void setFruits();
        void setWalls();

        int (*nibblerAlgo)(IGameModule &snake);

        int gameAlgorithm(IGameModule &snake) override;

    protected:
    private:
        const int width;
        const int height;
        std::vector<std::pair<int, int>> walls;
        std::vector<std::pair<std::pair<int, int>, bool>> fruits;
};

#endif /* !NIBBLERMODULE_HPP_ */
