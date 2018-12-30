#ifndef PODCAST_H
#define PODCAST_H
#include "audio.h"

class podcast: public audio{
private:
    string raccolta, ospite;
public:
    podcast(string, unsigned short int, string, double, unsigned short int, string, string, unsigned short int, string, string);
    ~podcast() = default;
    podcast(const podcast&);
    bool operator==(const podcast&) const;
    podcast& operator=(const podcast&);

    void riproduci() const;
    void pausa() const;

    void setRaccolta();
    string getRaccolta() const;
    void setOspite();
    string getOspite() const;
};

#endif // PODCAST_H
