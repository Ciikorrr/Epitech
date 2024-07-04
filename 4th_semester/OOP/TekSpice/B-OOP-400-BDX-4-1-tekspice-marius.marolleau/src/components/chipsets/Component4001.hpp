/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_
#include "../AComponent.hpp"

namespace nts {
    class Component4001 : public nts::AComponent{
        public:
            Component4001(std::string name);
            ~Component4001();
            nts::Tristate compute(std::size_t pin) override;

        protected:
        private:
    };
}
#endif /* !COMPONENT4001_HPP_ */
