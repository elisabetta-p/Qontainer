//#include <QGuiApplication>
#include <QWidget>
#include <QApplication>
#include <QFile>
#include "model/database.h"
#include "model/film.h"
#include "view/qontainer.h"
#include "model/container.h"
#include "model/canzone.h"

#include <string>

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
    qontainer window;

	QFile css("style.css");
	css.open(QFile::ReadOnly);
    app.setStyleSheet(css.readAll());

    window.show();
    return app.exec();
}
