#ifndef EPISODIO_H
#define EPISODIO_H
#include "video.h"

class episodio: public video {
private:
    string serie;
    string canale;
public:
    ~episodio() = default;
    episodio(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned int, string ="nd", string ="nd");
    episodio(const episodio&);
    episodio& operator=(const episodio&);
    bool operator==(const episodio&) const;
    void riproduci() const;
    void pausa() const;

    void setSerie(string);
    string getSerie() const;
    void setCanale(string);
    string getCanale() const;
};

#endif // EPISODIO_H
