#include "database.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "film.h"
#include "episodio.h"
#include "podcast.h"
#include "canzone.h"

database::database(string s, char d) : path(s), delimiter(d) {}

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

            while(std::getline(buffer, currentValue, delimiter))
                values.push_back(currentValue);

            /*
             * Determino il tipo di ContenutoMultimediale da creare analizzando values[0]
             *  C -> Canzone
             *  E -> Episodio
             *  F -> Film
             *  P -> Podcast
             */

            // Elimino il carattere \n dalla prima stringa della riga
            string typeContenutoMultimediale = values[0].substr(1, string::npos);
            values.erase(values.begin());

            // Per ogni tipologia di Contenuto multimediale si crea un nuovo oggetto
            // al quale viene passato il vector contenente i valori prelevati dal db

            if(typeContenutoMultimediale == "C")
                contenitore.insert(canzone::deserializza(values));

            if(typeContenutoMultimediale == "E")
                contenitore.insert(episodio::deserializza(values));

            if(typeContenutoMultimediale == "F") 
                contenitore.insert(film::deserializza(values));

            if(typeContenutoMultimediale == "P")
                contenitore.insert(podcast::deserializza(values));
        }
    }
}

void database::save(container<ContenutoMultimediale*>& contenitore) {
    std::ofstream file;
    file.open(path, std::ofstream::trunc);

    if (file.is_open()) {
        file << "# Qontainer DB;\n";
        for(auto it = contenitore.begin(); it != contenitore.end(); ++it)
            file << (*it)->serializza(delimiter) << std::endl;
    }
}


