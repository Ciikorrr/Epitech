/*
** EPITECH PROJECT, 2024
** y2
** File description:
** File
*/

#include "File.hpp"
#include <fstream>

File::File(const std::string &path)
    : m_Path(path)
{
}

File::~File()
{
}

std::string File::GetBuffer()
{
    std::ifstream ifs(m_Path, std::ios::binary);
    if (!ifs.is_open())
        return "";

    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return std::string(buffer.begin(), buffer.end());
}

std::vector<std::string> File::GetLines()
{
    std::ifstream ifs(m_Path);
    if (!ifs.is_open())
        return {};

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(ifs, line))
        lines.push_back(line);
    return lines;
}