/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_
#include "IFruit.hpp"
#include <list>

class FruitBox {
    public:
        FruitBox(unsigned int size);
        FruitBox(const FruitBox &copy) = delete;
        ~FruitBox();
        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *);
        IFruit *popFruit();
        void setNbFruit(int nb);
        std::list<IFruit *> getList() const;
        void setList(std::list<IFruit *> list);
    protected:
        unsigned int _size;
        unsigned int _nbFruit;
        std::list<IFruit *> box;
    private:

};

std::ostream &operator<<(std::ostream &s, FruitBox const &f1);
std::ostream &operator<<(std::ostream &s, IFruit const &f1);
#endif /* !FRUITBOX_HPP_ */
