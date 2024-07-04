/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
        public:
            OrComponent(std::string name);
            ~OrComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}

#endif /* !ORCOMPONENT_HPP_ */
