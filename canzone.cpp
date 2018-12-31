#include "canzone.h"

canzone::canzone(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data, unsigned short int qual, string alb, string prod) : audio(titol, dur, gen, dim, val, aut, data, qual), album (alb), produttore(prod) {}

bool canzone::operator==(const canzone & file) const {
    return (audio::operator==(file) && album == file.album && produttore == file.produttore);
}

void canzone::serialize(std::ostream& os) const {

}

canzone* canzone::create(std::istream) const {

}

canzone* canzone::create(std::istream istr) const {
    return new canzone(istr);
}