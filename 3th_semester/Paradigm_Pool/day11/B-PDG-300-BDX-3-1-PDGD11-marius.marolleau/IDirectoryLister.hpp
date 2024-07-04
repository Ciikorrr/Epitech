/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
#define IDIRECTORYLISTER_HPP_
#include <string>
#include <exception>

class IDirectoryLister {
    public:
        virtual std::string get() = 0;
        virtual bool open(const std::string& path, bool hidden) = 0;
        class OpenFailureException : public std::exception {
            public:
                const char *what() const noexcept;
            protected:
            private:
        };
        class NoMoreFileException : public std::exception {
            public:
                const char *what() const noexcept;
            protected:
            private:
        };
    protected:
    private:
};

#endif /* !IDIRECTORYLISTER_HPP_ */
