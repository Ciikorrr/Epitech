/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_
#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string name, std::string ascii = "woody.txt");
        ~Woody();
        void speak(std::string statement);
    protected:
    private:
};

#endif /* !WOODY_HPP_ */
