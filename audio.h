#ifndef AUDIO_H
#define AUDIO_H
#include "contenutomultimediale.h"

class audio: public ContenutoMultimediale {
private:
    unsigned short int qualita;
public:
    audio (QString, unsigned short int, QString, double, unsigned short int, QString, QString, unsigned short int =0);
    bool operator==(const audio&) const;
    virtual ~audio() = default;
};

#endif // AUDIO_H
