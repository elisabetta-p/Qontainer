#include "contenutomultimediale.h"


ContenutoMultimediale::ContenutoMultimediale(QString titolo, unsigned short int dur, QString gen, double dim, unsigned short int val, QString aut, QString data) : titolo(titolo), durata(dur), genere(gen), dimensione(dim), valutazione(val), autore(aut), dataUscita(data) {}
/*ContenutoMultimediale::~ContenutoMultimediale() {}*/

bool ContenutoMultimediale::operator==(const ContenutoMultimediale& cont) const {
    return (titolo == cont.titolo && durata == cont.durata && genere == cont.genere && dimensione == cont.dimensione && valutazione == cont.valutazione && autore == cont.autore && dataUscita == cont.dataUscita);
}

// METODI SET
void ContenutoMultimediale::setTitolo(QString titol) {
    titolo = titol;
}

void ContenutoMultimediale::setDurata(unsigned short int dur) {
    durata = dur;
}

void ContenutoMultimediale::setGenere(QString gen) {
    genere = gen;
}

void ContenutoMultimediale::setAutore(QString aut) {
    autore = aut;
}

void ContenutoMultimediale::setDataUscita(QString data) {
    dataUscita = data;
}

// METODI GET

QString ContenutoMultimediale::getTitolo() const {
    return titolo;
}

unsigned short int ContenutoMultimediale::getDurata() const {
    return durata;
}

QString ContenutoMultimediale::getGenere() const {
    return genere;
}

unsigned short int ContenutoMultimediale::getValutazione() const {
    return valutazione;
}

QString ContenutoMultimediale::getAutore() const {
    return autore;
}

QString ContenutoMultimediale::getDataUscita() const {
    return dataUscita;
}
