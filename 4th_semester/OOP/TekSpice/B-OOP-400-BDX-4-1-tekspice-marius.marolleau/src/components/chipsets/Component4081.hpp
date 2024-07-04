/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_
#include "../AComponent.hpp"

namespace nts {
    class Component4081 : public nts::AComponent{
        public:
            Component4081(std::string name);
            ~Component4081();
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}
#endif /* !COMPONENT4081_HPP_ */
