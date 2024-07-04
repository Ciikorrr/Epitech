/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include "components/IComponent.hpp"
#include "components/inputs/FalseComponent.hpp"
#include "components/inputs/TrueComponent.hpp"
#include "components/gates/OrComponent.hpp"
#include "components/gates/XorComponent.hpp"
#include "components/gates/NotComponent.hpp"
#include "components/gates/AndComponent.hpp"
#include "components/inputs/InputComponent.hpp"
#include "components/output/OutputComponent.hpp"
#include "components/inputs/ClockComponent.hpp"
#include "components/chipsets/Component4071.hpp"
#include "components/chipsets/Component4030.hpp"
#include "components/chipsets/Component4081.hpp"
#include "components/chipsets/Component4001.hpp"
#include "components/chipsets/Component4011.hpp"
#include "components/chipsets/Component4069.hpp"
#include <vector>
#include <memory>

#define SUCCESS 0
#define ERROR 84

class Factory {
    public:
        Factory() = default;
        ~Factory() = default;

        void createComponent(const std::string &type, std::string name);

        std::shared_ptr<nts::IComponent> createTrue(std::string name) const;
        std::shared_ptr<nts::IComponent> createFalse(std::string name) const;
        std::shared_ptr<nts::IComponent> createOr(std::string name) const;
        std::shared_ptr<nts::IComponent> createXor(std::string name) const;
        std::shared_ptr<nts::IComponent> createNot(std::string name) const;
        std::shared_ptr<nts::IComponent> createAnd(std::string name) const;
        std::shared_ptr<nts::IComponent> createInput(std::string name) const;
        std::shared_ptr<nts::IComponent> createOutput(std::string name) const;
        std::shared_ptr<nts::IComponent> createClock(std::string name) const;
        std::shared_ptr<nts::IComponent> create4071(std::string name) const;
        std::shared_ptr<nts::IComponent> create4030(std::string name) const;
        std::shared_ptr<nts::IComponent> create4081(std::string name) const;
        std::shared_ptr<nts::IComponent> create4011(std::string name) const;
        std::shared_ptr<nts::IComponent> create4069(std::string name) const;

        std::vector<std::shared_ptr<nts::IComponent>> getComponents() const;

    protected:
    private:
        std::vector<std::shared_ptr<nts::IComponent>> components;
};

#endif /* !FACTORY_HPP_ */
