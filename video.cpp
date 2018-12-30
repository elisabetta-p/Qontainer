#include "video.h"


video::video(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data, unsigned int risol) : ContenutoMultimediale (titol, dur, gen, dim, val, aut, data), risoluzione(risol) {}

bool video::operator==(const video& file) const {
    return (ContenutoMultimediale::operator==(file) && risoluzione == file.risoluzione);
}

void video::setRisoluzione(unsigned int ris) {
    risoluzione = ris;
}

unsigned int video::getRisoluzione() const {
    return risoluzione;
}
