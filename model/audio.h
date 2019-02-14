#ifndef AUDIO_H
#define AUDIO_H
#include "contenutomultimediale.h"

class audio: public ContenutoMultimediale {
private:
    unsigned short int qualita;
public:
    audio (string = "nd", unsigned short int = 0, string = "nd", double = 0.0, unsigned short int = 0, string = "nd", unsigned short int = 0, unsigned short int = 0);
    audio (string = "nd", string = "nd", unsigned short int = 0);
    bool operator==(const audio&) const;
    virtual ~audio() = default;
    audio* create(std::istream) const;
};

#endif // AUDIO_H
