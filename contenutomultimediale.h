#ifndef CONTENUTOMULTIMEDIALE_H
#define CONTENUTOMULTIMEDIALE_H
#include <string>
#include <iostream>
#include <fstream>
#include <string>

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
    string dataUscita;
public:
    ContenutoMultimediale(string ="0", unsigned short int =0, string ="0", double =0.0, unsigned short int=0, string ="0", string="0");
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
    void setDataUscita(string);
    string getDataUscita() const;

    //serializzazione/deserializzazione
    virtual void serialize(std::ostream&) const =0; //questa scrive su file
    virtual ContenutoMultimediale* create(std::istream) const =0; //questa crea l'oggetto
    static ContenutoMultimediale* unserialize (std::istream& istr); //questa legge dal file?
};

#endif // CONTENUTOMULTIMEDIALE_H
