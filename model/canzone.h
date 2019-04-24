#ifndef CANZONE_H
#define CANZONE_H
#include "audio.h"

class canzone: public audio {
private:
    string album, produttore;
public:
    canzone(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned short int, string = "nd", string = "nd");
    canzone(string, string, unsigned short int);
    bool operator==(const canzone&) const;
    ~canzone() = default;
    canzone (const canzone&);
    canzone& operator=(const canzone&);

    virtual void riproduci() const;
    virtual void pausa() const;

    void setAlbum(string);
    string getAlbum() const;
    void setProduttore(string);
    string getProduttore() const;

    /*void serialize(std::ostream&) const;
    canzone* create(std::istream) const;
    canzone* unserialize(std::istream) const; */
    string serializza(char) const;
    static canzone* deserializza (const vector<string>&);
};

#endif // CANZONE_H
