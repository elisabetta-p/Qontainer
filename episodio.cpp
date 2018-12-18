#include "episodio.h"

episodio::episodio(QString titol, unsigned short int dur, QString gen, double dim, unsigned short int val, QString aut, QString data, unsigned int risol, QString ser, QString can) : video(titol, dur, gen, dim, val, aut, data, risol), serie(ser), canale(can) {}

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
        cout << "Stai riproducendo l'episodio: " << getTitolo().toLocal8Bit().constData()  << " della serie " << getSerie().toLocal8Bit().constData()  << endl;
    }
    else {
        cout << "Stai riproducendo l'episodio: " << getTitolo().toLocal8Bit().constData()  << endl;
    }
}

void episodio::pausa() const {
    cout << "Hai messo in pausa l'episodio!" << endl;
}

void episodio::setSerie(QString s) {
    serie = s;
}

void episodio::setCanale(QString c) {
    canale = c;
}

QString episodio::getSerie() const {
    return serie;
}

QString episodio::getCanale() const {
    return canale;
}


