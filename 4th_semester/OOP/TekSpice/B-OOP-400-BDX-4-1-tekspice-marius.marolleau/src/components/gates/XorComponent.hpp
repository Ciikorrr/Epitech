/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class XorComponent : public nts::AComponent {
        public:
            XorComponent(std::string name);
            ~XorComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !XORCOMPONENT_HPP_ */
