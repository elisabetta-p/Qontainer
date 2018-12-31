#include "podcast.h"

podcast::podcast(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, string data, unsigned short int qual, string rac, string osp) : audio(titol, dur, gen, dim, val, aut, data, qual), raccolta(rac), ospite(osp) {}

string podcast::getRaccolta() const{
    return raccolta;
}

string podcast::getOspite() const{
    return ospite;
}

void podcast::riproduci() const {
    std::cout << "Stai riproducendo l'episodio " << getTitolo() << " del podcast " <<getRaccolta();
}

void podcast::pausa() const {
    std::cout << "Hai messo il podcast " <<getTitolo() << " della raccolta" << getRaccolta() << "in pausa";
}
