/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
#define HEALTHPOTION_HPP_
#include "IPotion.hpp"

class HealthPotion : public IPotion {
    public:
        HealthPotion() {};
        int getHeal() const;
        int getPower() const;
    protected:
        const int _heal = 50;
        const int _power = 0;
    private:
};

#endif /* !HEALTHPOTION_HPP_ */
