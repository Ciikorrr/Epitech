/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Circuit
*/
#include "components/IComponent.hpp"
#include "factory/Factory.hpp"
#include <iostream>
#include <memory>
#include <vector>
#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

class Circuit {
    public:
        Circuit(Factory &factory);
        ~Circuit();

        std::size_t getTick() const;
        void setTick(std::size_t tick);

        std::vector<std::shared_ptr<nts::IComponent>> gates;
        std::vector<std::shared_ptr<nts::IComponent>> inputs;
        std::vector<std::shared_ptr<nts::IComponent>> outputs;
    protected:
    private:
        std::size_t tick;
};

#endif /* !CIRCUIT_HPP_ */
