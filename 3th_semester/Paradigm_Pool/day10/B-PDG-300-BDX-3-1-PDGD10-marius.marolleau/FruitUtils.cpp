/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "Lemon.hpp"
#include <cmath>
#include <iostream>
FruitUtils::FruitUtils()
{
}

FruitUtils::~FruitUtils()
{
}

void FruitUtils::sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry)
{
    for (auto elem : unsorted.getList()) {
        unsorted.popFruit();
        if (dynamic_cast<ABerry *>(elem)) {
            if (!berry.pushFruit(elem))
                unsorted.pushFruit(elem);
            continue;
        }
        if (dynamic_cast<Lemon *>(elem)) {
            if (!lemon.pushFruit(elem))
                unsorted.pushFruit(elem);
            continue;
        }
        if (dynamic_cast<ACitrus *>(elem)) {
            if (!citrus.pushFruit(elem))
                unsorted.pushFruit(elem);
            continue;
        }
        unsorted.pushFruit(elem);
    }
}

static double getSizeArray(IFruit **fruits)
{
    double len = 0;
    for (int i = 0; fruits[i] != nullptr; i++) {
        len++;
    }
    return len;
}

FruitBox** FruitUtils::pack(IFruit **fruits, unsigned int boxSize)
{
    int to_alloc = ceil(getSizeArray(fruits) / boxSize);
    FruitBox **array = new FruitBox*[to_alloc + 1];
    int i = 0;
    int idx = 0;
    array[to_alloc] = nullptr;
    while (i < to_alloc) {
        array[i] = new FruitBox(boxSize);
        while (idx < getSizeArray(fruits) && array[i]->pushFruit(fruits[idx])) {
            idx++;
        }
        i++;
    }
    return array;
}

IFruit **FruitUtils::unpack(FruitBox **FruitBoxes)
{
    int to_alloc = 0;
    int i = 0;
    int idx = 0;
    for (int i = 0; FruitBoxes[i] != nullptr; i++) {
        to_alloc += FruitBoxes[i]->getSize();
    }
    IFruit **tab = new IFruit*[to_alloc + 1];
    for (int i = 0; i <= to_alloc; i++) {
        tab[i] = nullptr;
    }
    while (FruitBoxes[i] != nullptr) {
        while ((int)(FruitBoxes[i]->nbFruits()) > 0) {
            tab[idx] = FruitBoxes[i]->popFruit();
            idx++;
        }
        i++;
    }
    return tab;
}
