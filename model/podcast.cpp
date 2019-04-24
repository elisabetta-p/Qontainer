#include "podcast.h"

podcast::podcast(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned short int qual, string rac, string osp) : audio(titol, dur, gen, dim, val, aut, data, qual), raccolta(rac), ospite(osp) {}

podcast::podcast(string t, string a, unsigned short int d) : audio (t, a, d) {}

string podcast::getRaccolta() const{
    return raccolta;
}

string podcast::getOspite() const{
    return ospite;
}

void podcast::setRaccolta(string r) {
    raccolta = r;
}

void podcast::setOspite(string o) {
    ospite = o;
}

void podcast::riproduci() const {
    std::cout << "Stai riproducendo l'episodio " << getTitolo() << " del podcast " <<getRaccolta();
}

void podcast::pausa() const {
    std::cout << "Hai messo il podcast " <<getTitolo() << " della raccolta" << getRaccolta() << "in pausa";
}

podcast* podcast::deserializza(const vector<string> & values) {
    return new podcast(values[0],
                    std::stoul(values[1]),
                    values[2],
                    std::stod(values[3]),
                    std::stoul(values[4]),
                    values[5],
                    std::stoul(values[6]),
                    std::stoul(values[7]),
                    values[8],
                    values[9]
                    );
}
