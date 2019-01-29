#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

template <class T>
class container {
    friend class iteratore;
private:

    class nodo {                // !!!!!!!!! inizio classe NODO !!!!!!!!!
    public:
        T info;
        nodo* prev, *next;
        nodo (T, nodo*, nodo*);
        ~nodo();
    };                          // !!!!!!!!! fine classe NODO !!!!!!!!!


    // dentro container
    nodo* first ;


    static nodo* copia(nodo*);
    static void distruggi(nodo*);
public:

    class iterator {           // !!!!!!!!! inizio classe ITERATOR => dentro container<T> !!!!!!!!!
        friend class container;
    private:
        container::nodo* punt;
    public:
        bool operator==(iterator) const;
        bool operator!= (iterator) const;
        iterator& operator++(); //operator++ prefisso
        iterator operator++(int); //operator++ postfisso
        iterator& operator--(); //operatore postfisso
        iterator operator--(int); //operatore prefisso
    };                          // !!!!!!!!! fine classe ITERATOR !!!!!!!!!



    class const_iterator {      // !!!!!!!!! inizio classe CONST_ITERATOR !!!!!!!!!
        friend class container;
    private:
        const container::nodo* punt; //Definizione del puntatore come costante: non posso modificare il valore contenuto nell'indirizzo a cui punta tramite dereferenziazione
    public:
        bool operator==(const_iterator const_it) const;
        bool operator!= (const_iterator const_it) const;
        const_iterator& operator++() const; //operatore postfisso
        const_iterator operator++(int) const; //operatore prefisso
        const_iterator& operator--() const; //operatore postfisso
        const_iterator operator--(int) const;//operatore prefisso

    };                          // !!!!!!!!! fine classe CONST_ITERATOR !!!!!!!!!


    //                              !!!!!!! dentro CONTAINER !!!!!!!!
    container(nodo* = nullptr);

    ~container();
    container (const container&);
    //container& operator=(const container& c);

    bool vuota() const;

    //metodi del contenitore invocati su iteratori costanti
    const_iterator begin() const;
    const_iterator end() const;

    //metodi del contenitore invocati su iteratori non costanti
    iterator begin();
    iterator end();

    // Overloading di * e []

    //T& operator*() const;

    T operator[] (const iterator& it) const;
    T operator[] (const const_iterator& const_it) const;

    // METODI DA SPECIFICA

    void insert(const T);
    void remove(T);
    bool search(T parametro) const;

    // ALTRI METODI UTILI

    unsigned int size() const;
};

//definizioni di nodo
template <typename T>
container<T>::nodo::nodo(T contenuto, nodo* p, nodo* n) : info(contenuto), next(n), prev(p) {}

template<typename T>
container<T>::nodo::~nodo() {if (info) delete info;}

//definizioni di iterator
template <typename T>
bool container<T>::iterator::operator==(iterator it) const {
    return punt == it.punt;
}

template <typename T>
bool container<T>::iterator::operator!=(iterator it) const {
    return punt != it.punt;
}

template <typename T>
typename container<T>::iterator& container<T>::iterator::operator++() {
    if (punt) punt = punt->next;
    return *this;
}

template <typename T>
typename container<T>::iterator container<T>::iterator::operator++(int)  {
    iterator aux = *this;
    if (punt) punt = punt->next;
    return aux;
}

template <typename T>
typename container<T>::iterator& container<T>::iterator::operator--() {
    if (punt->prev)
        punt = punt->prev;
    else
        punt = nullptr;
    return *this;
}

template <typename T>
typename container<T>::iterator container<T>::iterator::operator--(int) {
    iterator aux;
    aux.punt = punt;
    if (punt->prev)
        punt = punt->prev;
    else
        punt = nullptr;
    return aux;
}

//definizioni di const_iterator

template <typename T>
bool container<T>::const_iterator::operator==(const_iterator const_it) const {
    return punt == const_it.punt;
}

template <typename T>
bool container<T>::const_iterator::operator!=(const_iterator const_it) const {
    return punt != const_it.punt;
}

template <typename T>
typename container<T>::const_iterator& container<T>::const_iterator::operator++() const {
    if (punt) punt = punt->next;
    return *this;
}

template <typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator++(int)  const {
    iterator aux = *this;
    if (punt) punt = punt->next;
    return aux;
}

template <typename T>
typename container<T>::const_iterator& container<T>::const_iterator::operator--() const {
    if (punt->prev)
        punt = punt->prev;
    else
        punt = nullptr;
    return *this;
}

template <typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator--(int) const {
    iterator aux;
    aux.punt = punt;
    if (punt->prev)
        punt = punt->prev;
    else
        punt = nullptr;
    return aux;
}

//definizioni di container
template <typename T>
typename container<T>::nodo* container<T>::copia(nodo* n) {
    if (!n)  {
        return nullptr;
    }
    else {
        nodo* aux = new nodo (n->info, nullptr, copia (n->next));
        std::cout << "here";
        if (aux->next)
            aux->next->prev = aux;
        return aux;
    }
}

template <typename T>
void container<T>::distruggi(nodo* n) {
    if (n) {
        distruggi (n->next);
        delete n;
    }
}


template <typename T>
container<T>::container(nodo* n) : first(n) {}


template <typename T>
container<T>::~container<T>() {if (first) delete(first);}

template <typename T>
container<T>::container(const container<T>& c) : first(copia(c.first)) {}
/*
template <typename T>
container<T>& container<T>::operator=(const container& c) {
    if (c != *this) {
        delete first;
        first = copia(c.first);
    }
    return *this;
}
*/
template <typename T>
bool container<T>::vuota() const {return first==nullptr;}

//definizione dei metodi da invocare sugli iteratori
template <typename T>
typename container<T>::iterator container<T>::begin() {
    iterator aux;
    aux.punt = first;
    return aux;
}

template <typename T>
typename container<T>::iterator container<T>::end() {
    iterator aux;
    aux.punt = nullptr;
    return aux;
}
//definizione dei metodi da invocare sugli iteratori costanti
template <typename T>
typename container<T>::const_iterator container<T>::begin() const {
    const_iterator aux;
    aux.punt = first;
    return aux;
}

template <typename T>
typename container<T>::const_iterator container<T>::end() const {
    const_iterator aux;
    aux.punt = nullptr;
    return aux;
}
/*
//overloading di * e []
template <typename T>
T& container<T>::operator*() const {
    return this->info;
}
*/
template <typename T>
T container<T>::operator[](const iterator& it) const {
    return (it.punt)->info;
}

template <typename T>
T container<T>::operator[](const const_iterator& const_it) const {
    return (const_it.punt)->info;
}

//metodi da specifica
template <typename T>
void container<T>::insert(const T contenuto) {
    first = new nodo(contenuto, nullptr, first);

    if(first->next)
        first->next->prev = first;

    std::cout << "Il contenuto e' stato inserito!" << std::endl;
}


template <typename T>
void container<T>::remove(T contenuto) {
    nodo* n = first;
    while (n && !(n->info == contenuto)) {
        n = n->next;
    }

    if (n) {
        if (!n->prev) {
            first = n -> next;
            first -> prev = nullptr;
        }
        else if(!n->next){
            n -> prev -> next = nullptr;
        }
        else {
            n -> prev -> next = n -> next;
            n -> next -> prev = n -> prev;
        }
        delete n;

    }

}

template <typename T>
bool container<T>::search(T contenuto) const {
    nodo* n = first;
    while (n) {
        if (n->info == contenuto)
            return true;
        n = n->next;
    }
    return false;
}

template <typename T>
unsigned int container<T>::size() const {
    if (first) {
        nodo* aux = first;
        unsigned int contatore=0;
        while (aux) {
            contatore++;
            aux = aux->next;
        }
        return contatore;
    }
    else return 0;
}

#endif // CONTAINER_H



