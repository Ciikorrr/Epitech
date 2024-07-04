/*
** EPITECH PROJECT, 2024
** y2
** File description:
** File
*/

#pragma once
#include <string>
#include <vector>

class File {
    public:
        File(const std::string &path);
        ~File();

    public:
        std::string GetBuffer();
        std::vector<std::string> GetLines();
    
    private:
        std::string m_Path;
};
