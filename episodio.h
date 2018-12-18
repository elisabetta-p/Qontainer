#ifndef EPISODIO_H
#define EPISODIO_H
#include "video.h"

class episodio: public video {
private:
    QString serie;
    QString canale;
public:
    ~episodio() = default;
    episodio(QString, unsigned short int, QString, double, unsigned short int, QString, QString, unsigned int, QString ="nd", QString ="nd");
    episodio(const episodio&);
    episodio& operator=(const episodio&);
    bool operator==(const episodio&) const;
    void riproduci() const;
    void pausa() const;

    void setSerie(QString);
    QString getSerie() const;
    void setCanale(QString);
    QString getCanale() const;
};

#endif // EPISODIO_H
