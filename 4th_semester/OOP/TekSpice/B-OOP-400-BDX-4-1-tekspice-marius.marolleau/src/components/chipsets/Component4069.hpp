/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_
#include "../AComponent.hpp"

namespace nts {

    class Component4069 : public nts::AComponent {
        public:
            Component4069(std::string name);
            ~Component4069();
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}
#endif /* !COMPONENT4069_HPP_ */
