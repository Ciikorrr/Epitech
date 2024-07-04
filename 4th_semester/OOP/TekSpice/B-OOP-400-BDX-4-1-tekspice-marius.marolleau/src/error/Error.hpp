/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <string>

class Error : public std::exception {
    public:
        Error(std::string msg) : _msg(msg)
        {
        }
        const char *what() const noexcept
        {
            return this->_msg.c_str();
        }
        std::string _msg;

    protected:
    private:
};

#endif /* !ERROR_HPP_ */
