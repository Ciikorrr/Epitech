/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_
#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();
        void rest();
};

#endif /* !PRIEST_HPP_ */
