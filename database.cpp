#include "database.h"
#include <fstream>
#include <iostream>


database::database(string s) : path(s) {}

void database::load() {
    std::ifstream file;
    file.open(path, std::ios::in);

    if (file.is_open())
        std::cout << "true";
     else
        std::cout << path;

}
