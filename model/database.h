#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include "container.h"
#include "contenutomultimediale.h"

using std::string;
using std::vector;

class database {
private:
    string path;
    char delimiter;
public:
    database(string = "0", char = ',');
    void load(container<ContenutoMultimediale*>&);
    void save(container<ContenutoMultimediale*>&);
};

#endif // DATABASE_H
