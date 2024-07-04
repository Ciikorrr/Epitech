/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
#define SAFEDIRECTORYLISTER_HPP_
#include <sys/types.h>
#include <dirent.h>
#include <string>

class SafeDirectoryLister {
    public:
        SafeDirectoryLister();
        SafeDirectoryLister(const std::string& path, bool hidden);
        ~SafeDirectoryLister();
        std::string get();
        bool open(const std::string& path, bool hidden);
    protected:
        DIR *_dir;
        bool _hidden;
    private:
};

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
