/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** UniquePointer
*/

#include "UniquePointer.hpp"
#include <iostream>

UniquePointer::UniquePointer(IObject *ptr)
{
    this->ptr = ptr;
}

UniquePointer::~UniquePointer()
{
    if (this->ptr)
        delete this->ptr;
}

UniquePointer *UniquePointer::operator=(IObject *new_ptr)
{
    if (this->ptr)
        delete this->ptr;
    this->ptr = new_ptr;
    return this;
}

IObject *UniquePointer::operator->()
{
    return this->ptr;
}

IObject &UniquePointer::operator*()
{
    return *this->ptr;
}

void UniquePointer::reset(IObject *ptr2)
{
    if (this->ptr)
        delete this->ptr;
    this->ptr = ptr2;
}

void UniquePointer::reset()
{
    if (this->ptr)
        delete this->ptr;
    this->ptr = nullptr;
}

void UniquePointer::swap(UniquePointer &ptr2)
{
    IObject *temp = this->ptr;
    this->ptr = ptr2.ptr;
    ptr2.ptr = temp;
}