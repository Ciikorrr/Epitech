/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** main
*/

#include "Composite.hpp"
#include "GUI/Display.hpp"
#include "Parser.hpp"
#include "Renderer.hpp"
#include <cstring>
#include <iostream>

int handle_args(int argc, const char *argv[])
{
    if (argc > 3 || argc < 2)
        return 84;
    if (argc == 2 && strcmp(argv[1], "--help") != 0) // NOLINT
        return 0;
    if (argc == 2 || strcmp(argv[2], "--sfml") != 0) { // NOLINT
        std::cout << "USAGE: ./raytracer <scene-file> [--sfml]" <<std::endl
                << "    - <scene-file> file containing the scene configuration" << std::endl
                << "    - --sfml to display in a window (movable camera)" << std::endl
                << "            ZQSD (deplacement), arrows (cam), Enter(save Picture)" << std::endl;
        return 84;
    }
    return 1;
}


int main(int argc, const char *argv[])
{
    int arg = handle_args(argc, argv);
    if (arg == 84)
        return 84;
    try {
        raytracer::Parser parser(argv[1]);
        raytracer::Composite composite(parser.factory.m_shapes);
        raytracer::Renderer renderer {parser.camera, parser.lights};
        raytracer::Display {renderer, arg != 0, composite};
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "Error reading the file." << std::endl;
        return 84;
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at line " << pex.getLine()
                  << ": " << pex.getError() << std::endl;
        return 84;
    }
    return 0;
}
