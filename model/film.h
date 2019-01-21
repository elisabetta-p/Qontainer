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
    film(string ="nd", unsigned short int =0, string ="nd", double =0.4, unsigned short int =3, string="nd", unsigned short int=0, unsigned int= 5, string="nd", string ="nessuna");
    film(const film&);
    film& operator=(const film&);
    bool operator==(const film&) const;
    void riproduci() const;
    void pausa() const;

    void setSaga(string);
    string getSaga() const;

    //virtual void serialize(std::ostream) const;
    //virtual film* create(std::istream) const;
    static container<film*> deserializza(const std::ifstream&);

    //friend std::istream& operator>>(std::istream&, film&);

};



#endif // FILM_H
