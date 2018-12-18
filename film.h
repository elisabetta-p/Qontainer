#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <iostream>
using std::cout;
using std::endl;

class film: public video {
private:
    QString saga;
public:
    ~film() = default;
    film(QString, unsigned short int, QString, double, unsigned short int, QString, QString, unsigned int, QString ="nessuna");
    film(const film&);
    film& operator=(const film&);
    bool operator==(const film&) const;
    void riproduci() const;
    void pausa() const;

    void setSaga(QString);
    QString getSaga() const;
};

#endif // FILM_H
