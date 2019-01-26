#ifndef CONTENUTOMULTIMEDIALE_H
#define CONTENUTOMULTIMEDIALE_H
#include <string>
#include <iostream>
#include <fstream>



using std::string;
using std::cout;
using std::endl;

class ContenutoMultimediale {
private:
    string titolo;
    unsigned short int durata;
    string genere;
    double dimensione;
    unsigned short int valutazione;
    string autore;
    unsigned short int dataUscita;
public:
    ContenutoMultimediale(string = "nd", unsigned short int =0, string ="nd", double =0.0, unsigned short int=0, string ="nd", unsigned short int=0);
    virtual ~ContenutoMultimediale() = default;
    virtual void riproduci() const =0;
    virtual void pausa() const =0;
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

    //serializzazione/deserializzazione
     void serialize(std::ostream&) const; //questa scrive su file
     ContenutoMultimediale* create(std::istream) const; //questa crea l'oggetto
    //static container<ContenutoMultimediale*> deserializza(std::istream&); //questa legge dal file?
};

#endif // CONTENUTOMULTIMEDIALE_H
