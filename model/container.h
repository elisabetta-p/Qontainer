#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class container {
    friend class iteratore;
private:

    template<typename T1>
    class nodo {                // !!!!!!!!! inizio classe NODO !!!!!!!!!
    public:
        T1 info;
        nodo* next;
        nodo (T1, nodo*);
        ~nodo();
    };                          // !!!!!!!!! fine classe NODO !!!!!!!!!


    // dentro container
    nodo<T>* first;
    static nodo<T>* copia(nodo<T>*);
    static void distruggi(nodo<T>*);
public:
    class iterator {           // !!!!!!!!! inizio classe ITERATOR => dentro container<T> !!!!!!!!!
        friend class container;
    private:
        container::nodo<T>* punt;
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
        const container::nodo<T>* punt; //Definizione del puntatore come costante: non posso modificare il valore contenuto nell'indirizzo a cui punta tramite dereferenziazione
    public:
        bool operator==(const_iterator const_it) const;
        bool operator!= (const_iterator const_it) const;
        const_iterator& operator++() const; //operatore postfisso
        const_iterator operator++(int) const; //operatore prefisso
        const_iterator& operator--() const; //operatore postfisso
        const_iterator operator--(int) const;//operatore prefisso

    };                          // !!!!!!!!! fine classe CONST_ITERATOR !!!!!!!!!


    //                              !!!!!!! dentro CONTAINER !!!!!!!!
    container(nodo<T>* =0);
    ~container();
    container (const container&);
    container& operator=(const container& c);
    bool vuota() const;


    //metodi del contenitore invocati su iteratori costanti
    const_iterator begin() const;
    const_iterator end() const;

    //metodi del contenitore invocati su iteratori non costanti
    iterator begin();
    iterator end();

    // Overloading di * e []

    T& operator*() const;
    T& operator[] (const iterator& it) const;
    T& operator[] (const const_iterator& const_it) const;

    // METODI DA SPECIFICA

    void insert(T);
    void remove(T);
    bool search( T parametro) const;

    // ALTRI METODI UTILI

    unsigned int size() const;
};

//definizioni di nodo
template <typename T> template <typename T1>
container<T>::template nodo<T1>::nodo(T1 contenuto, nodo* n) : info(contenuto), next(n) {}

template<typename T> template <typename T1>
container<T>::template nodo<T1>::~nodo() {if (this) delete this;}

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
    if (punt && punt->next != nullptr) punt = punt->next;
    return *this;
}

template <typename T>
typename container<T>::iterator container<T>::iterator::operator++(int)  {
    iterator aux = *this;
    if (punt && punt->next != nullptr) punt = punt->next;
    return aux;
}

template <typename T>
typename container<T>::iterator& container<T>::iterator::operator--() {
    if (punt){
        iterator aux;
        punt = punt -1;
        return aux;
    }
    else return *this;
}

template <typename T>
typename container<T>::iterator container<T>::iterator::operator--(int) {
    if (punt) {
        iterator aux;
        aux = punt-1;
        if (punt==nullptr)
            return punt;
        return aux;
    }
    else return *this;
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
    if (punt && punt->next != nullptr) punt = punt->next;
    return *this;
}

template <typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator++(int)  const {
    iterator aux = *this;
    if (punt && punt->next != nullptr) punt = punt->next;
    return aux;
}

template <typename T>
typename container<T>::const_iterator& container<T>::const_iterator::operator--() const {
    if (punt){
        iterator aux;
        punt = punt -1;
        return aux;
    }
    else return *this;
}

template <typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator--(int) const {
    if (punt) {
        iterator aux;
        aux = punt-1;
        if (punt==nullptr)
            return punt;
        return aux;
    }
    else return *this;
}

//definizioni di container
template <typename T>
typename container<T>::template nodo<T>* container<T>::copia(nodo<T>* n) {
    if (!n)  return nullptr;
    else return new nodo<T> (n->info, copia (n->next));
}

template <typename T>
void container<T>::distruggi(nodo<T>* n) {
    if (n) {
        distruggi (n->next);
        delete n;
    }
}

template <typename T>
container<T>::container(nodo<T>* n) : first(n) {}

template <typename T>
container<T>::~container<T>() {if (first) delete(first);}

template <typename T>
container<T>::container(const container& c) : first(copia(c.first)) {}

template <typename T>
container<T>& container<T>::operator=(const container& c) {
    first = copia(c.first);
    return *this;
}

template <typename T>
bool container<T>::vuota() const {return first==0;}

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
    iterator aux;
    aux.punt = first;
    return aux;
}

template <typename T>
typename container<T>::const_iterator container<T>::end() const {
    iterator aux;
    aux.punt = nullptr;
    return aux;
}

//overloading di * e []
template <typename T>
T& container<T>::operator*() const {
    return *this->info;
}

template <typename T>
T& container<T>::operator[](const iterator& it) const {
    return (it.punt)->info;
}

template <typename T>
T& container<T>::operator[](const const_iterator& const_it) const {
    return (const_it.punt)->info;
}

//metodi da specifica
template <typename T>
void container<T>::insert(T contenuto) {
    first = new nodo<T>(contenuto, first);
    cout << "Il contenuto e' stato inserito!";
}

template <typename T>
void remove(T contenuto) {
    typename container<T>::template nodo<T>* n = container<T>::first, * prec = 0;
    while (n && !(n->info == contenuto)) {
        prec = n;
        n = n->next;
    }
    if (n) {
        if (!prec)
            container<T>::first = n -> next;
        else {
            prec -> next = n -> next;
        }
        cout << "Il contenuto e' stato eliminato!";
        delete n;
    }
}

template <typename T>
bool container<T>::search(T parametro) const {
    typename container<T>::template nodo<T>* n = container<T>::first;
    while (n->next != nullptr) {
        n = n->next;
        if (n->info == parametro)
            return true;
    }
    return false;
}

template <typename T>
unsigned int container<T>::size() const {
    if (container<T>::first) {
        nodo<T>* aux = first;
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



