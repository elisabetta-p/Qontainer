#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using std::cout;
using std::endl;


#include "contenutomultimediale.h"

template <class T>
class container {
    friend class iteratore;
private:



    class nodo {                // !!!!!!!!! inizio classe NODO !!!!!!!!!
    public:
        T info;
        nodo* next;
        nodo (T contenuto, nodo* n=0) : info(contenuto), next(n) {}
        ~nodo() {if (*this) delete[] *this;}
    };                          // !!!!!!!!! fine classe NODO !!!!!!!!!



    nodo* first;
    static nodo* copia(nodo* n) {
        if (!n) return nullptr;
        else {
            return new nodo (n->info, copia(n->next));
        }
    }
    static void distruggi(nodo* n) {
        if (n) {
            distruggi(n->next);
            delete[] n;
        }
    }
public:



    class iterator {           // !!!!!!!!! inizio classe ITERATOR !!!!!!!!!
        friend class container;
    private:
        container::nodo* punt;
    public:
        bool operator==(iterator it) const {
            return punt == it.punt;
        }
        bool operator!= (iterator it) const {
            return punt != it.punt;
        }
        iterator& operator++() { //operator++ prefisso
            if (punt && punt->next != nullptr) punt = punt->next;
            return *this;
        }
        iterator operator++(int) {
            iterator aux = *this;
            if (punt && punt->next != nullptr) punt = punt->next;
            return aux;
        } //operator++ postfisso
        iterator& operator--(){
            if (punt){
                iterator aux;
                punt = punt -1;
                return aux;
            }
            else return *this;
        } //operatore postfisso
        iterator operator--(int) {
            if (punt) {
                iterator aux;
                aux = punt-1;
                if (punt==nullptr)
                    return punt;
                return aux;
            }
            else return *this;
        } //operatore prefisso
    };                          // !!!!!!!!! fine classe ITERATOR !!!!!!!!!



    class const_iterator {      // !!!!!!!!! inizio classe CONST_ITERATOR !!!!!!!!!
        friend class container;
    private:
        const container::nodo* punt; //Definizione del puntatore come costante: non posso modificare il valore contenuto nell'indirizzo a cui punta tramite dereferenziazione
    public:
        bool operator==(const_iterator const_it) const {
            return punt == const_it.punt;
        }
        bool operator!= (const_iterator const_it) const {
            return punt != const_it.punt;
        }
        const_iterator& operator++() const {
            const_iterator aux = *this;
            if (punt && punt->next != nullptr) punt = punt->next;
            return aux;
        } //operatore postfisso
        const_iterator operator++(int) const {
            if (punt && punt->next != nullptr) punt = punt->next;
            return *this;
        } //operatore prefisso
        const_iterator& operator--() const{
            if (punt){
                iterator aux;
                punt = punt -1;
                return aux;
            }
            else return *this;
        } //operatore postfisso
        const_iterator operator--(int) const {
            if (punt) {
                iterator aux;
                aux = punt-1;
                if (punt==nullptr)
                    return punt;
                return aux;
            }
        else return *this;
    }//operatore prefisso

    };                          // !!!!!!!!! fine classe CONST_ITERATOR !!!!!!!!!


    //                              !!!!!!! dentro CONTAINER !!!!!!!!
    container(nodo* n=0) : first(n) {}
    ~container() {if(first) distruggi(first);}
    container (const container&);
    container& operator=(const container& c) {
        first = copia(c.first);
        return *this;
    }
    bool vuota() const {
        return first==0;
    }


    //metodi del contenitore invocati su iteratori costanti
    const_iterator begin() const {
        const_iterator aux;
        aux.punt=first;
        return aux;
    }
    const_iterator end() const {
        const_iterator aux;
        aux.punt = nullptr;
        return aux;
    }

    //metodi del contenitore invocati su iteratori non costanti
    iterator begin() {
        const_iterator aux;
        aux.punt=first;
        return aux;
    }
    iterator end() {
        iterator aux;
        aux.punt = nullptr;
        return aux;
    }

    // Overloading di * e []

    T& operator*() const {
        return *this->info;
    }

    T& operator[] (const iterator& it) const {
        return (it.punt)->info;
    }

    T& operator[] (const const_iterator& const_it) const {
        return (const_it.punt)->info;
    }

    // METODI DA SPECIFICA

    void insert(const T& cont) { //aggiunge un contenuto multimediale in testa alla lista di contenuti multimediali salvati sotto forma di nodi
        cout << "Il contenuto e' stato inserito!";
        first = new nodo(cont, first);
    }

    void remove(const T& cont) {
        nodo* n = first, * prec = 0;
        while (n && !(n->info == cont)) {
            prec = n;
            n = n->next;
        }
        if (n) {
            if (!prec)
                first = n -> next;
            else {
                prec -> next = n -> next;
            }
            cout << "Il contenuto e' stato eliminato!";
            delete n;
        }
    }

    bool search(const T& parametro) const {
        nodo* n = first;
        while (n->next != nullptr) {
            n = n->next;
            if (n->info == parametro)
                return true;
        }
        return false;
    }

    // ALTRI METODI UTILI

    unsigned int size() const { //ritorna il numero di elementi nel container
        if (first) {
            nodo* aux = first;
            unsigned int contatore=0;
            while (aux) {
                contatore++;
                aux = aux->next;
            }
            return contatore;
        }
    }
};

#endif // CONTAINER_H



