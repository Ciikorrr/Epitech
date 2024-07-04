/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class OutputComponent : public nts::AComponent {
        public:
            OutputComponent(std::string name);
            ~OutputComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
