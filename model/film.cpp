#include "film.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using std::ifstream;
using std::string;

void film::riproduci() const {
    cout << "Stai riproducendo il film: " << getTitolo() << endl;
}

void film::pausa() const {
    cout <<"Hai messo in pausa il film: " << getTitolo() << endl;
}


bool film::operator==(const film& file) const {
    return (video::operator==(file) && saga == file.saga);
}

film::film(string titol, unsigned short int dur, string gen, double dim, unsigned short int val, string aut, unsigned short int data, unsigned int risol, string reg, string sag) : video(titol, dur, gen, dim, val, aut, data, risol), regista (reg), saga(sag) {}

film::film(const film& file) : video(file), saga(file.saga) {}

film& film::operator=(const film& file) {
    if (this != &file)
        *this = file;
    return *this;
}

void film::setSaga(string s) {
    saga = s;
}

string film::getSaga() const {
    return saga;
}
/*
container<film*> film::deserializza(const std::ifstream& file) {
    container<film*> contenitore;
    //std::ifstream file;
    //file.open(path, std::ios::in);

    if (file.is_open()) {
        while (!file.eof()){
            string riga="";
            //getline(file, riga, ';');

            std::stringstream buffer;
            buffer << file.rdbuf();
            riga = buffer.str();

            std::vector<string> risultato;
            int firstChar =0;
            //riga = "La compagnia dell'anello,228,Fantasy,2500,10,JRR Tolkien,2001,1080,Peter Jackson,Il Signore degli Anelli,";
            for (int pos=0; pos < riga.size() ; ++pos) {
                if (riga[pos] == ',' || pos == riga.size()-1) {
                    risultato.push_back(riga.substr(firstChar, pos-firstChar));
                    firstChar = pos+1;

                }

            }

            int p = 0;
            for ( auto it = risultato.begin() ; it != risultato.end(); ++it) {
                cout << p << " " << *it << std::endl; ++p;
            }

            //try{
            contenitore.insert(new film (risultato[0],
                                        static_cast<unsigned short int> (std::stoul(risultato[1])),
                                        risultato[2],
                                        std::stod(risultato[3]),
                                        static_cast<unsigned short int> (std::stoul(risultato[4])),
                                        risultato[5],
                                        static_cast<unsigned short int> (std::stoul(risultato[6])),
                                        static_cast<unsigned int> (std::stoul(risultato[7])),
                                        risultato[8],
                                        risultato[9]));
            //}
            //catch(std::invalid_argument e){ std::cout << e.what();}

        }

    }
    return contenitore;
}
*/
