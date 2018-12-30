#ifndef VIDEO_H
#define VIDEO_H

#include "contenutomultimediale.h"

class video: public ContenutoMultimediale {
private:
    unsigned int risoluzione;
public:
    video(string, unsigned short int, string, double, unsigned short int, string, string, unsigned int =0);
    virtual bool operator==(const video&) const;
    virtual ~video() = default;

    //metodi set e get
    void setRisoluzione(unsigned int);
    unsigned int getRisoluzione() const;

    //serializzazione
    virtual void serialize(std::ostream) const =0;
    virtual video* create(std::istream) const =0;
};

#endif // VIDEO_H
