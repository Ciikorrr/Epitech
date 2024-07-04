/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** DirectoryLitser
*/

#include "DirectoryLister.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>

DirectoryLister::DirectoryLister() : _hidden(false), _dir(nullptr)
{
}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden) : _hidden(hidden)
{
    this->_dir = opendir(path.c_str());
    if (!this->_dir) {
        this->_dir = nullptr;
        perror(path.c_str());
    }
}

DirectoryLister::~DirectoryLister()
{
    if (_dir)
        closedir(_dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    if (this->_dir)
        closedir(this->_dir);
    this->_dir = opendir(path.c_str());
    if (!this->_dir) {
        perror(path.c_str());
        return false;
    }   
    _hidden = hidden;
    return true;
}

std::string DirectoryLister::get()
{
    if (!_dir)
        return "";
    dirent *entry;
    while (!_hidden && (entry = readdir(_dir))) {
        if (entry->d_name[0] == '.')
            continue;
        return entry->d_name;
    }
    entry = readdir(_dir);
    if (!entry)
        return "";
    return entry->d_name;
}