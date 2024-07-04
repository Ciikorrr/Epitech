/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class InputComponent : public nts::AComponent {
        public:
            InputComponent(std::string name);
            ~InputComponent() = default;
            nts::Tristate compute(std::size_t pin) override;
        protected:
        private:
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
