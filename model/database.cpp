#include "database.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "film.h"

database::database(string s) : path(s) {}

/*
void database::load() {
    std::ifstream file;
    file.open(path, std::ios::in);
    if (file.is_open()) {
        film::deserializza(file);
        std::cout << "true";
        file.close();
    }
     else {
        std::cout << "Error " << path;
    }

}
*/

void database::load(container<ContenutoMultimediale*>& contenitore) {
    std::ifstream file;
    file.open(path, std::ios::in);
    if (file.is_open()) {
        // Contiene l'ultima riga prelevata dal file
        string currentLine;

        // Ignora la prima riga d'intestazione
        std::getline(file, currentLine, ';');

        while(std::getline(file, currentLine, ';')) {
            std::stringstream buffer(currentLine);

            // Contiene tutte le stringhe separate da virgola presenti in currentLine
            std::vector<string> values;
            string currentValue;

            while(std::getline(buffer, currentValue, ','))
                values.push_back(currentValue);


            /*
             * Determino il tipo di ContenutoMultimediale da creare analizzando values[0]
             *  C -> Canzone
             *  E -> Episodio
             *  F -> Film
             *  P -> Podcast
             *
             */

            // Elimino il carattere \n dalla prima stringa della riga
            string typeContenutoMultimediale = values[0].substr(1, string::npos);
            values.erase(values.begin());


            if(typeContenutoMultimediale == "C")
                //contenitore.insert(film::deserializza(values));

            if(typeContenutoMultimediale == "E")
                //contenitore.insert(film::deserializza(values));

            if(typeContenutoMultimediale == "F")
                contenitore.insert(film::deserializza(values));

            if(typeContenutoMultimediale == "P")
                //contenitore.insert(film::deserializza(values));

        }

    }
}

void database::save(vector<string> content) {
    std::ofstream file;
    file.open(path, std::ios_base::app);

    for(auto it = content.begin(); it < content.end(); ++it) {
        file << *it << std::endl;
    }
}


