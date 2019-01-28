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

    container<ContenutoMultimediale*> contenitore;
    ContenutoMultimediale* puntatoreFilm = new film("iron man", 126, "azione",1500.0,5,"Marvel", 2012,1080,"Joss Whedon","MCU");
    ContenutoMultimediale* puntatoreCanzone = new canzone("nd", 0, "nd", 0.0, 0, "nd", 0, 0, "nd", "nd");
    film* pf = new film("signore anelli", 14, "fanta",1900.0,5,"CasaMia", 2019,480,"Fedelisa","ABC");
    cout << puntatoreFilm->getAutore() << " " <<puntatoreCanzone->getGenere() << " " << std::endl;
    contenitore.insert(puntatoreFilm);
    contenitore.insert(puntatoreCanzone);
    contenitore.insert(pf);

    container<ContenutoMultimediale*>::iterator it = contenitore.begin();

    for(; it != contenitore.end(); it++) {
        std::cout << "x " << (contenitore[it])->getAutore() << std::endl;
    }

    std::cout << contenitore.size() << std::endl;
    contenitore.remove(puntatoreFilm);
        std::cout << contenitore.size() << std::endl;

    /*for(; it != contenitore.end(); it++) {
        std::cout << "y " << (contenitore[it])->getAutore() << std::endl;
    }

    std::cout << contenitore.size() << std::endl;
    /*
    database d = database("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
    d.load();
    std::string ciao = "44";
    unsigned short int x = static_cast<unsigned short int>(std::stoul(ciao));
    film::deserializza("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
    */

}
