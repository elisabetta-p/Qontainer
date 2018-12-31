#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <iostream>
using std::cout;
using std::endl;

class film: public video {
private:
    string regista, saga;
public:
    ~film() = default;
    film(string, unsigned short int, string, double, unsigned short int, string, string, unsigned int, string="nd", string ="nessuna");
    film(const film&);
    film& operator=(const film&);
    bool operator==(const film&) const;
    void riproduci() const;
    void pausa() const;

    void setSaga(string);
    string getSaga() const;

    virtual void serialize(std::ostream) const;
    virtual film* create(std::istream) const;
};

#endif // FILM_H
