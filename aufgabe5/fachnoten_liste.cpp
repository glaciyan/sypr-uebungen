//
// Created by kevin on 01.12.2022.
//

#include "fachnoten_liste.h"

class fachnoten_liste::element final
{
    element *next;
    fachnote *n;

    element(element *e, fachnote *m)
            : next(e), n(m)
    {}

    friend class fachnoten_liste;

    friend class fachnoten_liste::iterator;
};

// iterator

fachnoten_liste::iterator::iterator(element *e)
        : current(e)
{}

bool fachnoten_liste::iterator::operator!=(const iterator& i) const
{
    return this->current != i.current;
}

fachnote *& fachnoten_liste::iterator::operator*() const
{
    return this->current->n;
}

fachnoten_liste::iterator& fachnoten_liste::iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

// const iterator

fachnoten_liste::const_iterator::const_iterator(const element *e)
        : current(e)
{}

bool fachnoten_liste::const_iterator::operator!=(const const_iterator& i) const
{
    return this->current != i.current;
}

const fachnote *fachnoten_liste::const_iterator::operator*() const
{
    return this->current->n;
}

fachnoten_liste::const_iterator& fachnoten_liste::const_iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

// ctor

fachnoten_liste::fachnoten_liste(void (*param)(fachnote *)) : head(nullptr), delete_fachnote(param)
{
}

fachnoten_liste::~fachnoten_liste()
{
    element *e = this->head;
    while (e != nullptr)
    {
        element *x = e;
        e = e->next;
        delete_fachnote(x->n);
        delete x;
    }
}

fachnoten_liste& fachnoten_liste::insert(fachnote *f)
{
    this->head = new element(this->head, f);
    return *this;
}

fachnoten_liste::iterator fachnoten_liste::begin()
{
    return fachnoten_liste::iterator(this->head);
}

fachnoten_liste::iterator fachnoten_liste::end()
{
    return fachnoten_liste::iterator(nullptr);
}

fachnoten_liste::const_iterator fachnoten_liste::begin() const
{
    return fachnoten_liste::const_iterator(this->head);
}

fachnoten_liste::const_iterator fachnoten_liste::end() const
{
    return fachnoten_liste::const_iterator(nullptr);
}

fachnoten_liste::const_iterator fachnoten_liste::cbegin() const
{
    return fachnoten_liste::const_iterator(this->head);
}

fachnoten_liste::const_iterator fachnoten_liste::cend() const
{
    return fachnoten_liste::const_iterator(nullptr);
}


