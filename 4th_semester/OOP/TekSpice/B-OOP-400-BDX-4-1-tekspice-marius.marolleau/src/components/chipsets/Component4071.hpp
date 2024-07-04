/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4071
*/

#ifndef COMPONENT4071_HPP_
#define COMPONENT4071_HPP_
#include "../AComponent.hpp"

namespace nts {
    class Component4071 : public nts::AComponent {
        public:
            Component4071(std::string name);
            ~Component4071();
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !COMPONENT4071_HPP_ */
