#include "film.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


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

film::film(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned int risol, string reg, string sag) : video(titol, dur, gen, dim, val, aut, data, risol), regista (reg), saga(sag) {}

film::film(string t, string a, unsigned short int d) : video(t, a, d) {}

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

void film::setRegista(string r) {
    regista = r;
}

string film::getRegista() const{
    return regista;
}

film* film::deserializza(const vector<string>& values) {

    return new film(values[0],
                    std::stoul(values[1]),
                    values[2],
                    std::stod(values[3]),
                    std::stoul(values[4]),
                    values[5],
                    std::stoul(values[6]),
                    std::stoul(values[7]),
                    values[8],
                    values[9]
                    );
}

