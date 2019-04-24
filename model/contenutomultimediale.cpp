#include "contenutomultimediale.h"


ContenutoMultimediale::ContenutoMultimediale(string titolo, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data) : titolo(titolo), durata(dur), genere(gen), dimensione(dim), valutazione(val), autore(aut), dataUscita(data) {}
/*ContenutoMultimediale::~ContenutoMultimediale() {}*/

ContenutoMultimediale::ContenutoMultimediale(string t, string a, unsigned short int d) : titolo(t), autore(a), dataUscita(d) {}

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

void ContenutoMultimediale::setDataUscita(unsigned short int data) {
    dataUscita = data;
}

void ContenutoMultimediale::setDimensione(double d) {
    dimensione = d;
}

// METODI GET

double ContenutoMultimediale::getDimensione() const {
    return dimensione;
}

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

unsigned short int ContenutoMultimediale::getDataUscita() const {
    return dataUscita;
}


//serializzazione
string ContenutoMultimediale::serializza(char delimiter) const {

    string strDimensione = std::to_string(dimensione);
    std::replace(strDimensione.begin(), strDimensione.end(), ',', '.');

    return titolo + delimiter + std::to_string(durata) + delimiter + genere + delimiter +
           strDimensione + delimiter + std::to_string(valutazione) + delimiter +
           autore + delimiter + std::to_string(dataUscita);
}
