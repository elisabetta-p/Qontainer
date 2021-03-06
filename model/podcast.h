#ifndef PODCAST_H
#define PODCAST_H
#include "audio.h"

class podcast: public audio{
private:
    string raccolta, ospite;
public:
    podcast(string, unsigned short int, string, double, unsigned short int, string, unsigned short int, unsigned short int, string = "nd", string = "nd");
    podcast(string, string, unsigned short int);
    ~podcast() = default;
    podcast(const podcast&);
    bool operator==(const podcast&) const;
    podcast& operator=(const podcast&);

    void setRaccolta(string);
    string getRaccolta() const;
    void setOspite(string);
    string getOspite() const;
    string serializza(char) const;
    static podcast* deserializza(const vector<string>&);
};

#endif // PODCAST_H
