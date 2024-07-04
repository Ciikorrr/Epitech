/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Picture
*/

#include "Picture.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::Picture(const Picture &p)
{
    data = p.data;
}

Picture &Picture::operator=(const Picture &p)
{
    data = p.data;
    return *this;
}

Picture::Picture()
{
    data = "";
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    auto ss = std::ostringstream{};
    std::ifstream content(file);
    if (!(content.is_open())) {
        data = "ERROR";
        return false;
    }
    ss << content.rdbuf();
    this->data = ss.str();
    content.close();
    return true;
}