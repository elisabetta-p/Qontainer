#ifndef VIDEO_H
#define VIDEO_H

#include "contenutomultimediale.h"

class video: public ContenutoMultimediale {
private:
    unsigned int risoluzione;
public:
    video(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned int = 0);
    video (string, string, unsigned short int);
    virtual bool operator==(const video&) const;
    virtual ~video() = default;
    

    //metodi set e get
    void setRisoluzione(unsigned int);
    unsigned int getRisoluzione() const;

    string serializza(char) const;

    virtual string qualita() const;

};

#endif // VIDEO_H
