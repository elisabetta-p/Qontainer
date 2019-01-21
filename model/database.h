#ifndef DATABASE_H
#define DATABASE_H
#include <string>
using std::string;

class database {
private:
    string path;
public:
    database(string ="0");
    void load();
    void save();
};

#endif // DATABASE_H
