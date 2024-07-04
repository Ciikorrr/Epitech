/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include <iostream>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false,
        None = 2,
    };
    enum Types {
        Gate,
        Input,
        Output
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void simulate(std::size_t tick) = 0;
            virtual void setLink(std::size_t entryOne, IComponent &gate, std::size_t entryTwo, size_t stop) = 0;
            virtual std::string getName() const = 0;
            virtual size_t getNbPins() const = 0;
            virtual nts::Tristate getState() const = 0;
            virtual nts::Types getType() const = 0;
            virtual void setWaitingState(nts::Tristate state) = 0;
        protected:
        private:
    };
}
#endif /* !ICOMPONENT_HPP_ */
