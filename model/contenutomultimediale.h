#ifndef CONTENUTOMULTIMEDIALE_H
#define CONTENUTOMULTIMEDIALE_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using std::vector;
using std::string;
using std::cout;
using std::endl;

class ContenutoMultimediale {
private:
    string titolo;
    unsigned short int durata; //in minuti
    string genere;
    double dimensione; //in
    unsigned short int valutazione;
    string autore;
    unsigned short int dataUscita;
public:
    ContenutoMultimediale(string = "nd", unsigned short int = 0, string = "nd", double = 0.0, unsigned short int = 0, string = "nd", unsigned short int = 0);
    ContenutoMultimediale(string, string, unsigned short int);
    virtual ~ContenutoMultimediale() = default;

    virtual bool operator==(const ContenutoMultimediale&) const;

    //METODI SET E GET
    void setTitolo(string);
    string getTitolo() const;
    void setDurata(unsigned short int);
    unsigned short int getDurata() const;
    void setGenere(string);
    string getGenere() const;
    void setValutazione(unsigned short int);
    unsigned short int getValutazione() const;
    void setAutore(string);
    string getAutore() const;
    void setDataUscita(unsigned short int);
    unsigned short int getDataUscita() const;
    void setDimensione(double);
    double getDimensione() const;

    virtual string qualita() const =0;

    //serializzazione/deserializzazione
    virtual string serializza(char) const; //questa scrive su file
    ContenutoMultimediale* create(std::istream) const;
};

#endif // CONTENUTOMULTIMEDIALE_H
