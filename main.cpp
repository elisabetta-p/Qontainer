#include <QGuiApplication>
#include <QWidget>
#include "database.h"
#include "film.h"

#include <string>

int main(int argc, char *argv[])
{
   /*QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QGuiApplication app(argc, argv);


   return app.exec();*/

    database d = database("/home/studente/Desktop/ProgettoP2/inserimento_dati.txt");
    d.load();
    //std::string ciao = "44";
    //unsigned short int x = static_cast<unsigned short int>(std::stoul(ciao));
    //film::deserializza("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
}
