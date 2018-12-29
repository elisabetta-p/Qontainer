#include "film.h"
#include <string>
#include<QString>
using std::string;

void film::riproduci() const {
    cout << "Stai riproducendo il film: " << getTitolo().toLocal8Bit().constData() << endl;
}

void film::pausa() const {
    cout <<"Hai messo in pausa il film: " << getTitolo().toLocal8Bit().constData()<< endl;
}


bool film::operator==(const film& file) const {
    return (video::operator==(file) && saga == file.saga);
}

film::film(QString titol, unsigned short int dur, QString gen, double dim, unsigned short int val, QString aut, QString data, unsigned int risol, QString sag) : video(titol, dur, gen, dim, val, aut, data, risol), saga(sag) {}

film::film(const film& file) : video(file), saga(file.saga) {}

film& film::operator=(const film& file) {
    if (this != &file)
        *this = file;
    return *this;
}

void film::setSaga(QString s) {
    saga = s;
}

QString film::getSaga() const {
    return saga;
}

void film::serialize(std::ostream stream) const {

}
