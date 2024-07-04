/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_
#include "../AComponent.hpp"

namespace nts {

    class Component4011 : public nts::AComponent {
        public:
            Component4011(std::string name);
            ~Component4011();
            nts::Tristate compute(std::size_t pin) override;


        protected:
        private:
    };
}

#endif /* !COMPONENT4011_HPP_ */
