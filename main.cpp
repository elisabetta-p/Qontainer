#include <QGuiApplication>
#include <QWidget>
#include <boost/archive/tmpdir.hpp>

int main(int argc, char *argv[])
{
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QGuiApplication app(argc, argv);


   return app.exec();
}
