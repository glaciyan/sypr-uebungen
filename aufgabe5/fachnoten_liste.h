//
// Created by kevin on 01.12.2022.
//

#ifndef AUFGABE5_FACHNOTEN_LISTE_H
#define AUFGABE5_FACHNOTEN_LISTE_H

#include "fachnote.h"

class fachnoten_liste final
{
private:
    class element;

    element *head;

    void (*delete_fachnote)(fachnote *);

public:
    explicit fachnoten_liste(void (*param)(fachnote *));

    ~fachnoten_liste();

    fachnoten_liste(const fachnoten_liste&) = delete;

    fachnoten_liste& operator=(const fachnoten_liste&) = delete;

    fachnoten_liste(fachnoten_liste&&) = delete;

    fachnoten_liste& operator=(fachnoten_liste&&) = delete;

    fachnoten_liste& insert(fachnote *);

    class iterator final
    {
    private:
        element *current;

        explicit iterator(element *);

    public:
        bool operator!=(const iterator&) const;

        fachnote *& operator*() const;

        iterator& operator++();

        friend class fachnoten_liste;

        typedef std::input_iterator_tag iterator_category;
        typedef fachnote *value_type;
        typedef std::ptrdiff_t difference_type;
        typedef fachnote **pointer;
        typedef fachnote *& reference;
    };

    iterator begin();

    iterator end();

    class const_iterator final
    {
    private:
        const element *current;

        explicit const_iterator(const element *);

    public:
        bool operator!=(const const_iterator&) const;

        const fachnote *operator*() const;

        const_iterator& operator++();

        friend class fachnoten_liste;

        typedef std::input_iterator_tag iterator_category;
        typedef const fachnote *value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const fachnote **pointer;
        typedef const fachnote *& reference;
    };

    const_iterator begin() const;

    const_iterator end() const;

    const_iterator cbegin() const;

    const_iterator cend() const;

};


#endif //AUFGABE5_FACHNOTEN_LISTE_H
