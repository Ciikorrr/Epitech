/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"
#include <string.h>


const char *IDirectoryLister::OpenFailureException::what()const noexcept
{
    return strerror(errno);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}