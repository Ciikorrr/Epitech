/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_
#include <string>
#include "IObject.hpp"
#include <list>
#include <exception>

class List {
    public:
        List();
        List(const List &) = delete;
        List &operator=(const List &) = delete;
        ~List();
        bool empty() const;
        std::size_t size() const;
        IObject *&front();
        IObject *front() const;
        IObject *&back();
        IObject *back() const;
        void pushBack(IObject *obj);
        void pushFront(IObject *obj);
        void popFront();
        void popBack();
        void clear();
        void forEach(void(*function)(IObject*));
        class InvalidOperationException : public std::exception {
            public:
        };
    protected:
    private:
        std::list<IObject *> list;
};

#endif /* !LIST_HPP_ */
