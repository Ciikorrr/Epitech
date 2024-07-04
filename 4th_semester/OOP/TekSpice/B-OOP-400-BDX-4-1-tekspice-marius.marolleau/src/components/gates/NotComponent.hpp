/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class NotComponent : public nts::AComponent {
        public:
            NotComponent(std::string name);
            ~NotComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
