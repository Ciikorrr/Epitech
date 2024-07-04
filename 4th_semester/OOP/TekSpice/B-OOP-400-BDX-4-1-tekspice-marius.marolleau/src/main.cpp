/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** main
*/

#include <string>
#include <iostream>
#include "factory/Factory.hpp"

int hubFunctionManager(std::string filePath);

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return ERROR;
    return hubFunctionManager(argv[1]);
}