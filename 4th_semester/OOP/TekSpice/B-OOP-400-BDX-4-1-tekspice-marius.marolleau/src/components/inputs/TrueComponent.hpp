/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class TrueComponent : public nts::AComponent {
        public:
            TrueComponent(std::string name);
            ~TrueComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
