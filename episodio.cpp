#include "episodio.h"

episodio::episodio(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data, unsigned int risol, string ser, string can) : video(titol, dur, gen, dim, val, aut, data, risol), serie(ser), canale(can) {}

episodio::episodio(const episodio& e) : video(e), serie(e.serie), canale(e.canale) {};

episodio& episodio::operator=(const episodio& e) {
    if (this != &e)
        *this = e;
    return *this;
}

bool episodio::operator==(const episodio& file) const {
    return (video::operator==(file) && serie == file.serie && canale == file.canale);
}

void episodio::riproduci() const {
    if (serie != "nd") {
        cout << "Stai riproducendo l'episodio: " << getTitolo()  << " della serie " << getSerie()<< endl;
    }
    else {
        cout << "Stai riproducendo l'episodio: " << getTitolo()  << endl;
    }
}

void episodio::pausa() const {
    cout << "Hai messo in pausa l'episodio!" << endl;
}

void episodio::setSerie(string s) {
    serie = s;
}

void episodio::setCanale(string c) {
    canale = c;
}

string episodio::getSerie() const {
    return serie;
}

string episodio::getCanale() const {
    return canale;
}


