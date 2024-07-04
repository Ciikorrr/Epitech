/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class FalseComponent : public nts::AComponent {
        public:
            FalseComponent(std::string name);
            ~FalseComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
