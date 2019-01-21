#ifndef AUDIO_H
#define AUDIO_H
#include "contenutomultimediale.h"

class audio: public ContenutoMultimediale {
private:
    unsigned short int qualita;
public:
    audio (string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned short int =0);
    bool operator==(const audio&) const;
    virtual ~audio() = default;
    audio* create(std::istream) const;
};

#endif // AUDIO_H