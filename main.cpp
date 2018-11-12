#include <QGuiApplication>
<<<<<<< HEAD
=======
#include <QQmlApplicationEngine>
>>>>>>> fe6294d336eaaf5cc1efbc4d90fb170585e45495
#include <QWidget>

int main(int argc, char *argv[])
{
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QGuiApplication app(argc, argv):

   return app.exec();
}
