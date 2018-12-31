#include <QGuiApplication>
#include <QWidget>
#include "database.h"

int main(int argc, char *argv[])
{
   /*QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QGuiApplication app(argc, argv);


   return app.exec();*/

    database d = database("/Users/elisabetta/Desktop/ProgettoP2/inserimento_dati.txt");
    d.load();
}
