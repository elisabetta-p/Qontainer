#include <QGuiApplication>
#include <QApplication>
#include <QWidget>
#include "database.h"
#include "film.h"
#include "mainwindow.h"

#include <string>

int main(int argc, char *argv[])
{

   //QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QApplication app(argc, argv);
   MainWindow window;
   window.show();


   return app.exec();

    //database d = database("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
    //d.load();
    //std::string ciao = "44";
    //unsigned short int x = static_cast<unsigned short int>(std::stoul(ciao));
    //film::deserializza("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");


}
