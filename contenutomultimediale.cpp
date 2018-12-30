#include "contenutomultimediale.h"


ContenutoMultimediale::ContenutoMultimediale(string titolo, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data) : titolo(titolo), durata(dur), genere(gen), dimensione(dim), valutazione(val), autore(aut), dataUscita(data) {}
/*ContenutoMultimediale::~ContenutoMultimediale() {}*/

bool ContenutoMultimediale::operator==(const ContenutoMultimediale& cont) const {
    return (titolo == cont.titolo && durata == cont.durata && genere == cont.genere && dimensione == cont.dimensione && valutazione == cont.valutazione && autore == cont.autore && dataUscita == cont.dataUscita);
}

// METODI SET
void ContenutoMultimediale::setTitolo(string titol) {
    titolo = titol;
}

void ContenutoMultimediale::setDurata(unsigned short int dur) {
    durata = dur;
}

void ContenutoMultimediale::setGenere(string gen) {
    genere = gen;
}

void ContenutoMultimediale::setAutore(string aut) {
    autore = aut;
}

void ContenutoMultimediale::setDataUscita(string data) {
    dataUscita = data;
}

// METODI GET

string ContenutoMultimediale::getTitolo() const {
    return titolo;
}

unsigned short int ContenutoMultimediale::getDurata() const {
    return durata;
}

string ContenutoMultimediale::getGenere() const {
    return genere;
}

unsigned short int ContenutoMultimediale::getValutazione() const {
    return valutazione;
}

string ContenutoMultimediale::getAutore() const {
    return autore;
}

string ContenutoMultimediale::getDataUscita() const {
    return dataUscita;
}
