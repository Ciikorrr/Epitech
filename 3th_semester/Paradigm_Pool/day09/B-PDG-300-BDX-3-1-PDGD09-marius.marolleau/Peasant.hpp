/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Peasant
*/
#ifndef PEASANT_HPP_
#define PEASANT_HPP_
#include <string>
#include "ICharacter.hpp"
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"


class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        int attack();
        int special();
        void rest();
        void damage(int damage);
        void drink(const IPotion &potion);
        void drink(const HealthPotion &potion);
        void drink(const PowerPotion &potion);
        void drink(const PoisonPotion &potion);
    protected:
        std::string _name;
        int _power;
        int _health;
    private:
};

#endif /* !PEASANT_HPP_ */
