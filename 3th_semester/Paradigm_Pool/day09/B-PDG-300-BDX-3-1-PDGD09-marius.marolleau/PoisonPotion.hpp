/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
#define POISONPOTION_HPP_
#include "IPotion.hpp"

class PoisonPotion : public IPotion {
    public:
        PoisonPotion() {};
        int getHeal() const;
        int getPower() const;
    protected:
        const int _heal = -50;
        const int _power = 0;
    private:
};

#endif /* !POISONPOTION_HPP_ */
