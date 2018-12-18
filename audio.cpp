#include "audio.h"

audio::audio(QString titol, unsigned short int dur, QString gen, double dim, unsigned short int val, QString aut, QString data, unsigned short int qual) : ContenutoMultimediale (titol, dur, gen, dim, val, aut, data), qualita(qual) {}

bool audio::operator==(const audio& file) const {
    return (ContenutoMultimediale::operator==(file) && qualita == file.qualita);
}
