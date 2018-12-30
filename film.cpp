#include "film.h"
#include <string>
#include<string>
using std::string;

void film::riproduci() const {
    cout << "Stai riproducendo il film: " << getTitolo() << endl;
}

void film::pausa() const {
    cout <<"Hai messo in pausa il film: " << getTitolo() << endl;
}


bool film::operator==(const film& file) const {
    return (video::operator==(file) && saga == file.saga);
}

film::film(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data, unsigned int risol, string sag) : video(titol, dur, gen, dim, val, aut, data, risol), saga(sag) {}

film::film(const film& file) : video(file), saga(file.saga) {}

film& film::operator=(const film& file) {
    if (this != &file)
        *this = file;
    return *this;
}

void film::setSaga(string s) {
    saga = s;
}

string film::getSaga() const {
    return saga;
}

void film::serialize(std::ostream stream) const {

}
