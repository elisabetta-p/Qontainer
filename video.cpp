#include "video.h"


video::video(QString titol, unsigned short int dur, QString gen, double dim, unsigned short int val, QString aut, QString data, unsigned int risol) : ContenutoMultimediale (titol, dur, gen, dim, val, aut, data), risoluzione(risol) {}

bool video::operator==(const video& file) const {
    return (ContenutoMultimediale::operator==(file) && risoluzione == file.risoluzione);
}

void video::setRisoluzione(unsigned int ris) {
    risoluzione = ris;
}

unsigned int video::getRisoluzione() const {
    return risoluzione;
}
