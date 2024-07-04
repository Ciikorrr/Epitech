/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_
#include <string>

class Picture {
    public:
        Picture(const std::string &file);
        Picture();
        Picture(const Picture &copy);
        Picture &operator=(const Picture &p);
        ~Picture();
        bool getPictureFromFile(const std::string &file);
        std::string data;
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
