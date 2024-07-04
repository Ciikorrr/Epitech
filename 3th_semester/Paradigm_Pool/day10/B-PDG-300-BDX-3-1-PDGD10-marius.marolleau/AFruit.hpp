/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_
#include "IFruit.hpp"

class AFruit : public IFruit{
    public:
        AFruit();
        ~AFruit();
        unsigned int getVitamins() const;
        std::string getName() const;
        bool isPeeled() const;
        void peel(); 
    protected:
        unsigned int _vitamins;
        std::string _name;
        bool _isPeeled;
        unsigned int _nbVit;
    private:
};

#endif /* !AFRUIT_HPP_ */
