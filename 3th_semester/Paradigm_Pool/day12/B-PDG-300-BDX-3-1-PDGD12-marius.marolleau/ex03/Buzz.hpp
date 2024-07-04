/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_
#include "Toy.hpp"
#include <string>

class Buzz : public Toy {
    public:
        Buzz(std::string name, std::string ascii = "buzz.txt");
        ~Buzz();
        void speak(std::string statement);

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
