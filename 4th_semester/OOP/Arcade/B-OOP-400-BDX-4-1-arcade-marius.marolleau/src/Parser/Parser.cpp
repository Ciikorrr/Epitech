/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** Parser
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "../Error/Error.hpp"
#include <cstdlib>

std::string tabLib[13] = {"lib/arcade_ndk++.so",
                        "lib/arcade_aalib.so",
                        "lib/arcade_libcaca.so",
                        "lib/arcade_allegro5.so",
                        "lib/arcade_xlib.so",
                        "lib/arcade_gtk+.so",
                        "lib/arcade_sfml.so",
                        "lib/arcade_irrlicht.so",
                        "lib/arcade_opengl.so",
                        "lib/arcade_vulkan.so",
                        "lib/arcade_ncurses.so",
                        "lib/arcade_sdl2.so",
                        "lib/arcade_qt5.so"};

static 
void displayUsage(void)
{
    std::ifstream ifs("src/Parser/usage.txt");
    std::string line;

    if (!ifs.is_open())
        return;
    while (std::getline(ifs, line))
        std::cout << line << std::endl;
    return;
}

bool checkLib(char **argv)
{
    std::ifstream file(argv[1]);
    
    if (!file.is_open())
        throw ErrorParser("Can't open the library.");
    file.close();
    for (auto elem : tabLib)
        if (elem == argv[1])
            return true;
    throw ErrorParser("This library isn't authorized.");
}

bool checkEnv()
{
    char* display = std::getenv("DISPLAY");

    if (display == nullptr) {
        return false;
    }
    return true;
}

bool checkArgs(const int argc, char **argv)
{
    try {
        if (argc != 2) {
            displayUsage();
            throw ErrorParser("Bad args.");
        }
        if (!checkLib(argv))
            throw ErrorParser("Bad lib !");
        if (!checkEnv())
            throw ErrorParser("Bad env !");
    }
    catch (const ErrorParser &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}
