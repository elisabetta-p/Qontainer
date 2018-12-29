#ifndef CONTENUTOMULTIMEDIALE_H
#define CONTENUTOMULTIMEDIALE_H
#include <QString>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

class ContenutoMultimediale {
private:
    QString titolo;
    unsigned short int durata;
    QString genere;
    double dimensione;
    unsigned short int valutazione;
    QString autore;
    QString dataUscita;
public:
    ContenutoMultimediale(QString ="0", unsigned short int =0, QString ="0", double =0.0, unsigned short int=0, QString ="0", QString="0");
    virtual ~ContenutoMultimediale() = default;
    //il costruttore di copia ridefinito non serve
    virtual void riproduci() const =0;
    virtual void pausa() const =0;
    virtual bool operator==(const ContenutoMultimediale&) const;
    //virtual ContenutoMultimediale* clone() const =0;

    //METODI SET E GET
    void setTitolo(QString);
    QString getTitolo() const;
    void setDurata(unsigned short int);
    unsigned short int getDurata() const;
    void setGenere(QString);
    QString getGenere() const;
    void setValutazione(unsigned short int);
    unsigned short int getValutazione() const;
    void setAutore(QString);
    QString getAutore() const;
    void setDataUscita(QString);
    QString getDataUscita() const;

    //serializzazione/deserializzazione
    virtual void serialize(std::ostream) const =0;
    virtual ContenutoMultimediale* create(std::istream) const =0;
};

#endif // CONTENUTOMULTIMEDIALE_H
