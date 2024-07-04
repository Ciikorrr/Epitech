/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class AndComponent : public nts::AComponent {
        public:
            AndComponent(std::string name);
            ~AndComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
