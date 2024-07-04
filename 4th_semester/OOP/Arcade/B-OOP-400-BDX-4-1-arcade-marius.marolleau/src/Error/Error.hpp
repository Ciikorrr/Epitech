/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <string>

class ErrorParser : public std::exception {
    public:
        ErrorParser(std::string err_msg) : _msg(err_msg)
        {
        }
        const char *what() const noexcept
        {
            return _msg.c_str();
        }
        std::string _msg;
    protected:
    private:
};

class ErrorCore : public std::exception {
    public:
        ErrorCore(std::string err_msg) : _msg(err_msg)
        {
        }
        const char *what() const noexcept
        {
            return _msg.c_str();
        }
        std::string _msg;
    protected:
    private:
};

#endif /* !ERROR_HPP_ */
