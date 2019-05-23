#include "audio.h"

audio::audio(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned short int qual) : ContenutoMultimediale (titol, dur, gen, dim, val, aut, data), bitrate(qual) {}
audio::audio(string t, string a, unsigned short int d) : ContenutoMultimediale (t, a, d) {}

void audio::setBitrate(unsigned short q) {
    bitrate = q;
}

unsigned short int audio::getBitrate() const {
    return bitrate;
}

bool audio::operator==(const audio& file) const {
    return (ContenutoMultimediale::operator==(file) && bitrate == file.bitrate);
}

string audio::serializza(char delimiter) const {
    return ContenutoMultimediale::serializza(delimiter) + delimiter + std::to_string(bitrate);
}

string audio::qualita() const { //la dimensione dei file audio e' espressa in MB, e la loro durata in minuti
    double ratio = getDimensione() / getDurata() * getBitrate();
    if (ratio >= 320) { //un MB per minuto di audio
        return "Alta";
    }
    if (ratio >= 160) {
        return "Media";
    }    
    return "Bassa";
}