/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include "../error/Error.hpp"
#include <iostream>
#include <vector>
#include "../error/Error.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent();
            ~AComponent() = default;

            void simulate(std::size_t tick) override;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            void setLink(std::size_t entryOne, IComponent &gate, std::size_t entryTwo, size_t stop) override;
            std::string getName() const override;
            size_t getNbPins() const override;
            nts::Tristate getState() const override;
            nts::Types getType() const override;
            void setWaitingState(nts::Tristate state) override;

        protected:
            size_t _nbPins;
            std::vector<nts::IComponent *> links;
            std::vector<size_t> pins;
            std::string _name;
            nts::Tristate state;
            nts::Tristate waitingValue;
            nts::Types _type;
        private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
