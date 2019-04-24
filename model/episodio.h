#ifndef EPISODIO_H
#define EPISODIO_H
#include "video.h"

class episodio: public video {
private:
    string serie, canale;
public:
    ~episodio() = default;
    episodio(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned int, string ="nd", string ="nd");
    episodio (string, string, unsigned short int);
    episodio(const episodio&);
    episodio& operator=(const episodio&);
    bool operator==(const episodio&) const;
    void riproduci() const;
    void pausa() const;

    void setSerie(string);
    string getSerie() const;
    void setCanale(string);
    string getCanale() const;

    static episodio* deserializza(const vector<string>&);
};

#endif // EPISODIO_H
