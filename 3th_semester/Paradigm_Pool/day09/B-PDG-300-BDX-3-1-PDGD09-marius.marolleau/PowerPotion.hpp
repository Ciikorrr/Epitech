/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
#define POWERPOTION_HPP_
#include "IPotion.hpp"

class PowerPotion : public IPotion {
    public:
        PowerPotion() {};
        int getPower() const;
        int getHeal() const;
    protected:
        const int _power = 50;
        const int _heal = 0;
    private:
};

#endif /* !POWERPOTION_HPP_ */
