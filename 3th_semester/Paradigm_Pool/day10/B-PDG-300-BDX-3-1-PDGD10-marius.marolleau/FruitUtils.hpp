/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
#define FRUITUTILS_HPP_
#include "FruitBox.hpp"

class FruitUtils {
    public:
        FruitUtils();
        ~FruitUtils();
        static void sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry);
        static FruitBox** pack(IFruit **fruits, unsigned int boxSize);
        static IFruit **unpack(FruitBox **fruitBoxes);
    protected:
    private:
};

#endif /* !FRUITUTILS_HPP_ */
