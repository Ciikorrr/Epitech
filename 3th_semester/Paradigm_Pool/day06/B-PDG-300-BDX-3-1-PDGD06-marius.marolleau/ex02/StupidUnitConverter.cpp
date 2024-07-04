/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** StupidUnitConverter
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


int converter(double number, std::string type)
{
    float calcul = 0;

    if ("Fahrenheit" == type) {
        calcul = (5.0 / 9.0 * (number - 32));
        std::cout << std::setw(16) << std::fixed <<std::setprecision(3) << calcul <<std::setw(16) << "Celsius" << std::endl;
    } else if ("Celsius" == type) {
        calcul = number * 9 / 5 + 32;
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << calcul <<std::setw(16) << "Fahrenheit" << std::endl;
    }
    return 0;
}

int main(void)
{
    std::string parse;
    double number;
    std::string type;

    while (getline(std::cin, parse)) {
        std::stringstream ss(parse);
        ss >> number >> type;
        converter(number, type);
    }
    return 0;
}