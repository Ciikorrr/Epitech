/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class ClockComponent : public nts::AComponent {
        public:
            ClockComponent(std::string name);
            ~ClockComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
