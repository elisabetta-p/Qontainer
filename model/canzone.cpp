#include "canzone.h"

canzone::canzone(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned short int qual, string alb, string prod) : audio(titol, dur, gen, dim, val, aut, data, qual), album (alb), produttore(prod) {}
canzone::canzone(string t, string a, unsigned short int d) : audio (t, a, d) {}

void canzone::setAlbum(string a) {
    album = a;
}

void canzone::setProduttore(string p) {
    produttore = p;
}

string canzone::getAlbum() const {
    return album;
}

string canzone::getProduttore() const {
    return produttore;
}

bool canzone::operator==(const canzone & file) const {
    return (audio::operator==(file) && album == file.album && produttore == file.produttore);
}

void canzone::riproduci() const {
    std::cout << "Stai riproducendo la canzone " << getTitolo();
}

void canzone::pausa() const {
    std::cout << "Hai messo la canzone " <<getTitolo() << " in pausa";
}


/*canzone* canzone::create(std::istream istr) const {
    return new canzone(istr);
}*/
