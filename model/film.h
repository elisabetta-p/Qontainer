#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <istream>
#include "container.h"

using std::cout;
using std::endl;

class film: public video {
private:
    string regista, saga;
public:
    ~film() = default;
    film(string ="nd", unsigned short int =0, string ="nd", double =0.4, unsigned short int =3, string="nd", unsigned short int=0, unsigned int= 5, string="nd", string = "nd");
    film(string = "nd", string = "nd", unsigned short int = 0);
    film(const film&);
    film& operator=(const film&);
    bool operator==(const film&) const;
    void riproduci() const;
    void pausa() const;

    void setSaga(string);
    string getSaga() const;
    void setRegista(string);
    string getRegista() const;

    virtual string serializza(char) const;
    static film* deserializza(const vector<string>&);

    //friend std::istream& operator>>(std::istream&, film&);

};



#endif // FILM_H
