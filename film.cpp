#include "film.h"
#include <string>
#include <fstream>
using std::ifstream;
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

film::film(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data, unsigned int risol, string reg, string sag) : video(titol, dur, gen, dim, val, aut, data, risol), regista (reg), saga(sag) {}

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

static container<film*>* deserializza(std::string path) {
    container<film*>* contenitore;
    std::ifstream file;
    file.open(path, std::ios::in);

    if (file.is_open()) {
        while (!file.eof()){
            string riga="";
            getline(file, riga, ';');
            cout << riga;
        }
    }
    return contenitore;
}
