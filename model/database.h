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
public:
    database(string ="0");
    void load(container<ContenutoMultimediale*>&);
    void save(vector<string>);
};

#endif // DATABASE_H
