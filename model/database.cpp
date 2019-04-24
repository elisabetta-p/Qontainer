#include "database.h"
#include <fstream>
#include <iostream>
#include "film.h"

database::database(string s) : path(s) {}

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

void database::save(vector<string> content) {
    std::ofstream file;
    file.open(path, std::ios_base::app);

    for(auto it = content.begin(); it < content.end(); ++it) {
        file << *it << std::endl;
    }
}


