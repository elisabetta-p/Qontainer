#include "audio.h"

audio::audio(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned short int qual) : ContenutoMultimediale (titol, dur, gen, dim, val, aut, data), qualita(qual) {}
audio::audio(string t, string a, unsigned short int d) : ContenutoMultimediale (t, a, d) {}

void audio::setQualita(unsigned short q) {
    qualita = q;
}

unsigned short int audio::getQualita() const {
    return qualita;
}

bool audio::operator==(const audio& file) const {
    return (ContenutoMultimediale::operator==(file) && qualita == file.qualita);
}

string audio::serializza(char delimiter) const {
    return ContenutoMultimediale::serializza(delimiter) + delimiter + std::to_string(qualita);
}