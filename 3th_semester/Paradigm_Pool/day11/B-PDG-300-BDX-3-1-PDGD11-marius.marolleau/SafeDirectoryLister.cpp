/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"
#include "IDirectoryLister.hpp"
#include <string.h>

SafeDirectoryLister::SafeDirectoryLister() : _hidden(false)
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden) : _hidden(hidden)
{
    this->_dir = opendir(path.c_str());
    if (!this->_dir)
        throw IDirectoryLister::OpenFailureException();
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (_dir)
        closedir(_dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden)
{
    if (_dir)
        closedir(_dir);
    this->_dir = opendir(path.c_str());
    if (!this->_dir) {
        throw IDirectoryLister::OpenFailureException();
    }
    _hidden = hidden;
    return true;
}

std::string SafeDirectoryLister::get()
{
    if (!this->_dir)
        throw IDirectoryLister::OpenFailureException();
    dirent *entry;
    while (!_hidden && (entry = readdir(_dir))) {
        if (entry->d_name[0] == '.')
            continue;
        return entry->d_name;
    }
    entry = readdir(_dir);
    if (!entry)
        throw IDirectoryLister::NoMoreFileException();
    return entry->d_name;
}