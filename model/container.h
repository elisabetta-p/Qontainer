#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

template <class T>
class container {
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
    size_t findCaseInsensitive(string, string, size_t =0);

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
        T& operator*() const;
        nodo* operator->() const;
    };                          // !!!!!!!!! fine classe ITERATOR !!!!!!!!!



    class const_iterator {      // !!!!!!!!! inizio classe CONST_ITERATOR !!!!!!!!!
        friend class container;
    private:
        const container::nodo* punt; //Definizione del puntatore come costante: non posso modificare il valore contenuto nell'indirizzo a cui punta tramite dereferenziazione
    public:
        bool operator==(const_iterator const_it) const;
        bool operator!= (const_iterator const_it) const;
        const_iterator& operator++() ; //operatore postfisso
        const_iterator operator++(int) ; //operatore prefisso
        const_iterator& operator--() ; //operatore postfisso
        const_iterator operator--(int) ;//operatore prefisso
        T& operator*();
        nodo* operator->() const;

    };                          // !!!!!!!!! fine classe CONST_ITERATOR !!!!!!!!!


    //                              !!!!!!! dentro CONTAINER !!!!!!!!
    container(nodo* = nullptr);

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



    T operator[] (const iterator& it) const;
    T operator[] (const const_iterator& const_it) const;

    // METODI DA SPECIFICA

    void insert(const T);
    void remove(T);
    vector<T> search (T parametro);

    // ALTRI METODI UTILI

    unsigned int size() const;
};


//definizioni di nodo
template <typename T>
container<T>::nodo::nodo(T contenuto, nodo* p, nodo* n) : info(contenuto), prev(p), next(n) {}

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
typename container<T>::const_iterator& container<T>::const_iterator::operator++()  {
    if (punt) punt = punt->next;
    return *this;
}

template <typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator++(int)  {
    iterator aux = *this;
    if (punt) punt = punt->next;
    return aux;
}

template <typename T>
typename container<T>::const_iterator& container<T>::const_iterator::operator--()  {
    if (punt->prev)
        punt = punt->prev;
    else
        punt = nullptr;
    return *this;
}

template <typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator--(int)  {
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
        std::cout << "COPIA ";
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

template <typename T>
container<T>& container<T>::operator=(const container& c) {
    if (c != *this) {
        delete first;
        first = copia(c.first);
    }
    return *this;
}

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

//overloading di * e []
template <typename T>
T& container<T>::iterator::operator*() const {
    return  punt->info;
}

template <typename T>
typename container<T>::nodo* container<T>::iterator::operator->() const {
    return punt;
}

template <typename T>
T& container<T>::const_iterator::operator*(){
    return  punt->info;
}

template <typename T>
typename container<T>::nodo* container<T>::const_iterator::operator->() const {
    return punt;
}


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
}


template <typename T>
void container<T>::remove(T contenuto) {
    nodo* n = first;
    while (n && !(n->info == contenuto)) {
        n = n->next;
    }
    if(n) {
        //si deve eliminare il primo nodo
        if(!n->prev) {
          first = n->next;
          // Esiste il secondo nodo del container
          if(first)
            first->prev = nullptr;
        }
        //si deve eliminare un nodo in mezzo alla lista o l'ultimo
        else {
          n->prev->next = n->next;
          //esiste il nodo successivo a quello da eliminare
          if(n->next)
            n->next->prev = n->prev;
        }
        delete n;
  }
}

template <typename T>
size_t container<T>::findCaseInsensitive(string data, string daCercare, size_t pos) { //di default pos = 0
    /*
    * trasforma l'intera stringa in minuscolo
    */
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c)->unsigned char {return std::tolower(c);});
    /*
    * trasforma una sottostringa data in minuscolo
    */
    std::transform(daCercare.begin(), daCercare.end(), daCercare.begin(), [](unsigned char c)->unsigned char {return std::tolower(c);});
    /*
    * trova la sottostringa nella stringa data
    */
    return data.find(daCercare, pos);
}


template <typename T>
vector<T> container<T>::search(T contenuto) {
    nodo* n = first;
    vector<T> aux;
    while (n) {
        if( (findCaseInsensitive(n->info->getTitolo(), contenuto->getTitolo())) != std::string::npos &&
            (findCaseInsensitive(n->info->getAutore(), contenuto->getAutore())) != std::string::npos &&
            (n->info->getDataUscita() == contenuto->getDataUscita() || contenuto->getDataUscita() == 0) ) {
          aux.push_back(n->info);
        }
        n=n->next;
    }
    return aux;
}
/*
template <typename T>
vector<T> container<T>::search(T contenuto) const {
    nodo* n = first;
    vector<T> aux;
    while (n) {
        if ( (n->info->getTitolo().find(contenuto->getTitolo())!=std::string::npos) &&
             (n->info->getAutore().find(contenuto->getAutore())!=std::string::npos) &&
             (n->info->getDataUscita() == contenuto->getDataUscita() || contenuto->getDataUscita() == 0) )
            aux.push_back(n->info);
        }
        n = n->next;
    }
    return aux;
}
*/
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
