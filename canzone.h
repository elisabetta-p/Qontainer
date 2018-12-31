#ifndef CANZONE_H
#define CANZONE_H
#include "audio.h"

class canzone: public audio {
private:
    string album, produttore;
public:
    canzone(string, unsigned short int, string, double, unsigned short int, string, string, unsigned short int, string, string);
    bool operator==(const canzone&) const;
    ~canzone() = default;
    canzone (const canzone&);
    canzone& operator=(const canzone&);

    virtual void riproduci() const;
    virtual void pausa() const;

    void setAlbum();
    string getAlbum() const;
    void setProduttore();
    string getProduttore() const;

    /*void serialize(std::ostream&) const;
    canzone* create(std::istream) const;
    canzone* unserialize(std::istream) const; */
};

#endif // CANZONE_H
