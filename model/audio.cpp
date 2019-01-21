#include "audio.h"

audio::audio(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned short int qual) : ContenutoMultimediale (titol, dur, gen, dim, val, aut, data), qualita(qual) {}

bool audio::operator==(const audio& file) const {
    return (ContenutoMultimediale::operator==(file) && qualita == file.qualita);
}

