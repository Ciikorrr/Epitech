/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Enchanter
*/
#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_
#include <string>
#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();
        int attack();
        int special();
        void rest();
};

#endif /* !ENCHANTER_HPP_ */
