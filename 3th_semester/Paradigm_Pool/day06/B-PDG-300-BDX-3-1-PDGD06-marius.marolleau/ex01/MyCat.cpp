/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** MyCat
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

int main(int argc, char *argv[]) 
{
    std::ifstream ifs;
    bool error = false;
    std::string line;

    char c;
    if (argc == 1) {
        while (getline(std::cin, line)) {
            std::cout << line << std::endl;
        }
    }
    for (int i = 1;  i < argc; i++) {
        ifs.open (argv[i], std::ifstream::in);
        c = ifs.get();
        if (!ifs.is_open()) {
            std::cerr << "MyCat: "<< argv[i] << ": No such file or directory\n";
            error = true;
        } else {
            while (ifs.good()) {
                std::cout << c;
                c = ifs.get();
            }
        }
        ifs.close();
    }
    if (error)
        return 84;
    return 0;
}