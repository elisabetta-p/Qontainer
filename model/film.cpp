#include "film.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using std::ifstream;
using std::string;

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


string film::serializza(char delimiter) const {
    return "F|" + video::serializza(delimiter) + delimiter + regista + delimiter + saga + ";";
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
