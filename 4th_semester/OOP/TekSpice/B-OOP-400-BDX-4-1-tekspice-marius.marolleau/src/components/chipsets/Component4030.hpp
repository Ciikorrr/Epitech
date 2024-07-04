/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_
#include "../AComponent.hpp"

namespace nts {
    class Component4030 : public nts::AComponent {
        public:
            Component4030(std::string name);
            ~Component4030();
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !COMPONENT4030_HPP_ */
