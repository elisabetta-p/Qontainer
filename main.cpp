//#include <QGuiApplication>
#include <QWidget>
#include <QApplication>
#include "model/database.h"
#include "model/film.h"
#include "view/qontainer.h"
#include "model/container.h"
#include "model/canzone.h"

#include <string>

int main(int argc, char *argv[])
{

    /*
    QApplication app(argc, argv);
    qontainer window;
    window.show();
    return app.exec();
    */



    //film provaFilm("iron man", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");
    //film provaFilm2("iron man", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");

    container<ContenutoMultimediale*> contenitore;
    ContenutoMultimediale* puntatoreFilm = new film("iron man", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");
    ContenutoMultimediale* puntatoreCanzone = new canzone("nd", 0, "nd", 0.0, 0, "nd", 0, 0, "nd", "nd");
    cout << puntatoreFilm->getAutore() << " " <<puntatoreCanzone->getGenere() << " ";
    contenitore.insert(puntatoreFilm);

    /*
    container<film> cfilm;
    film provaFilm("iron man", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");
    std::cout<< provaFilm.getSaga();
    auto it = cfilm.getFirst();
    */

    /*
    database d = database("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
    d.load();
    std::string ciao = "44";
    unsigned short int x = static_cast<unsigned short int>(std::stoul(ciao));
    film::deserializza("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
    */

}
