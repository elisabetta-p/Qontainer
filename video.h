#ifndef VIDEO_H
#define VIDEO_H

#include "contenutomultimediale.h"

class video: public ContenutoMultimediale {
private:
    unsigned int risoluzione;
public:
    video(QString, unsigned short int, QString, double, unsigned short int, QString, QString, unsigned int =0);
    bool operator==(const video&) const;
    virtual ~video() = default;
    //metodi set e get
    void setRisoluzione(unsigned int);
    unsigned int getRisoluzione() const;
};

#endif // VIDEO_H
