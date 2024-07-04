/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include "IDirectoryLister.hpp"

class DirectoryLister : public IDirectoryLister {
    public:
        DirectoryLister();
        DirectoryLister(const std::string& path, bool hidden);
        DirectoryLister(const DirectoryLister &) = delete;
        DirectoryLister(DirectoryLister &&) = delete;
        DirectoryLister &operator=(DirectoryLister &) = delete;
        ~DirectoryLister();
        
        std::string get();
        bool open(const std::string& path, bool hidden);
    protected:
        bool _hidden;
        DIR *_dir;
    private:
};

#endif /* !DIRECTORYLISTER_HPP_ */
