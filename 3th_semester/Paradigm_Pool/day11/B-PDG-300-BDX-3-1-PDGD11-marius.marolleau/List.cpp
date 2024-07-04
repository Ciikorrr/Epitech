/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** List
*/

#include "List.hpp"

List::List()
{
}

List::~List()
{
    this->clear();
}

bool List::empty() const
{
    return this->list.empty();
}

std::size_t List::size() const
{
    return this->list.size();
}

IObject *&List::front()
{
    if (this->empty())
        throw List::InvalidOperationException();
    return this->list.front();
}

IObject *List::front() const
{
    if (this->empty())
        throw List::InvalidOperationException();
    return this->list.front();
}

IObject *&List::back()
{
    if (this->empty())
        throw List::InvalidOperationException();
    return this->list.back();
}

IObject *List::back() const
{
    if (this->empty())
        throw List::InvalidOperationException();
    return this->list.back();
}

void List::pushBack(IObject *obj)
{
    this->list.push_back(obj);
}

void List::pushFront(IObject *obj)
{
    this->list.push_front(obj);
}

void List::popBack()
{
    if (this->empty())
        throw List::InvalidOperationException();
    this->list.pop_back();
}

void List::popFront()
{
    if (this->empty())
        throw List::InvalidOperationException();
    this->list.pop_front();
}

void List::clear()
{
    for (auto elem : this->list) {
        delete elem;
    }
    this->list.clear();
}

void List::forEach(void(*function)(IObject*))
{
    for (auto elem : this->list) {
        function(elem);
    }
}