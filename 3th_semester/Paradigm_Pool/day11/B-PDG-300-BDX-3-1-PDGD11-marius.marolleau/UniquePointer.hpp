/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_
#include <string>
#include "IObject.hpp"

class UniquePointer : public IObject{
    public:
        UniquePointer() = default;
        UniquePointer(IObject *ptr);
        UniquePointer(const UniquePointer &copy) = delete;
        ~UniquePointer();
        UniquePointer &operator=(const UniquePointer &) = delete;
        UniquePointer *operator=(IObject *);
        IObject *operator->();
        IObject &operator*();
        void reset(IObject *ptr2);
        void reset();
        void touch() {};
        void swap(UniquePointer &ptr2);
    protected:
    private:
        IObject *ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
