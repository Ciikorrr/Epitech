/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-marius.marolleau
** File description:
** test_main
*/
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test(string_t *this, const char *s)
{
    this->split_c = (&split_c);
    this->find_c = (&find_c);
    this->find_s = (&find_s);
    this->copy = (&copy);
    this->insert_c = (&insert_c);
    this->insert_s = (&insert_s);
    this->print = (&print);
}

void string_init(string_t *this, const char *s)
{
    if (!this || !s)
        return;
    this->str = strdup(s);
    this->assign_c = (&assign_c);
    this->assign_s = (&assign_s);
    this->append_c = (&append_c);
    this->append_s = (&append_s);
    this->at = (&do_at);
    this->clear = (&clear);
    this->length = (&length);
    this->compare_c = (&compare_c);
    this->compare_s = (&compare_s);
    this->c_str = (&c_str);
    this->empty = (&empty);
    this->to_int = (&to_int);
    test(this, s);
}

void string_destroy(string_t *this)
{
    if (!this)
        return;
    free(this->str);
    return;
}
